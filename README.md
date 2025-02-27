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

-   Allegro_x86 5.2.10 versão estática https://github.com/liballeg/allegro5/releases
-   msys2 (windows) https://www.msys2.org/
-   Homebrew (Mac)
-   MinGw64
-   IDE

### Instalação Passo a Passo MinGw

Windows:

Utilize os seguintes comandos no terminal do msys2.

    pacman -Syu
    pacman -Su
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain

Confirme todas as perguntas (y para confirmar).

Não esqueça de colocar o caminho do mingw nas variáveis de ambiente.

Linux Ubunto/debian:

No terminal digite os seguintes comandos:

```bash
sudo apt update
sudo apt install mingw-w64
```

Linux Fedora:

No terminal digite o seguinte comando:

```bash
sudo dnf install mingw64-gcc
```

Linux Arch Linux:

No terminal digite o seguinte comando:

```bash
sudo pacman -S mingw-w64-gcc
```

Mac:

Instale o Homebrew com o seguinte comando:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Após a instalação digite o seguinte comando:

```bash
brew install mingw-w64
```

### Implementando a biblioteca

Copie os arquivos `lib, include e bin` da biblioteca do Allegro que foi baixada e cole no arquivo do compilador (mingw64)

O caminho do arquivo depende do local onde foi salvo, mas o padrão é `C:\msys2\mingw64`

## Rodando o jogo

Windows:

Após clonar o código, digite o seguinte comando para compilar o programa:

```bash
 gcc -g src/main.c src/graphics.c src/game.c src/map.c src/chicken.c src/car.c src/tree.c src/scoreboard.c src/log.c -o bin/main -lallegro -lallegro_image -lallegro_font
```

Linux e Mac:

Após clonar o código, digite o seguinte comando para compilar o programa:

```bash
x86_64-w64-mingw32-gcc -g src/main.c src/graphics.c src/game.c src/map.c src/chicken.c src/car.c src/tree.c src/scoreboard.c src/log.c -o bin/main.exe -lallegro -lallegro_image -lallegro_font
```

Por fim, abra a pasta bin e inicie o executável.

## Contribuidores

-   Caio (github: CaioML)
-   Agnes (github: AgnesRistau)
-   Davi (github: DaviJBF)
-   Eduardo (github: Eduardo-Torres6720)
