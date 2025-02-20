#ifndef CAR_H
#define CAR_H

typedef struct {
    ALLEGRO_BITMAP *car_model;
    int initial_x;
    int cpy_initial_x;
    int final_x;
    int position_y;
    int direction;
    int velocity;
    bool exists;
    bool defined_values;
} Car;

void handle_car();

void set_car(int i, int j);

void move_car(int i, int j);

void loop_car(int i, int j);

#endif