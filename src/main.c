#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "../include/graphics.h"

int main (){
  if(al_init_graphics() != 0) {
    fprintf(stderr,"Erro ao iniciar o allegro");
    return -1;
  }

  draw_sprite();

  al_rest(5.0);

  cleanup_display();

  return 0;
}