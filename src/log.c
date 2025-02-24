#include <allegro5/allegro.h> // Biblioteca Allegro para gráficos
#include <stdlib.h> // Biblioteca padrão para alocação de memória e funções utilitárias
#include "../include/log.h" // Inclusão do cabeçalho com a definição da estrutura Log

extern ALLEGRO_BITMAP *tronco; // Bitmap representando o tronco no jogo

Log logs[NUM_LOGS]; // Array de troncos presentes no jogo

// Inicializa um tronco na posição y
void set_log(int y) {
    logs[y].initial_x = 0;
    logs[y].velocity = 1;
    logs[y].exists = true;
}

// Move um tronco na tela
void move_log(Log *log) {
    if (log->exists) {
        log->initial_x += log->velocity;
        // Se o tronco sair da tela, é reposiciona para o início
        if (log->initial_x > 96 * 9) {
            log->initial_x = -96;
        }
    }
}