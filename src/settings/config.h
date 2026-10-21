#pragma once

#include "raylib.h"

class EditorConfig {
public:

    bool debugLines;
    bool debugInfo;

    bool insertMode;

    int windowPadding;
    int verticalLineSpacing;

    int gridWidth{};
    int gridHeight{};

    float fontSize;
    float spacing;

    Color textColor{};
    float spaceBetweenChar;

    EditorConfig() {

        debugLines=false;
        debugInfo=false;

        insertMode=false;

        windowPadding=20;

        verticalLineSpacing=5;
        spacing=0;
        fontSize=30;
        spaceBetweenChar=5;

        textColor=BLACK;
    }
};