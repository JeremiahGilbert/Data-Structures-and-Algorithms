#pragma once

class Customer {
public:
	Customer(int timeArrived);
	~Customer();

	bool serve(int time);

	int getTotalTime();

	int taskTime_;
	int timeArrived_;
	int timeServed_;
};

