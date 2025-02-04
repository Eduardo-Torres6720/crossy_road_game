#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "../include/graphics.h"
#include "../include/game.h"

int main (){
  bool running = true;

  if(al_init_graphics() != 0) {
    fprintf(stderr,"Erro ao iniciar o allegro");
    return -1;
  } else if (al_init_game() != 0) {
    fprintf(stderr, "Erro ao iniciar os eventos");
    return -1;
  }

  draw_sprite();

  while(running) {
    draw_map();

    moviment_chicken();

    update_window();

    running = close_window();
  }

  cleanup_display();

  return 0;
}