#include "RegionUtilities.h"
#include <iostream>
#include <fstream>
#include <climits>
vector<vector<Cell>> readRegion(vector<vector<Cell>>& Zone) {
    ifstream regionFile("region1template.csv");
    
    char zoneType;
    int currentRowWidth = 0;
    int regionWidth = 0;
	vector<Cell> Row;
    if (!regionFile.is_open()) {
        cout << "Failed to open file" << endl;
        return Zone;
    }

    while (regionFile) {
        zoneType = regionFile.get();
        if (zoneType != ',' && zoneType != '\n') {
            Cell cell;
            cell.zoneType = zoneType;
            cell.population = 0;
            cell.pollution = 0;
            Row.push_back(cell);  // Add the cell to the current row
            currentRowWidth++;
        } else if (zoneType == '\n') {
            if (currentRowWidth > regionWidth) {
                regionWidth = currentRowWidth;
            }
            currentRowWidth = 0;
            Zone.push_back(Row);  // Start a new row
        }
    }

    regionFile.close();
    return Zone;
}

void displayRegion(const vector<vector<Cell>>& zone) {
    for (const auto& row : zone) {
        for (const auto& cell : row) {
            if (cell.population > 0) {
                cout << cell.population << " ";
            } else {
                cout << cell.zoneType << " ";
            }
        }
        cout << endl;  // Start a new line for each row
    }
}

void displayPollution(const vector<vector<Cell>>& Zone) 
{
    for (const auto& Row : Zone) 
	{
        for (const auto& cell : Row) 
		{
			if(cell.zoneType != ' ')
			{
            cout << " " << cell.zoneType;
			}			
			cout << "(" << cell.pollution << ")";
        }
        cout << endl;  // Start a new line for each row
    }
}

