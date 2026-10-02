#include "canvas.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void Pause(bool& IsRunning){
  if(IsKeyPressed(KEY_SPACE) == true) IsRunning = !IsRunning;
}

void Zoom(int& BLOCK){
  if(IsKeyPressed(KEY_MINUS) || IsKeyPressed(KEY_KP_SUBTRACT)){
    BLOCK = BLOCK*0.8;
  }
  if(IsKeyPressed(KEY_EQUAL) || IsKeyPressed(KEY_KP_ADD)){
    BLOCK = BLOCK*1.25;
  }
}
