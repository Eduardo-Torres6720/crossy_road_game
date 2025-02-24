#include <allegro5/allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../include/map.h"
#include "../include/car.h"
#include "../include/tree.h"
#include "../include/chicken.h"
#include "../include/log.h"

#define MAP_HEIGHT 12
#define MAP_WIDTH 9
#define DISPLAY_HEIGHT 900

extern ALLEGRO_BITMAP *gram;
extern ALLEGRO_BITMAP *road;
extern ALLEGRO_BITMAP *car;
extern ALLEGRO_BITMAP *tree;
extern ALLEGRO_BITMAP *water;
extern ALLEGRO_BITMAP *scoreboard;
extern ALLEGRO_BITMAP *tronco;

extern int positiony_car;

extern Car cars[MAP_HEIGHT][3];
extern Tree trees[MAP_HEIGHT][2];
extern Chicken chicken_struct;

int bitmapType = 1; // inicia como estrada
int bitmapPrevious; // observa o ultimo valor do bitmapType
int num = 0; // variavel para guardar numeros aleatorios

int cam_y = 0;

Floor map[MAP_HEIGHT];

int dificult_progress(int limit_progress) {
    return ceil(chicken_struct.points/30)<=limit_progress ? ceil(chicken_struct.points/30) : limit_progress;
}

void random_map() {
    int i;

    if (bitmapType == 1 && num == 0) { 
        int progress_gram = dificult_progress(4);
        num = (rand() % 4) + 5-progress_gram;
        bitmapPrevious = bitmapType;
        bitmapType = 2; 
        fprintf(stderr, "%da", num);
    } else if(bitmapType == 2 && num == 0) {
        int progress_road = dificult_progress(6);
        num = (rand() % 4)+1+progress_road;
        int chance = rand() % 4;

        if (chance == 0) { 
            int progress_river = dificult_progress(3);
            num = (rand() % 2) + 1 + progress_river;
            bitmapPrevious = bitmapType;
            bitmapType = 3;
        } else { 
            int progress_road = dificult_progress(6);
            num = (rand() % 4)+1+progress_road;
            bitmapPrevious = bitmapType;
            bitmapType = 1; 
        }
        fprintf(stderr, "%db", num);
    }
    else if (bitmapType == 3 && num == 0) { 
        num = (rand() % 4) + 1 >= 2 ? 2 : 1;
        bitmapPrevious = bitmapType;
        bitmapType = 1; 
    }

    if (bitmapType == 3 && bitmapPrevious == 1) {
        bitmapType = 1;
    }

    for (i = 0; i < MAP_HEIGHT; i++) {
        if (map[i].bitmap_id == 0 && num > 0) {
            map[i].bitmap_id = bitmapPrevious;
            num = num - 1;
        }
    }
}

void draw_map() {
    int bitmap_width = 96;
    int bitmap_height = 96;

    for (int y = 0; y < MAP_HEIGHT; y++) {      
        map[y].positiony = map[y].exist ? map[y].positiony : DISPLAY_HEIGHT - ((y + 1) * bitmap_height); // Posição y do bitmap na tela
        map[y].exist = true;
        for (int x = 0; x < MAP_WIDTH; x++) {
            int bitmap_x = x * bitmap_width;

            if (map[y].bitmap_id == 1) { // Gramado
                al_draw_bitmap(gram, bitmap_x, map[y].positiony, 0);
                if (x == 0 || x == 8) { // Desenha árvores nas bordas do gramado
                    trees[y][x / 8].initial_x = bitmap_x;
                    trees[y][x / 8].final_x = bitmap_x + bitmap_width;
                    trees[y][x / 8].position_y = map[y].positiony;
                    al_draw_bitmap(tree, bitmap_x, map[y].positiony, 0);
                }
            } 
            else if (map[y].bitmap_id == 2) { // Estrada
                al_draw_bitmap(road, bitmap_x, map[y].positiony, 0);
            } 
            else if (map[y].bitmap_id == 3) { // Água
                al_draw_bitmap(water, bitmap_x, map[y].positiony, 0);
            }
        }

        if (map[y].bitmap_id == 3) {
            if (!logs[y].exists) {
                set_log(y);
            }
            al_draw_bitmap(tronco, logs[y].initial_x, map[y].positiony, 0);
            move_log(&logs[y]);

            // Adicionar verificação para a colisão da galinha com o tronco
            if (chicken_struct.positiony == map[y].positiony) {
                if (logs[y].initial_x <= chicken_struct.positionx && chicken_struct.positionx <= logs[y].initial_x + 96) {
                    // A galinha está sobre o tronco, então ela se move com ele
                    chicken_struct.positionx += logs[y].velocity;

                    // Impedir que a galinha ultrapasse a borda
                    if (chicken_struct.positionx < 0) {
                        chicken_struct.positionx = 0;
                    } else if (chicken_struct.positionx > 96 * (MAP_WIDTH - 1)) {
                        chicken_struct.positionx = 96 * (MAP_WIDTH - 1);
                    }
                }
            }
        }

        int random_number_car = (rand() % 3) + 1;
        if (map[y].bitmap_id == 2 && !cars[y][0].exists) {
            for (int i = 0; i < random_number_car; i++) {
                cars[y][i].position_y = map[y].positiony;
                cars[y][i].exists = true;
            }
        }
    }
}


void display_follow_player() {
    if(chicken_struct.positiony < DISPLAY_HEIGHT - 384) {
        chicken_struct.positiony -= chicken_struct.jumpy;
        for(int i = 0; i < MAP_HEIGHT; i++) {
            map[i].positiony -= chicken_struct.jumpy;
            for(int j = 0; j < 3; j++) {
                if(cars[i][j].exists) {
                    cars[i][j].position_y -= chicken_struct.jumpy;
                } 
            }
        }
        printf("%d,", chicken_struct.positiony);
        if (map[0].positiony == 900) {
            for(int i = 1; i < MAP_HEIGHT; i++) {
                    map[i - 1] = map[i];
                    for(int j=0; j<3; j++) {
                        cars[i - 1][j] = cars[i][j];
                    }
                    for(int j=0; j<2; j++) {
                        trees[i-1][j] = trees[i][j];
                    }
        
                // Atualizando troncos, se houver água na linha
                if (map[i - 1].bitmap_id == 3) { // Se for água
                    logs[i - 1] = logs[i]; // Mover troncos para a linha anterior
                }
            }
        
            // Limpar a última linha
            map[11].bitmap_id = 0;
            map[11].exist = false;
            for(int j=0; j<3; j++) {
                cars[11][j].exists = false;
                cars[11][j].defined_values = false;
            }
        }  
    } 
}