#ifndef REGIONUTILS_H
#define REGIONUTILS_H

#include <vector>
#include "Cell.h"
#include "simulationConfig.h"

using namespace std;

vector<vector<Cell>> readRegion(vector<vector<Cell>>& zone);

void displayRegion(const vector<vector<Cell>>& zone);

void displayPollution(const vector<vector<Cell>>& Zone);

bool simulateResidential(vector<vector<Cell>>& zone, int& availableWorkers);

bool simulateIndustrial(vector<vector<Cell>>& zone, int& availableWorkers);

bool simulateCommercial(vector<vector<Cell>>& zone, int& availableWorkers, int& availableGoods);

void simulateCityDevelopment(vector<vector<Cell>>& zone, SimulationConfig config);

void examineRegion(const vector<vector<Cell>>& zone, int startX, int startY, int endX, int endY);

bool compareCells(const Cell& cell1, const Cell& cell2);

void checkAdjacenctPowerlines(vector<vector<Cell>>& zone);

void checkAdjacentPopulation(vector<vector<Cell>>& zone);
#endif