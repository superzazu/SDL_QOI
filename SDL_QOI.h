/** \file SDL_QOI.h */

/**
 * \mainpage SDL_QOI
 *
 * [QOI](https://github.com/phoboslab/qoi#readme) image decoding and encoding
 * for SDL2 in C99. Copy SDL_QOI.h, SDL_QOI.c and
 * [qoi.h](https://github.com/phoboslab/qoi/blob/master/qoi.h)
 * into your project.
 *
 * Checkout the file "example.c" for a full example, or jump right in:
 *
 * \sa SDL_LoadQOI_RW
 * \sa SDL_LoadQOI_Texture_RW
 * \sa SDL_LoadQOI
 * \sa SDL_LoadQOI_Texture
 * \sa SDL_SaveQOI_RW
 * \sa SDL_SaveQOI
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

/**
 * \fn int SDL_SaveQOI_RW(SDL_Surface* sur, SDL_RWops* dst, int freedst)
 * \brief Saves QOI data from a SDL_Surface.
 *
 *    \param sur the SDL_Surface to read from
 *    \param dst the SDL_RWops to save to
 *    \param freedst if non-zero, calls SDL_RWclose() on dst before returning
 *   \return 0 if success, non-zero if an error happened
 *
 * \sa SDL_SaveQOI
 */
int SDL_SaveQOI_RW(SDL_Surface* sur, SDL_RWops* dst, int freedst);

/**
 * Saves a surface as a QOI file. Convenience macro.
 */
#define SDL_SaveQOI(sur, dst) SDL_SaveQOI_RW(sur, SDL_RWFromFile(dst, "wb"), 1)

#endif // SDL_QOI_H
