#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/graphics.h"

#include <stdio.h>

#define DISPLAY_HEIGHT 900
#define DISPLAY_WIDTH 864

ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *chicken;
ALLEGRO_BITMAP *gram;
ALLEGRO_BITMAP *road;
ALLEGRO_BITMAP *car[6];
ALLEGRO_BITMAP *tree;

int positionx;
int positiony;

int al_init_graphics() {
    if(!al_init()) {
        return 1;
    } else if(!al_init_image_addon()) {
        return 1;
    } else {
        display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
        chicken = al_load_bitmap("../assets/parado_costa.png");
        gram = al_load_bitmap("../assets/grama.png");
        road = al_load_bitmap("../assets/estrada.png");
        tree = al_load_bitmap("../assets/arvore.png");
        car[0] = al_load_bitmap("../assets/carro_azul.png");
        car[1] = al_load_bitmap("../assets/carro_azul_lado.png");
        car[2] = al_load_bitmap("../assets/carro_verde.png");
        car[3] = al_load_bitmap("../assets/carro_verde_lado.png");
        car[4] = al_load_bitmap("../assets/carro_laranja.png");
        car[5] = al_load_bitmap("../assets/carro_laranja_lado.png");
        return 0;
    }
}

void cleanup_display() {
    al_destroy_bitmap(chicken);
    al_destroy_display(display);
    al_destroy_bitmap(gram);
    al_destroy_bitmap(road);
}