bool simulateResidential(vector<vector<Cell>>& zone, int& availableWorkers) 
{
     bool hasChange = false;
    vector<vector<Cell>> updatedZone = zone;
    int populationIncrease = 0;

    // check adjacent cells for population count
    checkAdjacentPopulation(zone);

    // Iterate over the cells in the residential zone
    for (int i = 0; i < zone.size(); ++i) {
        for (int j = 0; j < zone[i].size(); ++j) {
            if (zone[i][j].zoneType == 'R') {
                // Apply the rules based on the current cell's population and adjacent counts
                if (zone[i][j].population == 0 && zone[i][j].adjacentPowerlines >= 1) {
                    // ... other code ...

                    // Check if there are any conflicting cells that could grow and use available resources
                    bool canGrow = true;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;

                            // Ignore the current cell itself and out-of-bounds neighbors
                            if (ni == i && nj == j || ni < 0 || ni >= zone.size() || nj < 0 || nj >= zone[ni].size()) {
                                continue;
                            }

                            // Check if there is a conflicting cell that could grow and use available resources
                            const Cell& neighborCell = zone[ni][nj];
                            if (neighborCell.zoneType == 'R' && neighborCell.population == 0 && neighborCell.adjacentPowerlines >= 1 &&
                                compareCells(zone[i][j], neighborCell)) {
                                canGrow = false;
                                break;
                            }
                        }
                        if (!canGrow) {
                            break;
                        }
                    }

                    // Update the available workers only if the cell can grow
                    if (canGrow) {
                        zone[i][j].population += 1;
                        populationIncrease++;
                        hasChange = true;
                    }
                } else if (zone[i][j].population == 0 && zone[i][j].adjacentPopulation >= 1) {
                    // ... other code ...

                    // Check if there are any conflicting cells that could grow and use available resources
                    bool canGrow = true;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;

                            // Ignore the current cell itself and out-of-bounds neighbors
                            if (ni == i && nj == j || ni < 0 || ni >= zone.size() || nj < 0 || nj >= zone[ni].size()) {
                                continue;
                            }

                            // Check if there is a conflicting cell that could grow and use available resources
                            const Cell& neighborCell = zone[ni][nj];
                            if (neighborCell.zoneType == 'R' && neighborCell.population == 0 && neighborCell.adjacentPowerlines >= 1 &&
                                compareCells(zone[i][j], neighborCell)) {
                                canGrow = false;
                                break;
                            }
                        }
                        if (!canGrow) {
                            break;
                        }
                    }

                    // Update the available workers only if the cell can grow
                    if (canGrow) {
                        zone[i][j].population += 1;
                        populationIncrease++;
                        hasChange = true;
                    }
                } else if (zone[i][j].population == 1 && zone[i][j].adjacentPopulation >= 2) {
                    // ... other code ...

                    // Check if there are any conflicting cells that could grow and use available resources
                    bool canGrow = true;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;

                            // Ignore the current cell itself and out-of-bounds neighbors
                            if (ni == i && nj == j || ni < 0 || ni >= zone.size() || nj < 0 || nj >= zone[ni].size()) {
                                continue;
                            }

                            // Check if there is a conflicting cell that could grow and use available resources
                            const Cell& neighborCell = zone[ni][nj];
                            if (neighborCell.zoneType == 'R' && neighborCell.population == 0 && neighborCell.adjacentPowerlines >= 1 &&
                                compareCells(zone[i][j], neighborCell)) {
                                canGrow = false;
                                break;
                            }
                        }
                        if (!canGrow) {
                            break;
                        }
                    }

                    // Update the available workers only if the cell can grow
                    if (canGrow) {
                        zone[i][j].population += 1;
                        populationIncrease++;
                        hasChange = true;
                    }
                } else if (zone[i][j].population == 2 && zone[i][j].adjacentPopulation >= 4) {
                    // ... other code ...

                    // Check if there are any conflicting cells that could grow and use available resources
                    bool canGrow = true;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;

                            // Ignore the current cell itself and out-of-bounds neighbors
                            if (ni == i && nj == j || ni < 0 || ni >= zone.size() || nj < 0 || nj >= zone[ni].size()) {
                                continue;
                            }

                            // Check if there is a conflicting cell that could grow and use available resources
                            const Cell& neighborCell = zone[ni][nj];
                            if (neighborCell.zoneType == 'R' && neighborCell.population == 0 && neighborCell.adjacentPowerlines >= 1 &&
                                compareCells(zone[i][j], neighborCell)) {
                                canGrow = false;
                                break;
                            }
                        }
                        if (!canGrow) {
                            break;
                        }
                    }

                    // Update the available workers only if the cell can grow
                    if (canGrow) {
                        zone[i][j].population += 1;
                        populationIncrease++;
                        hasChange = true;
                    }
                } else if (zone[i][j].population == 3 && zone[i][j].adjacentPopulation >= 6) {
                    // ... other code ...

                    // Check if there are any conflicting cells that could grow and use available resources
                    bool canGrow = true;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;

                            // Ignore the current cell itself and out-of-bounds neighbors
                            if (ni == i && nj == j || ni < 0 || ni >= zone.size() || nj < 0 || nj >= zone[ni].size()) {
                                continue;
                            }

                            // Check if there is a conflicting cell that could grow and use available resources
                            const Cell& neighborCell = zone[ni][nj];
                            if (neighborCell.zoneType == 'R' && neighborCell.population == 0 && neighborCell.adjacentPowerlines >= 1 &&
                                compareCells(zone[i][j], neighborCell)) {
                                canGrow = false;
                                break;
                            }
                        }
                        if (!canGrow) {
                            break;
                        }
                    }

                    // Update the available workers only if the cell can grow
                    if (canGrow) {
                        zone[i][j].population += 1;
                        populationIncrease++;
                        hasChange = true;
                    }
                } else if (zone[i][j].population == 4 && zone[i][j].adjacentPopulation >= 8) {
                    // ... other code ...

                    // Check if there are any conflicting cells that could grow and use available resources
                    bool canGrow = true;
                    for (int di = -1; di <= 1; ++di) {
                        for (int dj = -1; dj <= 1; ++dj) {
                            int ni = i + di;
                            int nj = j + dj;

                            // Ignore the current cell itself and out-of-bounds neighbors
                            if (ni == i && nj == j || ni < 0 || ni >= zone.size() || nj < 0 || nj >= zone[ni].size()) {
                                continue;
                            }

                            // Check if there is a conflicting cell that could grow and use available resources
                            const Cell& neighborCell = zone[ni][nj];
                            if (neighborCell.zoneType == 'R' && neighborCell.population == 0 && neighborCell.adjacentPowerlines >= 1 &&
                                compareCells(zone[i][j], neighborCell)) {
                                canGrow = false;
                                break;
                            }
                        }
                        if (!canGrow) {
                            break;
                        }
                    }

                    // Update the available workers only if the cell can grow
                    if (canGrow) {
                        zone[i][j].population += 1;
                        populationIncrease++;
                        hasChange = true;
                    }
                }
            }
        }
    }

    // Calculate available workers for industrial and commercial zones
    availableWorkers += populationIncrease;
    return hasChange;
}

