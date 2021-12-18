# SDL_QOI

[QOI](https://github.com/phoboslab/qoi#readme) image decoding and encoding for SDL2 in C99. Copy SDL_QOI.h, SDL_QOI.c and [qoi.h](https://github.com/phoboslab/qoi/blob/master/qoi.h) into your project.

```c
SDL_Surface* sur = SDL_LoadQOI("./SDL_logo.qoi");
SDL_Texture* tex = SDL_LoadQOI_Texture(renderer, "./SDL_logo.qoi");

SDL_SaveQOI(sur, "SDL_logo2.qoi");
```

See `example.c` for a working example with SDL logo (`mkdir build && cd build && cmake .. && make && ./example`).
