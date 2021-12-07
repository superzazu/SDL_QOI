#include "SDL_QOI.h"
#define QOI_NO_STDIO
#define QOI_MALLOC(sz) SDL_malloc(sz)
#define QOI_FREE(p) SDL_free(p)
#define QOI_IMPLEMENTATION
#include "qoi.h"

static inline void* getPixels(
    SDL_RWops* src, qoi_desc* desc, Uint32* format, int freesrc) {
  if (src == NULL) {
    return NULL;
  }

  size_t size;
  void* data = SDL_LoadFile_RW(src, &size, freesrc);
  if (!data) {
    return NULL;
  }

  void* pixels = qoi_decode(data, size, desc, 0);
  if (pixels == NULL) {
    SDL_SetError("Unable to decode QOI");
    SDL_free(data);
    return NULL;
  }

  *format =
      desc->channels == 3 ? SDL_PIXELFORMAT_RGB24 : SDL_PIXELFORMAT_RGBA32;

  SDL_free(data);
  return pixels;
}

SDL_Surface* SDL_LoadQOI_RW(SDL_RWops* src, int freesrc) {
  qoi_desc desc;
  Uint32 format;
  void* pixels = getPixels(src, &desc, &format, freesrc);
  if (pixels == NULL) {
    return NULL;
  }

  SDL_Surface* sur = SDL_CreateRGBSurfaceWithFormatFrom(pixels, desc.width,
      desc.height, 8 * desc.channels, desc.width * desc.channels, format);

  return sur;
}

SDL_Texture* SDL_LoadQOI_Texture_RW(
    SDL_Renderer* ren, SDL_RWops* src, int freesrc) {
  qoi_desc desc;
  Uint32 format;
  void* pixels = getPixels(src, &desc, &format, freesrc);
  if (pixels == NULL) {
    return NULL;
  }

  SDL_Texture* tex = SDL_CreateTexture(
      ren, format, SDL_TEXTUREACCESS_STATIC, desc.width, desc.height);
  if (tex == NULL) {
    SDL_free(pixels);
    return NULL;
  }
  if (SDL_UpdateTexture(tex, NULL, pixels, desc.width * desc.channels) != 0) {
    SDL_free(pixels);
    SDL_DestroyTexture(tex);
    return NULL;
  }
  if (format == SDL_PIXELFORMAT_RGBA32) {
    SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
  }

  SDL_free(pixels);
  return tex;
}
