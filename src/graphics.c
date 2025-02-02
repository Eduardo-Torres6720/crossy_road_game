#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/graphics.h"


#define DISPLAY_HEIGHT 900
#define DISPLAY_WIDTH 864

ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *sprite;

int positionx;
int positiony;

int al_init_graphics() {
    if(!al_init()) {
        return 1;
    } else if(!al_init_image_addon()) {
        return 1;
    } else {
        display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
        sprite = al_load_bitmap("../assets/parado_costa.png");
        return 0;
    }
}

void draw_sprite() {
    int chicken_width = al_get_bitmap_width(sprite);
    int chicken_height = al_get_bitmap_height(sprite);

    positionx = chicken_width * 4;
    positiony = DISPLAY_HEIGHT - chicken_height;

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_bitmap(sprite, positionx, positiony, 0);
    al_flip_display();
}

void cleanup_display() {
    al_destroy_bitmap(sprite);
    al_destroy_display(display);
}