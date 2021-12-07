/** \file SDL_QOI.h */

/**
 * \mainpage SDL_QOI
 *
 * [QOI](https://github.com/phoboslab/qoi#readme) image decoding for SDL2
 * in C99. Copy SDL_QOI.h, SDL_QOI.c and
 * [qoi.h](https://github.com/phoboslab/qoi/commit/03606a0be7bff7a734c805aea638d48ed0e5e72f)
 * into your project.
 *
 * Checkout the file "example.c" for a full example, or jump right in:
 *
 * \sa SDL_LoadQOI_RW
 * \sa SDL_LoadQOI_Texture_RW
 * \sa SDL_LoadQOI
 * \sa SDL_LoadQOI_Texture
 *
 */

#ifndef SDL_QOI_H
#define SDL_QOI_H

#include <SDL.h>

/**
 * \fn SDL_Surface* SDL_LoadQOI_RW(SDL_RWops* src, int freesrc)
 * \brief Loads QOI data and returns a SDL_Surface.
 *
 * You should free the pixels before calling SDL_FreeSurface when done using
 * (SDL_free(surface->pixels)).
 *
 *    \param src the SDL_RWops to read from
 *    \param freesrc if non-zero, calls SDL_RWclose() on src before returning
 *   \return the surface, or NULL if there was an error.
 *
 * \sa SDL_LoadQOI
 */
SDL_Surface* SDL_LoadQOI_RW(SDL_RWops* src, int freesrc);

/**
 * \fn SDL_Texture* SDL_LoadQOI_Texture_RW(
         SDL_Renderer* ren, SDL_RWops* src, int freesrc)
 * \brief Loads QOI data and returns a SDL_Texture.
 *
 * By default textures with an alpha mask are set up for blending
 (SDL_BLENDMODE_BLEND).
 *
 *    \param ren the rendering context
 *    \param src the SDL_RWops to read from
 *    \param freesrc if non-zero, calls SDL_RWclose() on src before returning
 *   \return the texture, or NULL if there was an error.
 *
 * \sa SDL_LoadQOI_Texture
 */
SDL_Texture* SDL_LoadQOI_Texture_RW(
    SDL_Renderer* ren, SDL_RWops* src, int freesrc);

/**
 * Loads a surface from a QOI file. Convenience macro.
 */
#define SDL_LoadQOI(file) SDL_LoadQOI_RW(SDL_RWFromFile(file, "rb"), 1)

/**
 * Loads a texture from a QOI file. Convenience macro.
 */
#define SDL_LoadQOI_Texture(ren, file) \
  SDL_LoadQOI_Texture_RW(ren, SDL_RWFromFile(file, "rb"), 1)

#endif // SDL_QOI_H
