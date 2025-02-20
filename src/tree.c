#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#include "../include/tree.h"

extern int positionx;
extern int positiony;
extern int moviment_performed;
Tree trees[12][2];

void colision_tree() {
    for(int i=0; i<12; i++) {
        for(int j=0; j<2; j++) {
            if(positionx < trees[i][j].final_x && positionx >= trees[i][j].initial_x && trees[i][j].position_y == positiony) {
                positionx = positionx - moviment_performed;
            } 
        }
    }
}