#ifndef CHICKEN_H
#define CHICKEN_H

typedef struct {
    int positionx;
    int positiony;
    bool on_log;
    int movement_performed_x;
    int movement_performed_y;
    int points;
    int step_control;
    ALLEGRO_BITMAP *sprite_chicken;
} Chicken;

void set_chicken();

void moviment_chicken();

bool detect_colision_tree();

int return_points();

#endif