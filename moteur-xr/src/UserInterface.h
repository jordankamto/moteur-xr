#pragma once

#include "imgui.h"
#include "imgui/imgui_impl_sdl3.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL3/SDL.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL3/SDL_opengles2.h>
#else
#include <SDL3/SDL_opengl.h>
#endif

#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

#include <string>

class UserInterface{
    private:
        // static bool display; // Ajout du mot-clé static

    public:
        UserInterface(){}
        static void InitUI();
        static void DisplayUI();
        static void RenderUI();
};
