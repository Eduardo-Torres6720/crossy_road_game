#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../include/graphics.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *sprite;

int al_init_graphics() {
    if(!al_init()) {
        return 1;
    } else if(!al_init_image_addon()) {
        return 1;
    } else {
        return 0;
    }
}

void draw_sprite() {
    display = al_create_display(600, 800);
    sprite = al_load_bitmap("../assets/parado_costa.png");

    int original_width = al_get_bitmap_width(sprite);
    int original_height = al_get_bitmap_height(sprite);
    float scale_factor = 3.0f;
    int chicken_width = original_width * scale_factor;
    int chicken_height = original_height * scale_factor;

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_scaled_bitmap(
        sprite,
        0, 0, original_width, original_height,
        100, 100, chicken_width, chicken_height,
        0
    );
    al_flip_display();
}

void cleanup_display() {
    al_destroy_bitmap(sprite);
    al_destroy_display(display);
}