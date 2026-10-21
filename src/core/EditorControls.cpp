#include <iostream>

#include "Editor.h"

// void Editor::HandleDeleteLine() {
//     // Delete line TODO: to fix after implementing the text buffer.
//     if ((IsKeyPressed(KEY_BACKSPACE) | IsKeyPressedRepeat(KEY_BACKSPACE)) && lineCounter > 1) {
//         lineCounter--;
//     }
// }

void Editor::HandleInsertMode() {
    // Activate insert mode
    if (IsKeyPressed(KEY_LEFT_SHIFT)) {
        config.insertMode = !config.insertMode;
        // std::cout<<("Insert mode activated \n");
    }
}

void Editor::HandleTyping() {
    // Logic that handles typing
    if (config.insertMode) {
        int key = GetCharPressed();

        while (key > 0) {
            if (key >= 32 && key <= 125) {
                text.InsertText(static_cast<char>(key));
            }
            key = GetCharPressed();
        }
    }
}

void Editor::HandleNewLine() {
    if (IsKeyPressed(KEY_ENTER) | IsKeyPressedRepeat(KEY_ENTER)) {
        text.NewLine();
    }
}

void Editor::HandleBackspace() {
    //Deletes characters
    if (IsKeyPressed(KEY_BACKSPACE) | IsKeyPressedRepeat(KEY_BACKSPACE)) {
        text.Backspace();
    }
}

void Editor::HandleTab() {
    if (IsKeyPressed(KEY_TAB)) {
        text.InsertTab();
    }
}

void Editor::HandleCursorMovement() {
    if (IsKeyPressed(KEY_LEFT) | IsKeyPressedRepeat(KEY_LEFT)) {
        text.MoveCursorLeft();
    }
    if (IsKeyPressed(KEY_RIGHT) | IsKeyPressedRepeat(KEY_RIGHT)) {
        text.MoveCursorRight();
    }
    if (IsKeyPressed(KEY_UP) | IsKeyPressedRepeat(KEY_UP)) {
        text.MoveCursorUp();
    }
    if (IsKeyPressed(KEY_DOWN) | IsKeyPressedRepeat(KEY_DOWN)) {
        text.MoveCursorDown();
    }
}

void Editor::HandleDebugMode() {
    //Activate or disables debug mode
    if (IsKeyPressed(KEY_F1)) {
        config.debugLines = !config.debugLines;
    }
    if (IsKeyPressed(KEY_F2)) {
        config.debugInfo = !config.debugInfo;
    }
}