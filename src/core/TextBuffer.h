#pragma once

#include <string>
#include <vector>

class TextBuffer {
public:

    TextBuffer() {
        cursorLine=0;
        cursorColumn=0;

        lines.emplace_back();
    }

    // Basic text modification
    void InsertText(char character);

    void NewLine();
    void Backspace();
    void InsertTab();

    // Cursor movement
    void MoveCursorLeft();
    void MoveCursorRight();
    void MoveCursorUp();
    void MoveCursorDown();

    // Gets the current line
    std::string GetLine(std::size_t line);

    // Gets the count of the lines
    std::size_t GetLineCounter();

    // Gets cursor position
    std::size_t GetCursorLine();
    std::size_t GetCursorColumn();

private:
    // Vector of strings
    std::vector<std::string> lines;

    std::size_t cursorLine;
    std::size_t cursorColumn;
};
