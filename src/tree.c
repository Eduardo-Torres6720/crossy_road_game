#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#include "../include/tree.h"
#include "../include/chicken.h"

extern Chicken chicken_struct;
Tree trees[12][2];

void colision_tree() {
    for(int i=0; i<12; i++) {
        for(int j=0; j<2; j++) {
            if(chicken_struct.positionx < trees[i][j].final_x && chicken_struct.positionx >= trees[i][j].initial_x && trees[i][j].position_y == chicken_struct.positiony) {
                chicken_struct.positionx = chicken_struct.positionx - chicken_struct.movement_performed_x;
                chicken_struct.positiony = chicken_struct.positiony - chicken_struct.movement_performed_y;
            } 
        }
    }
}

bool detect_colision_tree() {
    for(int i=0; i<12; i++) {
        for(int j=0; j<2; j++) {
            if(chicken_struct.positionx < trees[i][j].final_x && chicken_struct.positionx >= trees[i][j].initial_x && trees[i][j].position_y == chicken_struct.positiony) {
                return true;
            } 
        }
    }
    return false;
}
