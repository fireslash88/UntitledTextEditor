#include "../core/Editor.h"
#include "src/raygui.h"
#include "raylib.h"

void Editor::DrawButtons() {
    Vector2 anchor03={10,10};
    GuiButton((Rectangle){ anchor03.x + 8, anchor03.y, 80, 24 }, "File");
    GuiButton((Rectangle){ anchor03.x + 96, anchor03.y, 80, 24 }, "View");
    GuiButton((Rectangle){ anchor03.x + 184, anchor03.y , 80, 24 }, "Window");
}

void Editor::DrawMenuLine() {
    GuiLine((Rectangle){ anchor01.x + 0, anchor01.y + 56, static_cast<float>(GetScreenWidth()), 16 }, NULL);
}

void Editor::DrawFileTreePanel() {
    GuiPanel((Rectangle){ anchor01.x + 0, anchor01.y + 64, 169, static_cast<float>(GetScreenHeight()) }, NULL);
}

void Editor::DrawCodePanel() {
    GuiPanel((Rectangle){ anchor01.x + 168, anchor01.y + 64, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) }, NULL);
}

void Editor::DrawCursorPositionPanel() {
    GuiPanel((Rectangle){ anchor01.x + static_cast<float>(GetScreenWidth()-240), anchor01.y + static_cast<float>(GetScreenHeight()-48), 240, 48 }, NULL);
}

// void Editor::DrawFileTab() {
//     int tabActive=0;
//     DrawText("TEST",500,500,30,RED);
//     GuiTabBar({anchor02.x,anchor02.y+20,50,30},"Tab1;Tab2;Tab3",NULL,&tabActive);
// }

void Editor::DrawLineNumber() {

    for (std::size_t i = 0; i < text.GetLineCounter(); i++) {
        float posX = anchor02.x + config.gridWidth * 5; //*6
        float posY = i * config.gridHeight + anchor02.y + i * config.verticalLineSpacing;

        std::string lineText = std::to_string(i + 1);

        Vector2 size = MeasureTextEx(font, lineText.c_str(), 30, 0);

        DrawTextEx(font, lineText.c_str(), {posX - size.x, posY}, config.fontSize, config.spacing, config.textColor);

        // if (posY >= GetScreenHeight() - anchor02.y * 2) {
        //     break;
        // }
    }
}

void Editor::DrawLineSeparator() {
    DrawLine(anchor02.x + config.gridWidth * 6, anchor02.y, anchor02.x + config.gridWidth * 6,
             GetScreenHeight(),LIGHTGRAY);
}

void Editor::DrawFileText() {

    for (std::size_t i=0; i<text.GetLineCounter();i++) {
        DrawTextEx(font,text.GetLine(i).c_str(),{
        anchor02.x+config.gridWidth*6,
        anchor02.y+config.gridHeight*i+config.verticalLineSpacing*i},
            config.fontSize,
            0,
            RED
        );
    }
}

void Editor::DrawCursor() {

    Color cursorColor = {
        47,129,247,120
    };

    DrawRectangle(
        text.GetCursorColumn() * config.gridWidth + anchor02.x + config.gridWidth*6,
        text.GetCursorLine() * config.gridHeight + text.GetCursorLine()*config.verticalLineSpacing+anchor02.y,
        config.gridWidth, config.gridHeight, cursorColor
        );
}

void Editor::DrawCursorPosition() {
    DrawTextEx(font,TextFormat("%zu:%zu",text.GetCursorLine()+1,text.GetCursorColumn()+1),{anchor01.x+static_cast<float>(GetScreenWidth()-240)+60,anchor01.y + static_cast<float>(GetScreenHeight()-48)+12},30,0,RED);
}

