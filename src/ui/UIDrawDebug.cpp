#include "../core/Editor.h"
#include "../settings/config.h"

void Editor::DrawDebugLines() {
    int gridRows = GetScreenHeight() / config.gridHeight;
    int gridCols = GetScreenWidth() / config.gridWidth;
    //Draws debug grid
    if (config.debugLines) {
        for (int i = 0; i < gridCols; i++) {
            DrawRectangleLines(
                i * config.gridWidth + config.windowPadding,
                config.windowPadding,
                2,
                GetScreenHeight() - config.windowPadding * 2,
                GRAY);
        }

        for (int i = 0; i < gridRows + 1; i++) {
            DrawRectangleLines(
                config.windowPadding,
                i * config.verticalLineSpacing + i * config.gridHeight + config.windowPadding,
                GetScreenWidth() - config.windowPadding * 2,
                2,
                GRAY);
            DrawRectangleLines(
                config.windowPadding,
                i * config.verticalLineSpacing + (i + 1) * config.gridHeight + config.windowPadding,
                GetScreenWidth() - config.windowPadding * 2,
                2,
                GRAY);
        }
    }
}

void Editor::DrawDebugInfo() {
    if (config.debugInfo) {
        DrawText(TextFormat("cursorColumn %i" , text.GetCursorColumn()),1000,500,20,RED);
        DrawText(TextFormat("cursorLine %i" , text.GetCursorLine()),1000,520,20,RED);
        DrawText(TextFormat("fontSize %.00f" , config.fontSize),1000,540,20,RED);
    }
}