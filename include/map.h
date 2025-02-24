#ifndef MAP_H
#define MAP_H

typedef struct {
    int positiony;
    int bitmap_id;
    bool exist;
} Floor;

void draw_map();

void random_map();

void display_follow_player();

#endif