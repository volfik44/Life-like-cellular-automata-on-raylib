#include "canvas.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void Pause(bool& IsRunning){
  if(IsKeyPressed(KEY_SPACE) == true) IsRunning = !IsRunning;
  if(IsRunning){
    DrawCircle(10, 10, 5.0f, GREEN);
  }
  if(!IsRunning){
    DrawCircle(10, 10, 5.0f, RED);
  }
}
