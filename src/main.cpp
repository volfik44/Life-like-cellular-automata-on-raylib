#include <iostream>
#include <vector>
#include "raylib.h"
#include "resource_dir.h"
#include "cells.h"
#include "canvas.h"

const int BLOCK = 20;

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);

	InitWindow(800, 600, "Game of Life");

	SearchAndSetResourceDir("resources");
  
  ShowCursor();
  EnableCursor();
  
  int width = 1920;
  int height = 1080;
  int rows = height / BLOCK + 1;
  int cols = width / BLOCK + 1;

  float step = 0.1f;
  float timer = 0.0f;

  bool IsRunning = false;

  std::vector<std::vector<int>> grid(rows, std::vector<int>(cols)); 
  std::vector<std::vector<int>> next_grid(rows, std::vector<int>(cols));

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

    DrawCells(rows, cols, BLOCK, grid);

    Pause(IsRunning);

    ClickCell(BLOCK, grid);

    if(IsRunning == true){
      timer = timer + GetFrameTime();
      if(timer >= step){
        for(int i = 1; i < rows - 1; i++){
          for(int j = 1; j < cols - 1; j++){
            int alive = 0;
            for(int m = 0; m <= 2; m++){
              for(int n = 0; n <= 2; n++){
                if(m == 1 && n == 1){
                  continue;
                }
                else if(grid[i - 1 + m][j - 1 + n] == 1){
                  alive++;
                }
              }
            }
            if(grid[i][j] == 1){
              if(alive < 2) next_grid[i][j] = 0;
              if(alive == 2 || alive == 3) next_grid[i][j] = 1;
              if(alive > 3) next_grid[i][j] = 0;
            }
            if(grid[i][j] == 0){
              if(alive == 3) next_grid[i][j] = 1;
            }
          }
        }
        for(int i = 1; i < rows - 1; i++){
          for(int j = 1; j < cols - 1; j++){
            grid[i][j] = next_grid[i][j];
          }
        }

        timer = 0.0f;
      }
    }

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
