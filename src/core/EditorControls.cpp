#include <iostream>

#include "editor.h"

// void Editor::HandleNewLine() {
//     // Add line TODO: to fix after implementing the text buffer.
//     if (IsKeyPressed(KEY_ENTER) | IsKeyPressedRepeat(KEY_ENTER) && lineCounter!=MaxLines) {
//         lineCounter++;
//         line.resize(lineCounter);
//     }
// }
//
// void Editor::HandleDeleteLine() {
//     // Delete line TODO: to fix after implementing the text buffer.
//     if ((IsKeyPressed(KEY_BACKSPACE) | IsKeyPressedRepeat(KEY_BACKSPACE)) && lineCounter > 1) {
//         lineCounter--;
//     }
// }

void Editor::HandleDebugLines() {
    //Activate or disables debug mode
    if (IsKeyPressed(KEY_D)) {
        config.DebugMode = !config.DebugMode;
    }
}

void Editor::HandleInsertMode() {
    // Activate insert mode
    if (IsKeyPressed(KEY_LEFT_SHIFT)) {
        config.InsertMode = !config.InsertMode;
        std::cout<<("Insert mode activated \n");
    }
}

void Editor::HandleTyping() {
    // Logic that handles typing
    if (config.InsertMode) {
        int key = GetCharPressed();

        while (key > 0) {
            if (key >= 32 && key <= 125) {
                text.InsertText(static_cast<char>(key));
                //TODO: Check if += is better. on Stackoverflow said it's better
            }
            key = GetCharPressed();
        }
    }
}

// void Editor::HandleBackspace() {
//     //Deletes characters
//     if ((IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) && !line.empty()) {
//         line.pop_back();
//     }
// }

