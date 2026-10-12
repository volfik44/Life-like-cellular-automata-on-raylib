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

  int monitor = GetCurrentMonitor();
  int mon_width = GetMonitorWidth(monitor);
  int mon_height = GetMonitorHeight(monitor);

	InitWindow(1000, 1000, "Game of Life");

  Camera2D camera = {0};
  camera.target = (Vector2){1000.0f, 1000.0f};
  camera.offset = (Vector2){GetScreenWidth()/2.0f, GetScreenHeight()/2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

	SearchAndSetResourceDir("resources");
  
  ShowCursor();
  EnableCursor();
  
  int BLOCK = 10;
  int width = 2000;
  int height = 2000;
  int rows = height / BLOCK + 1;
  int cols = width / BLOCK + 1;
  int rule_b, rule_s;

  float step = 0.1f;
  float timer = 0.0f;

  bool IsRunning = false;

  std::set<std::pair<int, int>> alive;
  std::map<std::pair<int, int>, int> NeighborCount;

  RenderTexture2D gridTexture = LoadRenderTexture(cols*BLOCK, rows*BLOCK);

  BeginTextureMode(gridTexture);
  ClearBackground(BLACK);
  InitDraw(rows, cols, BLOCK, alive);
  EndTextureMode();

	while (!WindowShouldClose())
	{
    FoV(width, height, camera);

		BeginDrawing();

    BeginMode2D(camera);

    DrawTextureRec(gridTexture.texture, (Rectangle){0, 0, (float)gridTexture.texture.width, (float)-gridTexture.texture.height}, Vector2{0, 0}, WHITE);

		ClearBackground(BLACK);

    DrawCells(BLOCK, alive);

    Pause(IsRunning);

    ClickCell(BLOCK, rows, cols ,camera, alive);

    UpdateCells(IsRunning, timer, step, rows, cols, alive, NeighborCount);
		
    EndMode2D();

    EndDrawing();
	}

	CloseWindow();

  UnloadRenderTexture(gridTexture);

	return 0;
}
