#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/car.h"

#define MAP_HEIGHT 12

extern ALLEGRO_BITMAP *car[6];

Car cars[12][3];

void move_car(int i, int j) {
    cars[i][j].initial_x = cars[i][j].direction == 0 ? cars[i][j].initial_x + 2 : cars[i][j].initial_x - 2;
}

void set_car(int i, int j) {
    int random_direction;
    int random_model_car;
    int random_initial_x;
    int random_final_x;
    int random_cpy_x;

    if (j == 0) {
        random_direction = rand() % 2;
        random_initial_x = random_direction == 0 ? -1 * (rand() % 800) - 100 : (rand() % 320) + 900;
        random_final_x = random_direction == 0 ? (rand() % 320) + 900 : -1 * (rand() % 800) - 100;
        random_cpy_x = random_initial_x;
    } else {
        random_direction = cars[i][j-1].direction;
        int random_distance = (rand() % 300) + 200;
        random_initial_x = random_direction == 0 ? cars[i][j-1].initial_x - random_distance : cars[i][j-1].initial_x + random_distance;
        random_cpy_x = cars[i][j-1].cpy_initial_x;
        random_final_x = cars[i][j-1].final_x;
    }
    random_model_car = random_direction == 0 ? (rand() % 3) * 2 : (rand() % 3) * 2 + 1;

    cars[i][j].car_model = car[random_model_car];
    cars[i][j].initial_x = random_initial_x;
    cars[i][j].cpy_initial_x = random_cpy_x;
    cars[i][j].final_x = random_final_x;
    cars[i][j].direction = random_direction;
    cars[i][j].defined_values = true;
}

void handle_car() {
    int i;
    for(i=0; i<MAP_HEIGHT; i++) {
        for (int j=0; j<3; j++) {
            if(!cars[i][j].defined_values) {
                set_car(i, j);
            } else if (cars[i][j].exists) {
                al_draw_bitmap(cars[i][j].car_model, cars[i][j].initial_x, cars[i][j].position_y, 0);
                move_car(i, j);
                loop_car(i, j);
            }   
        }
    }
}


void loop_car(int i, int j) {
    if(cars[i][j].initial_x >= cars[i][j].final_x && cars[i][j].direction == 0) {
        cars[i][j].initial_x = cars[i][j].cpy_initial_x;
    } else if(cars[i][j].initial_x <= cars[i][j].final_x && cars[i][j].direction == 1) {
        cars[i][j].initial_x = cars[i][j].cpy_initial_x;
    }
}
