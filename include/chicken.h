#ifndef CHICKEN_H
#define CHICKEN_H

typedef struct {
    int positionx;
    int positiony;
    int movement_performed;
    ALLEGRO_BITMAP *sprite_chicken;
} Chicken;

void set_chicken();

void moviment_chicken();

#endif