bool simulateIndustrial(vector<vector<Cell>>& zone,int& availableWorkers, int& availableGoods)
{
    
	bool hasChange = false;
	int goodsIncrease = 0;
    // Iterate over the cells in the industrial zone
    for (int i = 0; i < zone.size(); ++i) {
        for (int j = 0; j < zone[i].size(); ++j) {
            Cell& currentCell = zone[i][j];

            // Check the zone type and population of the current cell
            if (currentCell.zoneType == 'I') {
                
                currentCell.adjacentPopulation = 0;

                // Calculate the number of adjacent powerlines and neighboring cells with population
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;

                        // Ignore the current cell itself
                        if (ni == i && nj == j) {
                            continue;
                        }

                        // Check if the neighbor is within the region bounds
                        if (ni >= 0 && ni < zone.size() && nj >= 0 && nj < zone[ni].size()) {
                            if (zone[ni][nj].population >= 1) {
                                currentCell.adjacentPopulation++;
                            }
                        }
                    }
                }

                // Apply the rules based on the current cell's population, adjacent counts, and available workers
                if (currentCell.population == 0 && currentCell.adjacentPowerlines >= 1 && availableWorkers >= 2) {
                    currentCell.population += 1;
					goodsIncrease++;
                    availableWorkers -= 2;
					hasChange = true;
                } else if (currentCell.population == 0 && currentCell.adjacentPopulation >= 1 && availableWorkers >= 2) {
                    currentCell.population += 1;
                    availableWorkers -= 2;
					goodsIncrease++;
					hasChange = true;
                } else if (currentCell.population == 1 && currentCell.adjacentPopulation >= 2 && availableWorkers >= 2) {
                    currentCell.population += 1;
                    availableWorkers -= 2;
					goodsIncrease++;
					hasChange = true;
                } else if (currentCell.population == 2 && currentCell.adjacentPopulation >= 8 && availableWorkers >= 2) {
                    currentCell.population += 1;
                    availableWorkers -= 2;
					goodsIncrease++;
					hasChange = true;
                }

                // Calculate pollution produced by the industrial cell
                currentCell.pollution = currentCell.population;
				

                // Spread pollution to adjacent cells
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;

                        // Ignore the current cell itself
                        if (ni == i && nj == j) {
                            continue;
                        }

                        // Check if the neighbor is within the region bounds
                        if (ni >= 0 && ni < zone.size() && nj >= 0 && nj < zone[ni].size()) {
                            int distance = abs(di) + abs(dj);
                            zone[ni][nj].pollution += max(0, currentCell.pollution - distance);
                        }
                    }
                }
            }
        }
    }
	availableGoods+=goodsIncrease;
	return hasChange;
}

