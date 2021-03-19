#pragma once
#include <istream>
#include <sstream>
#ifndef UTILITIES_H
#define UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

namespace sdds {
	Vehicle* createInstance(std::istream& in);
}
#endif // !CAR_H

