#include <allegro5/allegro.h> 
#include <stdio.h> 
#include <stdlib.h> 

#include "../include/car.h" 
#include "../include/chicken.h"
#include "../include/game.h"

#define MAP_HEIGHT 12 // Número de faixas da estrada

extern ALLEGRO_BITMAP *car[6]; // Modelos de carros
extern Chicken chicken_struct; // Estrutura da galinha

Car cars[12][3]; // Matriz de carros (faixas e posições)

// Move o carro conforme sua direção e velocidade
void move_car(int i, int j) {
    cars[i][j].initial_x = cars[i][j].direction == 0 ? cars[i][j].initial_x + cars[i][j].velocity : cars[i][j].initial_x - cars[i][j].velocity;
    cars[i][j].position_x_inicial = cars[i][j].direction == 0 ? cars[i][j].position_x_inicial + cars[i][j].velocity : cars[i][j].position_x_inicial - cars[i][j].velocity;
    cars[i][j].position_x_final = cars[i][j].direction == 0 ? cars[i][j].position_x_final + cars[i][j].velocity : cars[i][j].position_x_final - cars[i][j].velocity;
}

// Define atributos iniciais do carro
void set_car(int i, int j) {
    // Declarando variaveis de valores aleatorios
    int random_direction;
    int random_model_car;
    int random_initial_x;
    int random_final_x;
    int random_cpy_x;
    int random_velocity;

    if (j == 0) {
        // definindo valores do primeiro carro da faixa
        random_direction = rand() % 2;
        random_initial_x = random_direction == 0 ? -1 * (rand() % 800) - 100 : (rand() % 320) + 900;
        random_final_x = random_direction == 0 ? (rand() % 320) + 900 : -1 * (rand() % 800) - 100;
        random_cpy_x = random_initial_x;
        random_velocity = (rand() % 4) + 2;
    } else {
        // definindo valores dos demais carros da faixa
        random_direction = cars[i][j-1].direction;
        int random_distance = (rand() % 300) + 200;
        random_initial_x = random_direction == 0 ? cars[i][j-1].initial_x - random_distance : cars[i][j-1].initial_x + random_distance;
        random_cpy_x = cars[i][j-1].cpy_initial_x;
        random_final_x = cars[i][j-1].final_x;
        random_velocity = cars[i][j-1].velocity;
    }
    random_model_car = random_direction == 0 ? (rand() % 3) * 2 : (rand() % 3) * 2 + 1;

    // Atribuindo os valores dos carros
    cars[i][j].car_model = car[random_model_car];
    cars[i][j].initial_x = random_initial_x;
    cars[i][j].cpy_initial_x = random_cpy_x;
    cars[i][j].final_x = random_final_x;
    cars[i][j].direction = random_direction;
    cars[i][j].velocity = random_velocity;
    cars[i][j].defined_values = true;
    cars[i][j].position_x_inicial = cars[i][j].initial_x;
    cars[i][j].position_x_final = cars[i][j].initial_x + 96;
}

// Gerencia os carros no jogo
void handle_car() {
    int i;
    for(i=0; i<MAP_HEIGHT; i++) {
        for (int j=0; j<3; j++) {
            if(!cars[i][j].defined_values) {
                // Definindo os valores dos carros caso não esteja definido
                set_car(i, j);
            } else if (cars[i][j].exists) {
                // desenha os carros e lida com funções dos carros
                al_draw_bitmap(cars[i][j].car_model, cars[i][j].initial_x, cars[i][j].position_y, 0);
                colision_car(&i, &j);
                move_car(i, j);
                loop_car(i, j);
            }   
        }
    }
}

// Reinicia o carro ao sair da tela
void loop_car(int i, int j) {
    if(cars[i][j].initial_x >= cars[i][j].final_x && cars[i][j].direction == 0) { // carro que estão andando da esquerda para direita 
        cars[i][j].initial_x = cars[i][j].cpy_initial_x;
        cars[i][j].position_x_inicial = cars[i][j].initial_x;
        cars[i][j].position_x_final = cars[i][j].initial_x + 96;
    } else if(cars[i][j].initial_x <= cars[i][j].final_x && cars[i][j].direction == 1) { // carro que estão andando da direita para esquerda
        cars[i][j].initial_x = cars[i][j].cpy_initial_x;
        cars[i][j].position_x_inicial = cars[i][j].initial_x;
        cars[i][j].position_x_final = cars[i][j].initial_x + 96;
    }
}

// colisão entre galinha e o carro
void colision_car(int* i, int* j) {
    if(cars[*i][*j].position_x_inicial <= chicken_struct.positionx + 96/2 && cars[*i][*j].position_x_final >= chicken_struct.positionx + 96/2 && chicken_struct.positiony == cars[*i][*j].position_y) {
        // reseta a galinha, mapa, carros e troncos
        reset();
        // reseta o contador dos loops
        *i = 0;
        *j = 0;
    }
}
