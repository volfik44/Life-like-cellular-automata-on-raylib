#include "cells.h"
#include "raylib.h"
#include <iostream>
#include <vector>

void DrawCells(int rows, int cols, int BLOCK, std::vector<std::vector<int>>& grid){
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
} 
