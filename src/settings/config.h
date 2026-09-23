#pragma once

#include "raylib.h"

class EditorConfig {
public:

    bool DebugMode;
    bool InsertMode;

    int windowPadding;
    int verticalLineSpacing;

    int gridWidth{};
    int gridHeight{};

    float fontSize;
    float spacing;

    Color textColor{};
    float spaceBetweenChar;

    EditorConfig() {

        DebugMode=false;
        InsertMode=false;

        windowPadding=20;

        verticalLineSpacing=5;

        spacing=0;

        fontSize=30;

        textColor=BLACK;

        spaceBetweenChar=5;
    }
};