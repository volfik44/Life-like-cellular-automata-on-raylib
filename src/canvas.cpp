#include "canvas.h"

void Pause(bool& IsRunning){
  if(IsKeyPressed(KEY_SPACE) == true) IsRunning = !IsRunning;
}
void FoV(const int& width, const int& height, Camera2D& camera){
  camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
  if (IsKeyDown(KEY_D) && camera.target.x <= width) camera.target.x += (5.0f / camera.zoom);
  if (IsKeyDown(KEY_A) && camera.target.x >= 0) camera.target.x -= (5.0f / camera.zoom);
  if (IsKeyDown(KEY_W) && camera.target.y >= 0) camera.target.y -= (5.0f / camera.zoom);
  if (IsKeyDown(KEY_S) && camera.target.y <= height) camera.target.y += (5.0f / camera.zoom);
  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    Vector2 world_before = GetScreenToWorld2D(GetMousePosition(), camera);
    if (wheel < 0 && camera.zoom > 0.6){
      camera.zoom *= 0.8;
    }
    if (wheel > 0 && camera.zoom < 10){ 
      camera.zoom *= 1.25;
    }
    Vector2 world_after = GetScreenToWorld2D(GetMousePosition(), camera);
    camera.target.x += world_before.x - world_after.x;
    camera.target.y += world_before.y - world_after.y;
  }
  if (camera.zoom < 0.6) camera.target = (Vector2){1000.0f, 1000.0f};
}



