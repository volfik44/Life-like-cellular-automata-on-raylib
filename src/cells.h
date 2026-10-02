#pragma once
#include <iostream>
#include <vector>

void DrawCells(int rows, int cols, int BLOCK, const std::vector<std::vector<int>>& grid);

void ClickCell(int BLOCK, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& next_grid);

void UpdateCells(bool IsRunning, float& timer, float step, int rows, int cols, std::vector<std::vector<int>>& grid, std::vector<std::vector<int>>& next_grid);