bool simulateCommercial(vector<vector<Cell>>& zone, int& availableWorkers, int& availableGoods) {
    int adjacentPowerlines = 0;
    int adjacentPopulation = 0;
	bool hasChange = false;
    // Iterate over the cells in the commercial zone
    for (int i = 0; i < zone.size(); ++i) {
        for (int j = 0; j < zone[i].size(); ++j) {
            Cell& currentCell = zone[i][j];

            // Check the zone type and population of the current cell
            if (currentCell.zoneType == 'C') {
                adjacentPowerlines = 0;
                adjacentPopulation = 0;

                // Calculate the number of adjacent powerlines and neighboring cells with population
                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;

                        // Ignore the current cell itself
                        if (ni == i && nj == j) {
                            continue;
                        }

                        // Check if the neighbor is within the region bounds
                        if (ni >= 0 && ni < zone.size() && nj >= 0 && nj < zone[ni].size()) {
                            if (zone[ni][nj].population >= 1) {
                                ++adjacentPopulation;
                            }

                            if (zone[ni][nj].zoneType == 'T') {
                                ++adjacentPowerlines;
                            }
                        }
                    }
                }

                // Apply the rules based on the current cell's population, adjacent counts, and available workers and goods
                if (currentCell.population == 0 && adjacentPowerlines >= 1 && availableWorkers >= 1 && availableGoods >= 1) {
                    currentCell.population += 1;
                    availableWorkers -= 1;
                    availableGoods -= 1;
					hasChange = true;
                } else if (currentCell.population == 0 && adjacentPopulation >= 1 && availableWorkers >= 1 && availableGoods >= 1) {
                    currentCell.population += 1;
                    availableWorkers -= 1;
                    availableGoods -= 1;
					hasChange = true;
                } else if (currentCell.population == 1 && adjacentPopulation >= 2 && availableWorkers >= 1 && availableGoods >= 1) {
                    currentCell.population += 1;
                    availableWorkers -= 1;
                    availableGoods -= 1;
					hasChange = true;
                }
            }
        }
    }
	return hasChange;
}

void simulateCityDevelopment(vector<vector<Cell>>& zone, SimulationConfig config) {
    int timeStep = 1;
    bool hasChange = true;
    vector<vector<Cell>> updatedZone = zone;
    int availableWorkers = 0;
    int availableGoods = 0;
	
	
	checkAdjacenctPowerlines(zone);
	
    while (hasChange && timeStep <= config.timeLimit) {
        hasChange = false;
        
  
        bool residentialChange = simulateResidential(zone, availableWorkers);
        hasChange = hasChange || residentialChange;
        
        //Simulate industrial zones and check for changes
        bool industrialChange = simulateIndustrial(zone,availableWorkers, availableGoods);
        hasChange = hasChange || industrialChange;
        
        // Simulate commercial zones and check for changes
        bool commercialChange = simulateCommercial(zone,availableWorkers, availableGoods);
        hasChange = hasChange || commercialChange;
		
        
        
        
        
        cout << "Time Step: " << timeStep << endl;
        cout << "Available Workers: " << availableWorkers << endl;
        cout << "Available Goods: " << availableGoods << endl;
        
        // Display the state of the region at each time step
        if (timeStep % config.refreshRate == 0) {
            displayRegion(zone);
        }
		timeStep++;
    }
	
}

void examineRegion(const vector<vector<Cell>>& zone, int startX, int startY, int endX, int endY) {
    int numRows = zone.size();
    int numCols = zone[0].size();
    int totalPopulation = 0;
    int totalPollution = 0;

    for (int i = startY; i <= endY; ++i) {
        for (int j = startX; j <= endX; ++j) {
            const Cell& cell = zone[i][j];
            totalPopulation += cell.population;
            totalPollution += cell.pollution;
        }
    }
	cout << endl;
    cout << "Region Summary:" << endl;
    cout << "Total Population: " << totalPopulation << endl;
    cout << "Total Pollution: " << totalPollution << endl;

}

