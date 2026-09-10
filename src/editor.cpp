#include "editor.h"
#include "raylib.h"
#include "config.h"

//Initiate game variables;
void Initializing() {
    EditorLoadDefault();
}

//Update the
void Update() {
    if (IsKeyPressed(KEY_ENTER) | IsKeyPressedRepeat(KEY_ENTER)) {
        text.lineCounter++;
    }

    // if ((IsKeyPressed(KEY_BACKSPACE) | IsKeyPressedRepeat(KEY_BACKSPACE))&& text.lineCounter>1) {
    //     text.lineCounter--;
    // }

    if (IsKeyPressed(KEY_D)) {
        //TODO: need to clean it like the insert mode. feeling lazy.
        if (config.DebugMode) {
            config.DebugMode=false;
        }
        else {
            config.DebugMode=true;
        }
    }

    if (IsKeyPressed(KEY_LEFT_SHIFT)) {
        insertMode=!insertMode;
    }

    if (insertMode) {

        int key=GetCharPressed();

        while (key>0) {
            if (key>=32 && key<=125) {
                line.push_back(static_cast<char>(key)); //TODO: Check if += is better. on Stackoverflow said it's better
            }
            key=GetCharPressed();
        }
    }

    if ((IsKeyPressed(KEY_BACKSPACE)|| IsKeyPressedRepeat(KEY_BACKSPACE)) && !line.empty()) {
        line.pop_back();
    }

}

//Draws the frames
void DrawFrame() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangleLines(config.windowPadding,config.windowPadding,GetScreenWidth()-config.windowPadding*2,GetScreenHeight()-config.windowPadding*2,PURPLE);

    DrawTextEx(font,line.c_str(),{(float)config.windowPadding+config.gridWidth*6,(float)config.windowPadding},config.fontSize,config.spacing,RED);

    int gridRows=GetScreenHeight() / config.gridHeight;
    int gridCols=GetScreenWidth() / config.gridWidth;

    //Draws debug grid
    if (config.DebugMode) {
        for (int i=0;i<gridCols;i++) {
            DrawRectangleLines(
                i*config.gridWidth+config.windowPadding,
                config.windowPadding,
                2,
                GetScreenHeight()-config.windowPadding*2,
                PURPLE);
        }

        for (int i=0;i<gridRows + 1;i++) {
            DrawRectangleLines(
                config.windowPadding,
                i * config.verticalLineSpacing + i*config.gridHeight + config.windowPadding,
                GetScreenWidth() - config.windowPadding*2,
                2,
                PURPLE);
            DrawRectangleLines(
               config.windowPadding,
               i * config.verticalLineSpacing + (i+1)* config.gridHeight + config.windowPadding,
               GetScreenWidth() - config.windowPadding*2,
               2,
               PURPLE);

        }
    }

    DrawLine(config.windowPadding+config.gridWidth*6,0,config.windowPadding+config.gridWidth*6,GetScreenHeight(),RED);

    for (int i=0;i<text.lineCounter;i++) {
        float posX=config.windowPadding+config.gridWidth*5; //*6
        float posY= i*config.gridHeight + config.windowPadding + i*config.verticalLineSpacing;

        std::string lineText=std::to_string(i+1);

        Vector2 size=MeasureTextEx(font,lineText.c_str(),30,0);

        DrawTextEx(font,lineText.c_str(),{posX-size.x,posY},config.fontSize,config.spacing,config.textColor);

        if (posY>= GetScreenHeight()-config.windowPadding*2) {
            break;
        }
    }

    if (insertMode) {
        DrawText("Insert mode",1100,600,20,RED);
    }

    EndDrawing();
}

//Unload resources (useless for now)
void UnloadResources() {
    UnloadFont(font);
}