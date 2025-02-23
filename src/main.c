#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "../include/graphics.h"
#include "../include/map.h"
#include "../include/game.h"
#include "../include/chicken.h"
#include "../include/car.h"
#include "../include/tree.h"
#include "../include/scoreboard.h"

int main (){
  bool running = true;

  if(al_init_graphics() != 0) {
    fprintf(stderr,"Erro ao iniciar o allegro");
    return -1;
  } else if (al_init_game() != 0) {
    fprintf(stderr, "Erro ao iniciar os eventos");
    return -1;
  }

  set_chicken();
  start_scoreboard();

  srand(time(0));

  while(running) {
    random_map();
    draw_map();

    handle_car();

    moviment_chicken();

    colision_tree();
    
    display_follow_player();

    int points = return_points();

    render_score(points, 0, 0); // Você pode alterar esses números pra trocar a posição
    
    update_window();

    print_y();


    running = close_window();
  }

  cleanup_display();

  return 0;
}