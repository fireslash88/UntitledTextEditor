#include "textbuffer.h"

void TextBuffer::InsertText(char character) {
    lines.at(cursorLine).insert(
        cursorColumn,
        1,
        character);
    cursorColumn++;
}

void TextBuffer::NewLine() {
    std::string& currentLine = lines.at(cursorLine);

    std::string newLine = currentLine.substr(cursorColumn);

    currentLine.erase(cursorColumn);

    lines.insert(
        lines.begin() + cursorLine + 1,
        newLine
        );

    cursorLine++;
    cursorColumn=0;
}

void TextBuffer::Backspace() {
    if (cursorColumn>0) {
        lines.at(cursorLine).erase(cursorColumn-1,1);
        cursorColumn--;

        return;
    }

    if (cursorLine>0) {
        std::size_t previousLineLength = lines.at(cursorLine-1).size();

        lines.at(cursorLine-1) += lines.at(cursorLine);

        lines.erase(lines.begin()+ cursorLine);

        cursorLine--;

        cursorColumn = previousLineLength;
    }
}

void TextBuffer::InsertTab() {
    lines.at(cursorLine).insert(
        cursorColumn,
        4,
        '\t'
        );
    cursorColumn+=4;
}

void TextBuffer::MoveCursorLeft() {
    if (cursorColumn>0) {
        cursorColumn--;
        return;
    }

    if (cursorLine>0) {
        cursorLine--;
        cursorColumn=lines.at(cursorLine).size();
    }
}

void TextBuffer::MoveCursorRight() {
    if (cursorColumn<lines.at(cursorLine).size()) {
        cursorColumn++;
        return;
    }
    if (cursorLine+1 < lines.size()) {
        cursorLine++;
        cursorColumn=0;
    }
}

void TextBuffer::MoveCursorUp() {
    if (cursorLine>0) {
        cursorLine--;
        cursorColumn=lines.at(cursorLine).size();
    }
}

void TextBuffer::MoveCursorDown() {
    if (cursorLine+1<lines.size()) {
        cursorLine++;
        cursorColumn=lines.at(cursorLine).size();
    }
}

std::string TextBuffer::GetLine(std::size_t line) {
    return lines.at(line);
}

std::size_t TextBuffer::GetLineCounter() {
    return lines.size();
}

std::size_t TextBuffer::GetCursorLine() {
    return cursorLine;
}

std::size_t TextBuffer::GetCursorColumn() {
    return cursorColumn;
}
