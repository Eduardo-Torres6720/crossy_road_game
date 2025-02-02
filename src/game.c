#include <stdbool.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "../include/game.h"

#define CHICKEN_JUMP 96

ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_BITMAP *sprite;

ALLEGRO_EVENT ev;

extern int positionx;
extern int positiony;
bool key[ALLEGRO_KEY_MAX] = {false};

bool key_pressed = false;

int al_init_game() {
    //criando o timer
    timer = al_create_timer(1.0 / 60.0);
    //criando a fila de eventos
    event_queue = al_create_event_queue();
    if (!timer) {
        return 1;
    } else if (!event_queue) {
        return 1;
    }

    al_install_keyboard();
    //registra os eventos de pressionamente e soltagem de teclas, 
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    //iniciando o timer
    al_start_timer(timer);
    return 0;
}

void update_window() {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(sprite, positionx, positiony, 0);  // Desenhar o sprite na nova posição
    al_flip_display();  // Atualizar a tela
}

bool close_window() {
    if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return false;
    }
}

void moviment_chicken() {

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
            sprite = al_load_bitmap("../assets/parado_costa.png");
        } else if (key[ALLEGRO_KEY_DOWN] && !key_pressed) {
            positiony += CHICKEN_JUMP;  // Move para baixo
            key_pressed = true;
            sprite = al_load_bitmap("../assets/parado_frente.png");
        } else if (key[ALLEGRO_KEY_LEFT] && !key_pressed) {
            positionx -= CHICKEN_JUMP;  // Move para a esquerda
            key_pressed = true;
            sprite = al_load_bitmap("../assets/parado_lado.png");
        } else if (key[ALLEGRO_KEY_RIGHT] && !key_pressed) {
            positionx += CHICKEN_JUMP;  // Move para a direita
            key_pressed = true;
            sprite = al_load_bitmap("../assets/parado_lado_direito.png");
        }
    }

}
