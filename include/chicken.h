#ifndef CHICKEN_H
#define CHICKEN_H

typedef struct {
    int positionx;
    int positiony;
    int movement_performed_x;
    int movement_performed_y;
    int jumpx;
    int jumpy;
    int points; // QUANDO RESETAR A GALINHA, VOCÊ PRECISA ZERAR ISSO
    int step_control; // QUANDO RESETAR A GALINHA, VOCÊ PRECISA ZERAR ISSO
    ALLEGRO_BITMAP *sprite_chicken;
} Chicken;

void set_chicken();

void moviment_chicken();

bool detect_colision_tree();

int return_points();

void verify_reset();

void fluid_movement();

#endif