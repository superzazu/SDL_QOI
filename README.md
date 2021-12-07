# SDL_QOI

[QOI](https://github.com/phoboslab/qoi#readme) image decoding for SDL2 in C99. Copy SDL_QOI.h, SDL_QOI.c and [qoi.h](https://github.com/phoboslab/qoi/commit/03606a0be7bff7a734c805aea638d48ed0e5e72f) into your project.

```c
SDL_Surface* sur = SDL_LoadQOI("./SDL_logo.qoi");
SDL_Texture* tex = SDL_LoadQOI_Texture(renderer, "./SDL_logo.qoi");
```

See `example.c` for a working example with SDL logo (`mkdir build && cd build && cmake .. && make && ./example`).
