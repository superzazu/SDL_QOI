#include <SDL.h>
#include "SDL_QOI.h"

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

int main(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Unable to initialise SDL2: %s", SDL_GetError());
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("SDL_QOI example",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT,
      SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
  if (window == NULL) {
    SDL_Log("Unable to create window: %s", SDL_GetError());
    return 1;
  }
  SDL_Renderer* renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    SDL_Log("Unable to create renderer: %s", SDL_GetError());
    return 1;
  }
  SDL_RenderSetLogicalSize(renderer, WIN_WIDTH, WIN_HEIGHT);

  SDL_Texture* tex = SDL_LoadQOI_Texture(renderer, "./SDL_logo.qoi");
  if (tex == NULL) {
    SDL_Log("Unable to load file: %s", SDL_GetError());
    return 1;
  }

  int shouldQuit = 0;
  SDL_Event event;
  while (!shouldQuit) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT: shouldQuit = 1; break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tex, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
