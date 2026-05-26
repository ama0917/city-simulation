#ifndef CELL_H
#define CELL_H
using namespace std;

class Cell {
public:
    char zoneType;
    int population = 0;
    int pollution = 0;
    int workers = 0;
    int adjacentPopulation = 0;
	int adjacentGoods = 0;
	int adjacentPowerlines = 0;
	int neighborCount;
	int availableWorkers = 0;
	int availableGoods = 0;
    int xCoordinate, yCoordinate;
    bool operator==(const Cell& other) const;
};

#endif