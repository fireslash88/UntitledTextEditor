#include "textbuffer.h"

void TextBuffer::InsertText(char character) {
    lines.at(cursorLine).insert(
        cursorColumn,
        1,
        character);
    cursorColumn++;
}

void TextBuffer::NewLine() {

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
