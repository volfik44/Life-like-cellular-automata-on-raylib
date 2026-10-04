#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include "raylib.h"
#include "resource_dir.h"
#include "cells.h"
#include "canvas.h"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

	InitWindow(1920, 1080, "Game of Life");

  Camera2D camera = {0};
  camera.target = (Vector2){500.0f, 500.0f};
  camera.offset = (Vector2){960.0f, 540.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

	SearchAndSetResourceDir("resources");
  
  ShowCursor();
  EnableCursor();
  
  int BLOCK = 20;
  int width = 2000;
  int height = 2000;
  int rows = height / BLOCK + 1;
  int cols = width / BLOCK + 1;

  float step = 0.05f;
  float timer = 0.0f;

  bool IsRunning = false;

  std::set<std::pair<int, int>> alive;
  std::map<std::pair<int, int>, int> NeighborCount;

	while (!WindowShouldClose())
	{

    if (IsKeyDown(KEY_D)) camera.target.x += (5.0f / camera.zoom);
    if (IsKeyDown(KEY_A)) camera.target.x -= (5.0f / camera.zoom);
    if (IsKeyDown(KEY_W)) camera.target.y -= (5.0f / camera.zoom);
    if (IsKeyDown(KEY_S)) camera.target.y += (5.0f / camera.zoom);
    float wheel = GetMouseWheelMove();
    if (wheel != 0) {
      if (wheel < 0 && camera.zoom > 0.1) camera.zoom *= 0.8;
      if (wheel > 0 && camera.zoom < 10) camera.zoom *= 1.25;
    }
		BeginDrawing();

    BeginMode2D(camera);

		ClearBackground(BLACK);

    DrawCells(rows, cols, BLOCK, alive);
   
    Pause(IsRunning);
    
    ClickCell(BLOCK, camera, alive);
    
    UpdateCells(IsRunning, timer, step, rows, cols, alive, NeighborCount);
		
    EndMode2D();

    EndDrawing();
	}

	CloseWindow();
	return 0;
}
