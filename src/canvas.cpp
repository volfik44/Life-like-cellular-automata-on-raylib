#include "canvas.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void Pause(bool& IsRunning){
  if(IsKeyPressed(KEY_SPACE) == true) IsRunning = !IsRunning;
}

