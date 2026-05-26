#ifndef SIMULATIONCONFIG_H
#define SIMULATIONCONFIG_H
#include <string>

using namespace std;

class SimulationConfig {
public:
    int refreshRate;
    int timeLimit;
    string regionFilePath;
    string configFilePath;
    
    SimulationConfig();
};

SimulationConfig readConfigFromFile(const string& filePath);

#endif
