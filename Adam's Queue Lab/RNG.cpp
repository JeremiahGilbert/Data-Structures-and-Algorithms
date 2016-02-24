#include "RNG.h"

#include <random>

int RNG::generateRandomInteger() {
	static std::uniform_int_distribution<int> UID(1, 5);
	static std::mt19937 rng;
	return (UID(rng));
}