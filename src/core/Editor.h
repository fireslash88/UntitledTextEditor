#pragma once

#include "../settings/config.h"
#include "TextBuffer.h"
#include "raylib.h"

class Editor {

public:
    const int MaxLines=19;

private:
    EditorConfig config;

    TextBuffer text;

    Font font = {};

public:
    void Initializing();
    void Update();
    void DrawFrame();
    void UnloadResources();

private:
    // This is used to declare the controls of the editor.
    // Defined in EditorControls.cpp

    void HandleInsertMode();

    void HandleTyping();
    void HandleNewLine();
    //void HandleDeleteLine();
    void HandleBackspace();
    void HandleTab();
    void HandleCursorMovement();

    void HandleDebugMode();


    // Drawing functions
    // Defined in UIDraw.cpp
    void DrawTabLimits();
    void DrawSeparatorLine();
    void DrawFileText();
    void DrawLineNumber();
    void DrawCursor();
    void DrawCursorPosition();

    // For debugging
    // Defined in UIDrawDebug.cpp
    void DrawDebugLines();
    void DrawDebugInfo();
};