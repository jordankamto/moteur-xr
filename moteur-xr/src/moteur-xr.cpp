#include "Application.h"

int main(int argc, char** argv){    
    Application *app = new Application();

    if (app != nullptr && app->Init()){

        app->Update();
        app->Release();

        delete app;

        return 0;
    }

    return 1;
}
