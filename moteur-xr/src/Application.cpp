#include "Application.h"
#include "UserInterface.h"
#include <string>
#include <iostream>

bool display = false; // Définition de la variable statique

// // Add a buffer to store input text
char inputText[256] = "";

bool Application::Init(){
    return SDLInit() && OpenGLInit() && ImguiInit();
}

void Application::Update(){

    // Main loop
     ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    while (running)
    {
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
                running = false;
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))
                running = false;
            if (event.type == SDL_EVENT_KEY_DOWN) {
                
                if(event.key.key == SDLK_ESCAPE){
                    running = false;
                }
            }
            // Handle text input events
            if (event.type == SDL_EVENT_TEXT_INPUT) {
                strcat(inputText, event.text.text);
            }
        }
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED)
        {
            SDL_Delay(10);
            continue;
        }

        // Refactoring imgui interface creation
        UserInterface::InitUI();
        UserInterface::DisplayUI();
        UserInterface::RenderUI();

        glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
}

void Application::Release(){
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DestroyContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

bool Application::SDLInit(){

    // Setup SDL
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        printf("Error: SDL_Init(): %s\n", SDL_GetError());
        return -1;
    }

    // Decide GL+GLSL versions
    // GL 3.0 + GLSL 130
    // const char* glsl_version = "#version 450";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
    window = SDL_CreateWindow("Moteur XR", 1280, 720, window_flags);
    if (window == nullptr)
    {
        printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
        return false;
    }
    return true;
}

bool Application::OpenGLInit(){
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    gl_context = SDL_GL_CreateContext(window);
    if (gl_context == nullptr)
    {
        printf("Error: SDL_GL_CreateContext(): %s\n", SDL_GetError());
        return false;
    }

    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync
    SDL_ShowWindow(window);
    return true;
}

bool Application::ImguiInit(){


    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    io = &ImGui::GetIO();
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    //ImGui::StyleColorsDark();
    ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL3_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);

    return true;
}

void UserInterface::InitUI(){
    // Initialisation du frame ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();
}
void UserInterface::DisplayUI(){
    //Affichage du contenu de la fenetre
        ImGui::Begin("Fenetre Imgui");
        ImGui::Text("BIENVENU SUR LA FENETRE DE SuperAdmin");
        ImGui::Text("Entrez un texte à afficher dans la console");
        ImGui::InputText("Console Text", inputText, IM_ARRAYSIZE(inputText));
        if (ImGui::Button("Save"))
            std::cout << inputText << std::endl;
        if(ImGui::Button("Display Window"))
            if(display){
                display = false;
            }
            else {display = true;}
        ImGui::End();

        if(display)
            {ImGui::Begin("Dummy Window");
            ImGui::Text("Je suis une fenetre test");
            ImGui::End();}
}
void UserInterface::RenderUI(){
    // Rendering
        ImGui::Render();
}