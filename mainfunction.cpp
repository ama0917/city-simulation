#include <iostream>
#include <fstream>
#include <vector>
#include "simulationConfig.h"
#include "Cell.h"
#include "RegionUtilities.h"
using namespace std;
int main() {
   vector<vector<Cell>> zone;
	int regionWidth;
	zone = readRegion(zone);
	int startX, startY, endX, endY;
	bool validRegion = false;
	
	string configFilePath = "config1.txt";
	SimulationConfig config = readConfigFromFile(configFilePath);
	
	displayRegion(zone);
	
	
	simulateCityDevelopment(zone,config);
	cout << endl << endl;
	cout << "Final pollution state:" << endl;
	displayPollution(zone);
	cout << endl << endl;
	cout << "Examine a zone:" << endl;
	while (!validRegion)
	{
	cout << "Enter first X coordinate:";
	cin >> startX;
	cout << "Enter first Y coordinate:";
	cin >> startY;
	cout << "Enter second X coordinate:";
	cin >> endX;
	cout << "Enter second Y coordinate:";
	cin >> endY;
	if (startX >= 0 && startY >= 0 && endX < zone[0].size() && endY < zone.size() &&
            startX <= endX && startY <= endY) {
            validRegion = true;
        } else {
            cout << "Invalid region coordinates. Please try again." << endl;
        }
	}
	examineRegion(zone,startX,startY,endX,endY);
    return 0;
}