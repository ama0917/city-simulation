# City Growth & Resource Simulation Engine

A grid-based urban development simulation engine built in modern C++. The engine models a living city over discrete time steps — growing residential neighborhoods, building industrial output, opening commercial zones, and tracking pollution spread — all driven by adjacency rules, resource availability, and conflict-resolution logic.

---

## Overview

The simulation reads a region layout from a CSV map template and a config file, then evolves the city forward in time. At each step, the engine evaluates growth conditions for every zoned cell, resolves conflicts between competing growth events, propagates pollution from industrial zones, and tracks the flow of workers and goods across the economy.

This project demonstrates systems design, simulation modeling, C++ data structures, rule-based engine development, and config-driven architecture.

---

## Project Structure

```
├── main.cpp                  # Entry point, simulation orchestration
├── Cell.h / Cell.cpp         # Grid cell data model
├── simulationConfig.h/.cpp   # Config file parser and settings
├── RegionUtilities.h/.cpp    # Core simulation logic
├── region1template.csv       # Example region map
└── config1.txt               # Example simulation config
```

---

## How It Works

### Grid & Cell Model

The city is represented as a 2D grid of `Cell` objects. Each cell tracks:

| Field | Description |
|---|---|
| `zoneType` | Zone type character (see Zone Types below) |
| `population` | Current population or output level |
| `pollution` | Accumulated pollution value |
| `workers` | Workers available from this cell |
| `adjacentPopulation` | Sum of neighboring cell populations |
| `adjacentPowerlines` | Count of adjacent powerline cells |
| `adjacentGoods` | Adjacent goods supply |

### Zone Types

| Symbol | Zone |
|---|---|
| `R` | Residential |
| `I` | Industrial |
| `C` | Commercial |
| `T` | Powerline over road |
| `#` | Powerline |
| `-` | Road |
| `P` | Power plant |

### Config File Format

```
Refresh Rate: 5
Time Limit: 20
Region Layout: region1template.csv
```

- **Refresh Rate** — how often (in time steps) to print the region state
- **Time Limit** — maximum number of simulation steps
- **Region Layout** — path to the CSV map file

### Simulation Loop

Each time step runs three phases in order:

1. **Residential growth** — R cells grow when adjacent to powerlines or populated neighbors, subject to conflict resolution
2. **Industrial growth** — I cells grow when worker supply is available, producing goods and generating pollution
3. **Commercial growth** — C cells grow when both workers and goods are available

The loop continues until either no cell changes state or the time limit is reached.

---

## Growth Rules

### Residential (`R`)

| Current Population | Condition to Grow |
|---|---|
| 0 | Adjacent to at least 1 powerline |
| 0 | Adjacent population >= 1 |
| 1 | Adjacent population >= 2 |
| 2 | Adjacent population >= 4 |
| 3 | Adjacent population >= 6 |
| 4 | Adjacent population >= 8 |

### Industrial (`I`)

Grows when adjacent population thresholds are met and workers are available. Each growth event consumes 1 worker and produces goods and pollution.

### Commercial (`C`)

Grows when adjacent population thresholds are met and both workers and goods are available. Each growth event consumes 1 worker and 1 unit of goods.

---

## Conflict Resolution

When multiple cells are eligible to grow simultaneously and compete for limited resources, `compareCells()` resolves priority using a deterministic 5-rule cascade:

1. Commercial zones are prioritized over industrial zones
2. Higher current population wins
3. Higher total adjacent population wins
4. Lower Y coordinate wins (top of map)
5. Lower X coordinate wins (left of map)

This ensures deterministic, reproducible simulation outcomes regardless of iteration order.

---

## Pollution Model

Industrial growth generates pollution that spreads to neighboring cells based on Manhattan distance. Pollution accumulates over time and is tracked independently of population, allowing the final state to show both where the city grew and at what environmental cost.

---

## Running the Simulation

### Prerequisites
- C++11 or later
- A CSV region map and config file in the working directory

### Compile
```bash
g++ -std=c++11 main.cpp Cell.cpp simulationConfig.cpp RegionUtilities.cpp -o city_sim
```

### Run
```bash
./city_sim
```

The simulation will:
1. Load the region map and config
2. Display the initial region state
3. Run the simulation loop, printing state at each refresh interval
4. Display the final pollution state
5. Prompt for a sub-region to examine (enter X/Y coordinate bounds)

### Example Output
```
Time Step: 5
Available Workers: 12
Available Goods: 4
1 1 . . I I . .
1 2 R . I I . .
. R R . . T . .
...

Final pollution state:
R(0) R(0) .(0) I(3) I(5)
...

Region Summary:
Total Population: 47
Total Pollution: 112
```

---

## Region Map Format

Region maps are CSV files where each cell is represented by its zone type character:

```
,R,R,-,-,I,I,
R,R,R,-,T,I,I,
,R,,-,,T,,
```

Commas separate columns, newlines separate rows. Blank cells represent empty land.

---

## Concepts Demonstrated

- Object-oriented design with a modular Cell/Region architecture
- 2D grid traversal and adjacency-based rule evaluation
- Multi-phase simulation loop with time-step progression
- Deterministic conflict resolution via multi-criteria comparison
- Pollution propagation modeling
- Config-driven architecture with external parameter files
- CSV parsing into a dynamic 2D data structure
- Resource flow modeling (workers, goods) across economic zones
