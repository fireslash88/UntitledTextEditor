#include "raylib.h"
#include "editor.h"
#include "config.h"

//Global Variables
const int screenWidth=1280;
const int screenHeight=720;

int main() {

    //Set Window to be resizable
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);

    InitWindow(screenWidth,screenHeight,"Template Raylib");

    font=LoadFontEx("../../fonts/0xProtoNerdFont-Regular.ttf",30,nullptr,0);

    //Initialize all the variables needed
    Initializing();
    // EditorLoadDefault();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        //Updates everything
        Update();

        //Draws the frame
        DrawFrame();
    }

    //Unload eventually loaded resources
    UnloadResources();

    CloseWindow();
    return 0;
}