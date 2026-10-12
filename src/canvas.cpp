#include "canvas.h"

void Pause(bool& IsRunning){
  if(IsKeyPressed(KEY_SPACE) == true) IsRunning = !IsRunning;
}
void FoV(Camera2D& camera){
  if (IsKeyDown(KEY_D)) camera.target.x += (5.0f / camera.zoom);
  if (IsKeyDown(KEY_A)) camera.target.x -= (5.0f / camera.zoom);
  if (IsKeyDown(KEY_W)) camera.target.y -= (5.0f / camera.zoom);
  if (IsKeyDown(KEY_S)) camera.target.y += (5.0f / camera.zoom);
  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    Vector2 world_before = GetScreenToWorld2D(GetMousePosition(), camera);
    if (wheel < 0 && camera.zoom > 0.1){
      camera.zoom *= 0.8;
    }
    if (wheel > 0 && camera.zoom < 10){ 
      camera.zoom *= 1.25;
    }
    Vector2 world_after = GetScreenToWorld2D(GetMousePosition(), camera);
    camera.target.x += world_before.x - world_after.x;
    camera.target.y += world_before.y - world_after.y;
  }
}


