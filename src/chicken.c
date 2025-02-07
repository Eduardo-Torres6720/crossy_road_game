#include <allegro5/allegro.h>

#include "../include/chicken.h"

#define DISPLAY_HEIGHT 900
#define CHICKEN_JUMP 96

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_BITMAP *chicken;
extern ALLEGRO_EVENT ev;

extern int positionx;
extern int positiony;
bool key[ALLEGRO_KEY_MAX] = {false};

bool key_pressed = false;

void position_chicken() {
    int chicken_width = al_get_bitmap_width(chicken);
    int chicken_height = al_get_bitmap_height(chicken);
    //posição inicial
    positionx = chicken_width * 4;
    positiony = DISPLAY_HEIGHT - chicken_height;
}

void moviment_chicken() {
    bool preview_positionx_right = (positionx + CHICKEN_JUMP) >= 864; 
    bool preview_positionx_left = (positionx - CHICKEN_JUMP) < 0;
    bool preview_positiony_down = (positiony + CHICKEN_JUMP) >= 900; 

    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        key[ev.keyboard.keycode] = true;  // Marca a tecla como pressionada
    } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            key[ev.keyboard.keycode] = false; // Marca a tecla como solta
            key_pressed = false;
    } else if (ev.type == ALLEGRO_EVENT_TIMER) {
        // Mover o sprite com base nas teclas pressionadas
        if (key[ALLEGRO_KEY_UP] && !key_pressed) {
            positiony -= CHICKEN_JUMP;  // Move para cima
            key_pressed = true;
            chicken = al_load_bitmap("../assets/parado_costa.png");
        } else if (key[ALLEGRO_KEY_DOWN] && !key_pressed && !preview_positiony_down) {
            positiony += CHICKEN_JUMP;  // Move para baixo
            key_pressed = true;
            chicken = al_load_bitmap("../assets/parado_frente.png");
        } else if (key[ALLEGRO_KEY_LEFT] && !key_pressed && !preview_positionx_left) {
            positionx -= CHICKEN_JUMP;  // Move para a esquerda
            key_pressed = true;
            chicken = al_load_bitmap("../assets/parado_lado.png");
        } else if (key[ALLEGRO_KEY_RIGHT] && !key_pressed && !preview_positionx_right) {
            positionx += CHICKEN_JUMP;  // Move para a direita
            key_pressed = true;
            chicken = al_load_bitmap("../assets/parado_lado_direito.png");
        }

    }

}