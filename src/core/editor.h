#pragma once

#include "../settings/config.h"
#include "textbuffer.h"
#include "raylib.h"

class Editor {

public:
    const int MaxLines=19;

private:
    EditorConfig config;
    TextBuffer text;

    Font font = {};

    // Vector2 cursorPosition={.x=0.0,.y=0.0};

    // std::string line;
    // std::vector<std::string> line ={"This is a test!"};

    int letterCount=0; //Why did I add this?..

    int lineCounter=1; //To move into a Text manager class

public:
    void Initializing();
    void Update();
    void DrawFrame();
    void UnloadResources();

private:
    //This is used to declare the controls of the editor.
    // Defined in EditorControls.cpp
    void HandleDebugLines();

    void HandleNewLine();
    void HandleDeleteLine();
    void HandleInsertMode();
    void HandleTyping();
    void HandleBackspace();


    //Drawing functions
    // Defined in UIDraw.cpp
    void DrawTabLimits();
    void DrawDebugLines();
    void DrawSeparatorLine();
    void DrawText();
    void DrawLineNumber();
    void DrawInsertMode();
};