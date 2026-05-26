#include "simulationConfig.h"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>

SimulationConfig::SimulationConfig() {
    refreshRate = 0;
    timeLimit = 0;
    regionFilePath = "";
    configFilePath = "";
}

SimulationConfig readConfigFromFile(const string& filePath) {
    SimulationConfig config;
    unordered_map<string,string> configMap;

    ifstream configFile(filePath);
    if (!configFile.is_open()) {
        cout << "Failed to open config file: " << filePath << std::endl;
        return config;
    }

    string line;
    while (getline(configFile, line)) {
        istringstream iss(line);
        string paramName, paramValue;

        if (getline(iss, paramName, ':') && getline(iss, paramValue)) {
            paramName.erase(paramName.find_last_not_of(" \t") + 1);
            paramValue.erase(0, paramValue.find_first_not_of(" \t"));

            configMap[paramName] = paramValue;
        }
    }

    configFile.close();

    // Extract values from the config map
    if (configMap.count("Refresh Rate")) {
        config.refreshRate = stoi(configMap["Refresh Rate"]);
    }
    if (configMap.count("Time Limit")) {
        config.timeLimit = stoi(configMap["Time Limit"]);
    }
    if (configMap.count("Region Layout")) {
        config.regionFilePath = configMap["Region Layout"];
    }

    return config;
}
