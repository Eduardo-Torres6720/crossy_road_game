#include <stdbool.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "../include/game.h"
#include "../include/chicken.h"

#define CHICKEN_JUMP 96

ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer;
extern ALLEGRO_DISPLAY *display;

ALLEGRO_EVENT ev;

extern Chicken chicken_struct;

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
    al_draw_bitmap(chicken_struct.sprite_chicken, chicken_struct.positionx, chicken_struct.positiony, 0);  // Desenhar o sprite na nova posição
    al_flip_display();  // Atualizar a tela
}

bool close_window() {
    if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return false;
    }
}
