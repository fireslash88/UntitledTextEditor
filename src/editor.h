#pragma once

#include <vector>
#include <string>
#include "raylib.h"

void Initializing();
void Update();
void DrawFrame();
void UnloadResources();

inline Font font;

// struct Cursor {
//     int cursorLine=0;
//     int cursorColumn=0;
// };
//
// inline Cursor cursor;

inline bool insertMode=false;

inline int letterCount=0;

inline struct Text {
    int lineCounter=1;
}text;

inline std::string line;