#include <allegro5/allegro.h>
#include <stdio.h>

#include "../include/chicken.h"
#include "../include/tree.h"

#define DISPLAY_HEIGHT 900
#define CHICKEN_JUMP 96

extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_BITMAP *chicken;
extern ALLEGRO_EVENT ev;

Chicken chicken_struct;

bool key[ALLEGRO_KEY_MAX] = {false};

bool key_pressed = false; // Verifica se uma tecla ta pressionada
bool movement = false; // Verifica se a galinha ta se movimentando

// Atualiza os pontos verificando se é um ponto valido
void update_points() {
    if (chicken_struct.step_control > chicken_struct.points) {
        chicken_struct.points = chicken_struct.step_control;
    }
}

void set_chicken() {
    int chicken_width = al_get_bitmap_width(chicken);
    int chicken_height = al_get_bitmap_height(chicken);
    //posição inicial
    chicken_struct.positionx = chicken_width * 4;
    chicken_struct.positiony = DISPLAY_HEIGHT - chicken_height;
    chicken_struct.movement_performed_x = 0;
    chicken_struct.movement_performed_y = 0;
    chicken_struct.jumpx = 0;
    chicken_struct.jumpy = 0;
    chicken_struct.sprite_chicken = chicken;
}

void moviment_chicken() {

    bool preview_positionx_right = (chicken_struct.positionx + CHICKEN_JUMP) >= 864; 
    bool preview_positionx_left = (chicken_struct.positionx - CHICKEN_JUMP) < 0;
    bool preview_positiony_down = (chicken_struct.positiony + CHICKEN_JUMP) >= 900; 

    al_wait_for_event(event_queue, &ev);
    if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        key[ev.keyboard.keycode] = true;  // Marca a tecla como pressionada
    } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            key[ev.keyboard.keycode] = false; // Marca a tecla como solta
            key_pressed = false;
    } else if (ev.type == ALLEGRO_EVENT_TIMER) {
        // Mover o sprite com base nas teclas pressionadas

        // movimento  da galinha
        if (key[ALLEGRO_KEY_UP] && !key_pressed && !movement) {
            chicken_struct.movement_performed_y = -CHICKEN_JUMP;
            key_pressed = true;
            chicken_struct.sprite_chicken = al_load_bitmap("../assets/parado_costa.png");

            if (!detect_colision_tree()) {
                chicken_struct.step_control++; // Incrementa o step_control pq vai funcionar, confia
            }

        } else if (key[ALLEGRO_KEY_DOWN] && !key_pressed && !preview_positiony_down && !movement) {
            key_pressed = true;
            chicken_struct.sprite_chicken = al_load_bitmap("../assets/parado_frente.png");
            chicken_struct.movement_performed_y = CHICKEN_JUMP;

            if (!detect_colision_tree()) {
                chicken_struct.step_control--; // Decrementa o step_control pq vai funciona, confia
            }

        } else if (key[ALLEGRO_KEY_LEFT] && !key_pressed && !preview_positionx_left && !movement) {
            key_pressed = true;
            chicken_struct.movement_performed_x = -CHICKEN_JUMP;
            chicken_struct.sprite_chicken = al_load_bitmap("../assets/parado_lado.png");
        } else if (key[ALLEGRO_KEY_RIGHT] && !key_pressed && !preview_positionx_right && !movement) {
            key_pressed = true;
            chicken_struct.movement_performed_x = CHICKEN_JUMP;
            chicken_struct.sprite_chicken = al_load_bitmap("../assets/parado_lado_direito.png");
        }
        update_points(); // Isso vai atualizar a pontuação. Tenha fé em Deus!

    }

}

int return_points() {
    return chicken_struct.points;
}

// Faz a galinha andar em partes (16px)
void fluid_movement() {
    if(chicken_struct.movement_performed_x != 0) {
        chicken_struct.jumpx = chicken_struct.movement_performed_x>0 ? CHICKEN_JUMP/6 : -CHICKEN_JUMP/6;
        chicken_struct.movement_performed_x -= chicken_struct.jumpx;
        chicken_struct.positionx += chicken_struct.jumpx;
        movement = true;
    } else if (chicken_struct.movement_performed_y != 0) {
        chicken_struct.jumpy = chicken_struct.movement_performed_y>0 ? CHICKEN_JUMP/6 : -CHICKEN_JUMP/6;
        chicken_struct.movement_performed_y -= chicken_struct.jumpy;
        chicken_struct.positiony += chicken_struct.jumpy;
        movement = true;
    } else {
        chicken_struct.jumpx = 0;
        chicken_struct.jumpy = 0;
        movement = false;
    }
}

void verify_reset() {
    chicken_struct.points = 0;
    chicken_struct.step_control = 0;
}
