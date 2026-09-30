/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include <iostream>
#include <vector>
#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
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

    if(IsRunning){
      DrawCircle(10, 10, 5.0f, GREEN);
    }
    if(!IsRunning){
      DrawCircle(10, 10, 5.0f, RED);
    }

    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        if(grid[i][j] == 0){
          DrawRectangleLines(j*BLOCK, i*BLOCK, BLOCK, BLOCK, WHITE);
        }
        if(grid[i][j] == 1){
          DrawRectangleLines(j*BLOCK, i*BLOCK, BLOCK, BLOCK, WHITE);
          DrawRectangle(j*BLOCK + BLOCK/10, i*BLOCK + BLOCK/10, BLOCK - BLOCK / 5, BLOCK - BLOCK / 5, WHITE);
        }
      }
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true){
      int i = GetMouseX() / BLOCK;
      int j = GetMouseY() / BLOCK;
      if(grid[j][i] == 0){
        grid[j][i] = 1;
      }
      else{
        grid[j][i] = 0;
      }
    }

    if(IsKeyPressed(KEY_SPACE) == true) IsRunning = !IsRunning;

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
