#pragma once

#include "../core/editor.h"
#include "../settings/config.h"

void Editor::DrawTabLimits() {
    DrawRectangleLines(config.windowPadding, config.windowPadding, GetScreenWidth() - config.windowPadding * 2,
                       GetScreenHeight() - config.windowPadding * 2,PURPLE);
}

void Editor::DrawDebugLines() {
    int gridRows = GetScreenHeight() / config.gridHeight;
    int gridCols = GetScreenWidth() / config.gridWidth;
    //Draws debug grid
    if (config.DebugMode) {
        for (int i = 0; i < gridCols; i++) {
            DrawRectangleLines(
                i * config.gridWidth + config.windowPadding,
                config.windowPadding,
                2,
                GetScreenHeight() - config.windowPadding * 2,
                PURPLE);
        }

        for (int i = 0; i < gridRows + 1; i++) {
            DrawRectangleLines(
                config.windowPadding,
                i * config.verticalLineSpacing + i * config.gridHeight + config.windowPadding,
                GetScreenWidth() - config.windowPadding * 2,
                2,
                PURPLE);
            DrawRectangleLines(
                config.windowPadding,
                i * config.verticalLineSpacing + (i + 1) * config.gridHeight + config.windowPadding,
                GetScreenWidth() - config.windowPadding * 2,
                2,
                PURPLE);
        }
    }
}

void Editor::DrawSeparatorLine() {
    //Draws separating line
    DrawLine(config.windowPadding + config.gridWidth * 6, 0, config.windowPadding + config.gridWidth * 6,
             GetScreenHeight(),RED);
}

void Editor::DrawText() {
    // DrawTextEx(font, line.c_str(),
    //            {
    //                static_cast<float>(config.windowPadding) + config.gridWidth * 7,
    //                static_cast<float>(config.windowPadding)
    //            }
    //            , config.fontSize
    //            , config.spacing,RED);

    // for (int i=0;i<lineCounter;i++) {
    //     DrawTextEx(font,line.at(i).c_str(),{
    //         (float)config.windowPadding+ config.gridWidth*7,
    //         (float)config.windowPadding+config.gridHeight*i+config.verticalLineSpacing*i},
    //         config.fontSize,
    //         0,
    //         RED);
    // }
}

void Editor::DrawLineNumber() {
    //Draws line number
    for (int i = 0; i < lineCounter; i++) {
        float posX = config.windowPadding + config.gridWidth * 5; //*6
        float posY = i * config.gridHeight + config.windowPadding + i * config.verticalLineSpacing;

        std::string lineText = std::to_string(i + 1);

        Vector2 size = MeasureTextEx(font, lineText.c_str(), 30, 0);

        DrawTextEx(font, lineText.c_str(), {posX - size.x, posY}, config.fontSize, config.spacing, config.textColor);

        if (posY >= GetScreenHeight() - config.windowPadding * 2) {
            break;
        }
    }
}

void Editor::DrawInsertMode() {
    if (config.InsertMode) {
        DrawTextEx(font, "Insert mode", {1100, 600}, config.fontSize, config.spacing,RED);
    }
}