bool compareCells(const Cell& cell1, const Cell& cell2) {
    // Rule 1: Commercial zoned cells are prioritized over industrial zoned cells
    if (cell1.zoneType == 'C' && cell2.zoneType == 'I') {
        return true;
    }
    if (cell1.zoneType == 'I' && cell2.zoneType == 'C') {
        return false;
    }

    // Rule 2: Larger population zoned cells are prioritized over smaller population zoned cells
    if (cell1.population > cell2.population) {
        return true;
    }
    if (cell1.population < cell2.population) {
        return false;
    }

    // Rule 3: Zoned cells with greater total adjacent populations are prioritized over zoned cells with smaller total adjacent populations
    if (cell1.adjacentPopulation > cell2.adjacentPopulation) {
        return true;
    }
    if (cell1.adjacentPopulation < cell2.adjacentPopulation) {
        return false;
    }

    // Rule 4: Zoned cells with smaller Y coordinates are prioritized over zoned cells with greater Y coordinates
    if (cell1.yCoordinate < cell2.yCoordinate) {
        return true;
    }
    if (cell1.yCoordinate > cell2.yCoordinate) {
        return false;
    }

    // Rule 5: Zoned cells with smaller X coordinates are prioritized over zoned cells with greater X coordinates
    if (cell1.xCoordinate < cell2.xCoordinate) {
        return true;
    }
    if (cell1.xCoordinate > cell2.xCoordinate) {
        return false;
    }

    // No prioritization rule applies, maintain the current order
    return false;
}

void checkAdjacenctPowerlines(vector<vector<Cell>>& zone)
{
	for (int i = 0; i < zone.size(); ++i) 
	{
        for (int j = 0; j < zone[i].size(); ++j) 
		{
            // Check the zone type and population of the current cell
            
                

                // Calculate the number of adjacent powerlines and neighboring cells with population
                for (int di = -1; di <= 1; ++di) 
				{
                    for (int dj = -1; dj <= 1; ++dj) 
					{
                        int ni = i + di;
                        int nj = j + dj;

                        // Ignore the current cell itself
                        if (ni == i && nj == j) 
						{
                            continue;
                        }

                        // Check if the neighbor is within the region bounds
                        if (ni >= 0 && ni < zone.size() && nj >= 0 && nj < zone[ni].size()) 
						{
                            if (zone[ni][nj].population >= 1) 
							{
                                zone[i][j].adjacentPopulation++;
                            }

                            if (zone[ni][nj].zoneType == 'T' || zone[ni][nj].zoneType == '#') 
							{
                                zone[i][j].adjacentPowerlines++;
                            }
                        }
                    }
                }
		}
	}
}

void checkAdjacentPopulation(vector<vector<Cell>>& zone)
{
	
	for (int i = 0; i < zone.size(); ++i) 
	{
        for (int j = 0; j < zone[i].size(); ++j) 
		{
			zone[i][j].adjacentPopulation = 0;
            // Check the population of the current cell
            if(zone[i][j].zoneType == 'I' || zone[i][j].zoneType == 'C' || zone[i][j].zoneType == 'R')
			{
                

                // Calculate the number of neighboring cells with population
                for (int di = -1; di <= 1; ++di) 
				{
                    for (int dj = -1; dj <= 1; ++dj) 
					{
                        int ni = i + di;
                        int nj = j + dj;

                        // Ignore the current cell itself
                        if (ni == i && nj == j) 
						{
                            continue;
                        }

                        // Check if the neighbor is within the region bounds
                        if (ni >= 0 && ni < zone.size() && nj >= 0 && nj < zone[ni].size()) 
						{
                            if (zone[ni][nj].population >= 1) 
							{
								
                                zone[i][j].adjacentPopulation+=zone[ni][nj].population;
								//cout << zone[i][j].adjacentPopulation << " ";
                            }
                        }
                    }
                }
			}
		
		}
	}
	
	
}