#include "Editor.h"

void Editor::Initializing() {
    //Loads font at startup
    font = LoadFontEx("../../fonts/0xProtoNerdFont-Regular.ttf", 30, nullptr, 0);

    config.gridWidth = MeasureTextEx(font, "A", 30, 0).x;
    config.gridHeight = MeasureTextEx(font, "A", 30, 0).y;
}

void Editor::Update() {

    HandleInsertMode();

    HandleTyping();
    HandleNewLine();
    HandleBackspace();
    HandleTab();
    HandleDebugMode();
    HandleCursorMovement();

    HandleLoadingFile();
    HandleSavingFile();
}

//Draws the frames
void Editor::DrawFrame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    //Main UI, WIP(?)
    DrawButtons();
    DrawMenuLine();
    DrawFileTreePanel();
    DrawCodePanel();
    DrawCursorPositionPanel();
    // DrawFileTab();

    DrawLineNumber();
    DrawLineSeparator();
    DrawFileText();
    DrawCursor();
    DrawCursorPosition();

    //UI for debugging
    DrawDebugLines();
    DrawDebugInfo();

    EndDrawing();
}

//Unload resources
void Editor::UnloadResources() {
    UnloadFont(font);

}
