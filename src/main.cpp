#include <iostream>
#include <vector>
#include "raylib.h"
#include "resource_dir.h"
#include "cells.h"
#include "canvas.h"


int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

	InitWindow(800, 600, "Game of Life");

	SearchAndSetResourceDir("resources");
  
  ShowCursor();
  EnableCursor();
  
  int BLOCK = 20;
  int width = 5000;
  int height = 5000;
  int rows = height / BLOCK + 1;
  int cols = width / BLOCK + 1;

  float step = 0.01f;
  float timer = 0.0f;

  bool IsRunning = false;

  std::vector<std::vector<int>> grid(rows, std::vector<int>(cols)); 
  std::vector<std::vector<int>> next_grid(rows, std::vector<int>(cols));

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

    DrawCells(rows, cols, BLOCK, grid);

    Zoom(BLOCK);

    ClickCell(BLOCK, grid, next_grid);

    Pause(IsRunning);

    UpdateCells(IsRunning, timer, step, rows, cols, grid, next_grid);
		
    EndDrawing();
	}

	CloseWindow();
	return 0;
}
