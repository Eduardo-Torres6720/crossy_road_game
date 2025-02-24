#include <allegro5/allegro.h>
#include <stdlib.h>
#include "../include/log.h"

extern ALLEGRO_BITMAP *tronco;

Log logs[NUM_LOGS];

void set_log(int y) {
    logs[y].initial_x = 0;
    logs[y].velocity = 1;
    logs[y].exists = true;
}

void move_log(Log *log) {
    if (log->exists) {
        log->initial_x += log->velocity;
        if (log->initial_x > 96 * 9) {
            log->initial_x = -96;
        }
    }
}