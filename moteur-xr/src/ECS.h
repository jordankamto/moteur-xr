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

#include <iostream>
#include <string>
#include <list>

// definition des entites de l'ecs pour UserInterface
// entite : interface window;
// comportements: Position, affichage, input;
// systeme: init, update, render

class Component;
class TranformComponent;

class Entity {
    public:
        Entity(const std::string name) : name(name) {

        }

        template<typename component, typename... Args>
        component* AddComponent(Args... args){
            if (typeid(component).name == typeid(TranformComponent).name){
                return transform;
            }

            component *comp = new component(args, ...);
            components.push_back(comp);
            return comp;
        }

        template<typename component>
        component* GetComponent(){
            for (auto comp : components){
                if (typeid(*comp).name == typeid(component).name){
                    return static_cast<component*>(comp);
                }
            }
            return nullptr;
        }
    private:
    TransformComponent* transform = nullptr;
    std::vector<Component*> components;
    std::string name;
};

class Component {
    public:
        virtual void update (float -){}
        virtual void Awake() {}
    private:
        Entity* owner;
};

class TransformComponent : Component{
    Vector3 position;
    Vector3 scale;
    Vector3 rotation;

    // Transform transform;
};

class RenderComponent : Component {
};

class System {
    virtual void AddComponent(Component* compo) = 0;
    virtual void DoWork() = 0;
};

class RenderSystem : System{

    virtual void AddComponent(Component* compo) {
        if (typeid(*RenderComponent).name == typeid(compo).name){
            components.push_back(compo)
        }
    }
    virtual void DoWork(){
        for (auto render : components){
            // recupperer la transform
            // appliquer les proprieter de la tranform
            // recupperer le shader
            // recupperer le material
            // appliquer le material au shader
            // appeler le moteur de rendu avec les proprieter
            render.Update()
        }
    }
    std::vector<RenderComponent*> components;
};