#include "../core/Editor.h"
#include "../settings/config.h"

void Editor::DrawTabLimits() {
    DrawRectangleLines(config.windowPadding, config.windowPadding, GetScreenWidth() - config.windowPadding * 2,
                       GetScreenHeight() - config.windowPadding * 2,PURPLE);

}

void Editor::DrawSeparatorLine() {
    //Draws separating line
    DrawLine(config.windowPadding + config.gridWidth * 6, 0, config.windowPadding + config.gridWidth * 6,
             GetScreenHeight(),LIGHTGRAY);

}

void Editor::DrawFileText() {
    for (std::size_t i=0; i<text.GetLineCounter();i++) {
        DrawTextEx(font,text.GetLine(i).c_str(),{
        (float)config.windowPadding+ config.gridWidth*6,
            (float)config.windowPadding+config.gridHeight*i+config.verticalLineSpacing*i},
            config.fontSize,
            0,
            RED
        );
    }

}

void Editor::DrawLineNumber() {
    //Draws line number
    for (int i = 0; i < text.GetLineCounter(); i++) {
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

void Editor::DrawCursor() {
    Color cursorColor = {
        47,129,247,120
    };

    DrawRectangle(
        text.GetCursorColumn() * config.gridWidth + config.windowPadding + config.gridWidth*6,
        text.GetCursorLine() * config.gridHeight + text.GetCursorLine()*config.verticalLineSpacing+config.windowPadding,
        config.gridWidth, config.gridHeight, cursorColor
        );
}

void Editor::DrawCursorPosition() {
    DrawTextEx(font,TextFormat("%zu:%zu",text.GetCursorLine()+1,text.GetCursorColumn()+1),{1100,650},30,0,RED);
}
