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

 class Application {
    private:
        SDL_GLContext gl_context = nullptr;
        SDL_Window* window = nullptr;
        bool running = true;
        ImGuiIO* io;
        const char* glsl_version = "#version 450";

        // init sdl
        bool SDLInit();
        bool OpenGLInit();
        bool ImguiInit();

    public:
        Application(){}
        bool Init();
        void Update();
        void Release();
        //ajout de getter pour acceder aux variables privées
        bool getRunning(){return running;}
        SDL_Window* getWindow(){return window;}
        ImGuiIO* getIo(){return io;}
 };