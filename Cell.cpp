#include "Cell.h"

bool Cell::operator==(const Cell& other) const {
    return (zoneType == other.zoneType &&
            population == other.population &&
            pollution == other.pollution &&
            workers == other.workers);
}