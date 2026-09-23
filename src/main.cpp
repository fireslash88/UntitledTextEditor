#include "raylib.h"
#include "core/editor.h"

//Global Variables
const int screenWidth=1280;
const int screenHeight=720;

int main() {

    Editor editor;

    //Set Window to be resizable
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(screenWidth,screenHeight,"Template Raylib");

    //Initialize the font and all the variables needed
    editor.Initializing();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        //Updates everything
        editor.Update();

        //Draws the frame
        editor.DrawFrame();
    }

    //Unload eventually loaded resources
    editor.UnloadResources();

    CloseWindow();
    return 0;
}