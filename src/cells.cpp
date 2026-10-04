#include "cells.h"
#include "raylib.h"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <cmath>

void DrawCells(int rows, int cols, int BLOCK, const std::set<std::pair<int, int>>& alive){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(!alive.count({i, j})){
        DrawRectangleLines(j*BLOCK, i*BLOCK, BLOCK, BLOCK, GREEN);
      }
      if(alive.count({i, j})){
        DrawRectangleLines(j*BLOCK, i*BLOCK, BLOCK, BLOCK, GREEN);
        DrawRectangle(j*BLOCK + BLOCK/10, i*BLOCK + BLOCK/10, BLOCK*0.8, BLOCK*0.8,  GREEN);
      }
    }
  }
}

void ClickCell(int BLOCK, Camera2D camera, std::set<std::pair<int, int>>& alive){
  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true){
    Vector2 world = GetScreenToWorld2D(GetMousePosition(), camera);
    int i = world.x / BLOCK;
    int j = world.y / BLOCK;
    if(alive.count({j, i})) {
      alive.erase({j, i});
    }
    else {
      alive.insert({j, i});
    }
  }
}

void UpdateCells(bool IsRunning, float& timer, float step, int rows, int cols, std::set<std::pair<int, int>>& alive, std::map<std::pair<int, int>, int>& NeighborCount){
  if(IsRunning == true){
    timer = timer + GetFrameTime();
    if(timer >= step){
      for(const auto& cell : alive){
        for(int i = -1; i <= 1; i++){
          for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) NeighborCount[{cell.first, cell.second}];
            else NeighborCount[{cell.first + i, cell.second + j}]++;
          }
        }
      }
      for(const auto& [cell, n] : NeighborCount){
        if(alive.count(cell) == 1){
          if(n < 2 || n > 3) alive.erase(cell);
          if(n == 2 || n == 3) continue;
        } 
        if(alive.count(cell) == 0){
          if(n == 3) alive.insert(cell);
        }
        if(alive.count(cell) == 1 && (cell.first < 0 || cell.first >= cols || cell.second < 0 || cell.second >= rows)){
          alive.erase(cell);
        }
      }
      NeighborCount.clear();
      timer = 0.0f;
    }
  }
}


