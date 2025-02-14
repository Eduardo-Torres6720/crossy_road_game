#ifndef CAR_H
#define CAR_H

typedef struct {
    int frequency;
    ALLEGRO_BITMAP *car_model;
    int initial_x;
    int cpy_initial_x;
    int final_x;
    int position_y;
    int direction;
    bool exists;
    bool defined_values;
} Car;

void handle_car();

void set_car(int i);

void move_car(int i);

void loop_car(int i);

#endif