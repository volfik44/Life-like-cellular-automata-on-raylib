#pragma once
#include <iostream>
#include <vector>

void DrawCells(int rows, int cols, int BLOCK, const std::vector<std::vector<int>>& grid);

void ClickCell(int BLOCK, std::vector<std::vector<int>>& grid);
