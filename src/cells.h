#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include <set>
#include <utility>
#include <map>
#include <cmath>

void InitDraw(const int& rows, const int& cols, const int& BLOCK, const std::set<std::pair<int, int>>& alive);

void DrawCells(const int& BLOCK, const std::set<std::pair<int, int>>& alive);

void ClickCell(const int& BLOCK, const int& rows, const int& cols, Camera2D camera, std::set<std::pair<int, int>>& alive);

void UpdateCells(bool IsRunning, float& timer, float step, int rows, int cols, std::set<std::pair<int, int>>& alive, std::map<std::pair<int, int>, int>& NeighborCount);
