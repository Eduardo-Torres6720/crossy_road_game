#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/car.h"

#define MAP_HEIGHT 12

extern ALLEGRO_BITMAP *car[6];

Car cars[12];

void move_car(int i) {
    cars[i].initial_x = cars[i].direction == 0 ? cars[i].initial_x + 2 : cars[i].initial_x - 2;
}

void set_car(int i) {
    if(!cars[i].defined_values) {

        int random_direction = rand() % 2;
        int random_model_car = random_direction == 0 ? (rand() % 3) * 2 : (rand() % 3) * 2 + 1;
        int random_initial_x = random_direction == 0 ? -1 * (rand() % 600) - 100 : (rand() % 120) + 900;
        int random_final_x = random_direction == 0 ? (rand() % 120) + 900 : -1 * (rand() % 600) - 100;

        cars[i].car_model = car[random_model_car];
        cars[i].initial_x = random_initial_x;
        cars[i].cpy_initial_x = cars[i].initial_x;
        cars[i].final_x = random_final_x;
        cars[i].direction = random_direction;
        cars[i].frequency = 1;
        cars[i].defined_values = true;
    }
}

void handle_car() {
    int i;
    for(i=0; i<MAP_HEIGHT; i++) {
        if(cars[i].exists) {
            set_car(i);
            al_draw_bitmap(cars[i].car_model, cars[i].initial_x, cars[i].position_y, 0);
            move_car(i);
            loop_car(i);
        }
    }
}


void loop_car(int i) {
    if(cars[i].initial_x >= cars[i].final_x && cars[i].direction == 0) {
        cars[i].initial_x = cars[i].cpy_initial_x;
    } else if(cars[i].initial_x <= cars[i].final_x && cars[i].direction == 1) {
        cars[i].initial_x = cars[i].cpy_initial_x;
    }
}
