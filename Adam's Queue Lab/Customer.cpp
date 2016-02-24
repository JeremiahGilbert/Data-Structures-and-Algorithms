#include "Customer.h"

#include "RNG.h"

Customer::Customer(int timeArrived) : timeArrived_(timeArrived), taskTime_(RNG::generateRandomInteger()) {}

Customer::~Customer() {}

bool Customer::serve(int time) {
	--taskTime_;
	return (taskTime_ == 0 ? timeServed_ = time, true : false);
}

int Customer::getTotalTime() {
	return (timeServed_ - timeArrived_);
}
