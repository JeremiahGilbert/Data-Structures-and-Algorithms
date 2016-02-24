#include <array>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>

#include "Customer.h"
#include "RNG.h"

int main() {
	std::queue<std::unique_ptr<Customer>> mainQueue;
	std::array<std::unique_ptr<Customer>, 3> tellers;
	std::array<int, 10000> timeTaken;

	int nextCustomer = 1;
	int customersServed = 0;
	int clock = 0;
	while (customersServed < 10000) {
		--nextCustomer;
		++clock;
		if (nextCustomer == 0) {
			mainQueue.push(std::make_unique<Customer>(clock));
			nextCustomer = RNG::generateRandomInteger();
		}
		for (auto& teller : tellers) {
			if (!teller && !mainQueue.empty()) {
				teller = std::move(mainQueue.front());
				mainQueue.pop();
			}
			if (teller && teller->serve(clock)) {
				timeTaken[customersServed] = teller->getTotalTime();
				teller.reset();
				++customersServed;
				if (customersServed == 10000) break;
			}
		}
	}
	std::cout << "The average time taken is: " << std::accumulate(timeTaken.begin(), timeTaken.end(), 0) / float(timeTaken.size()) << std::endl;

	return (0);
}