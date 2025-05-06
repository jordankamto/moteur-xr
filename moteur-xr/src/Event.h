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

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void OnEvent(const SDL_Event &event) = 0;
};

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void Add(Observer *observer) = 0;
    virtual void Remove(Observer *observer) = 0;
    virtual void PollEvent() = 0;
    virtual void ActivatePollEvent() = 0;
};

class Event : public Subject
{
private:
    std::list<Observer *> observers; // Liste des observateurs
    SDL_Event event;                 // État du sujet

public:
    void Add(Observer *observer) override
    {
        observers.push_back(observer);
    }

    void Remove(Observer *observer) override
    {
        observers.remove(observer);
    }
    void PollEvent();
    void ActivatePollEvent();
};

class EventListener : public Observer
{
private:
    std::string name;
    Event &event;

public:
    EventListener(Event &sub, std::string name) : event(sub), name(name)
    {
        event.Add(this);
    }

    ~EventListener()
    {
        event.Remove(this);
    }

    void OnEvent(const SDL_Event &e);
};
