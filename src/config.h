#pragma once

struct Config {
    bool DebugMode;
    int windowPadding;
    int verticalLineSpacing;

    int gridWidth;
    int gridHeight;

    int fontSize;
    int spacing;

    Color textColor;
    // inline float spaceBetweenChar=5;
};

inline Config config;

inline void EditorLoadDefault() {
    config.DebugMode=false;
    config.windowPadding=20;

    config.verticalLineSpacing=5;

    config.gridWidth=MeasureTextEx(font,"A",30,0).x;
    config.gridHeight=MeasureTextEx(font,"A",30,0).y;

    config.spacing=0;

    config.fontSize=30;

    config.textColor=BLACK;
}