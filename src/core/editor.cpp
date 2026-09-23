#include "editor.h"

void Editor::Initializing() {
    //Loads font at startup
    font = LoadFontEx("../../fonts/0xProtoNerdFont-Regular.ttf", 30, nullptr, 0);

    config.gridWidth = MeasureTextEx(font, "A", 30, 0).x;
    config.gridHeight = MeasureTextEx(font, "A", 30, 0).y;
}

void Editor::Update() {

    HandleInsertMode();
    HandleTyping();
    HandleDebugLines();

    // HandleNewLine();
    // HandleBackspace();
    // HandleDeleteLine();
}

//Draws the frames
void Editor::DrawFrame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTabLimits();
    DrawDebugLines();
    DrawSeparatorLine();
    DrawText();
    DrawLineNumber();
    DrawInsertMode();


    EndDrawing();
}

//Unload resources
void Editor::UnloadResources() {
    UnloadFont(font);
}
