#include "cells.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void DrawCells(int rows, int cols, int BLOCK, const std::vector<std::vector<int>>& grid){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(grid[i][j] == 0){
        DrawRectangleLines(j*BLOCK, i*BLOCK, BLOCK, BLOCK, GREEN);
      }
      if(grid[i][j] == 1){
        DrawRectangleLines(j*BLOCK, i*BLOCK, BLOCK, BLOCK, GREEN);
        DrawRectangle(j*BLOCK + BLOCK/10, i*BLOCK + BLOCK/10, BLOCK - BLOCK / 5, BLOCK - BLOCK / 5, GREEN);
      }
    }
  }
}

void ClickCell(int BLOCK, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& next_grid){
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true){
    int i = GetMouseX() / BLOCK;
    int j = GetMouseY() / BLOCK;
    if(grid[j][i] == 0){
      grid[j][i] = 1;
      next_grid[j][i] = 1;
    }
    else{
      grid[j][i] = 0;
      next_grid[j][i] = 0;
    }
  }
}
void UpdateCells(bool IsRunning, float& timer, float step, int rows, int cols, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& next_grid){
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
            else if (alive != 3) next_grid[i][j] = 0;
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
}
