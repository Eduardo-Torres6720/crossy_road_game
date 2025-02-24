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
ALLEGRO_BITMAP *water;
ALLEGRO_BITMAP *numbers[10];
ALLEGRO_BITMAP *tronco;

int positionx;
int positiony;
// iniciando sistemas de graficos
int al_init_graphics() {
    if(!al_init()) {
        return 1;
    } else if(!al_init_image_addon()) {
        return 1;
    } else { 
        // rederizando os assets
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
        water = al_load_bitmap("../assets/rio.png");
        load_numbers();
        tronco = al_load_bitmap("../assets/tronco.png");
        return 0;
    }
}

void load_numbers() {
    
    for (int i = 0; i < 10; i++) {
        char path[256];
        snprintf(path, sizeof(path), "../assets/numeros/num%d.png", i); // Construir o caminho do arquivo
        numbers[i] = al_load_bitmap(path); // Carregar o bitmap
        if (!numbers[i]) {
            fprintf(stderr, "Failed to load number %d!\n", i);
            exit(-1);
        }
    }
}
// Destruindo os assets
void cleanup_display() {
    al_destroy_bitmap(chicken);
    al_destroy_display(display);
    al_destroy_bitmap(gram);
    al_destroy_bitmap(road);
    al_destroy_bitmap(water);
}