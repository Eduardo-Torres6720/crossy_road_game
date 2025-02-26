# Crossy Road

## Sobre Crossy Road

Esse programa se trata da replica do jogo arcade Crossy road, cujo principal objetivo é atravessar pistas e outros obstaculos, conseguindo o maior número de pontos.

## Como jogar

-   Setas do teclado para movimentar o player
-   Evite ser atingido pelos carros ou cair nos rios
-   O jogo é infinito, busque a maior pontuação possível

## Ferramentas e linguagem utilizada

-   Allegro5
-   MinGw (compilador)
-   C

## Instalação

### Requisitos

-   Allegro_x86 5.2.10 versão estática
-   msys2
-   MinGw64
-   IDE

### Instalação Passo a Passo MinGw

Utilize os seguintes comandos no terminal do msys2.

    pacman -Syu
    pacman -Su
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain

Confirme todas as perguntas (y para confirmar).

Não esqueça de colocar o caminho do mingw nas variáveis de ambiente.

### Implementando a biblioteca

Copie os arquivos `lib, include e bin` da biblioteca do Allegro que foi baixada e cole no arquivo do compilador (mingw64)

O caminho do arquivo depende do local onde foi salvo, mas o padrão é `C:\msys2\mingw64`

## Rodando o jogo

Após clonar o código, digite o seguinte comando para compilar o programa:

```bash
 gcc -g src/main.c src/graphics.c src/game.c src/map.c src/chicken.c src/car.c src/tree.c src/scoreboard.c src/log.c -o bin/main -lallegro -lallegro_image -lallegro_font -I/path/to/allegro/include -L/path/to/allegro/lib
```

Por fim, abra a pasta bin e inicie o executável.
