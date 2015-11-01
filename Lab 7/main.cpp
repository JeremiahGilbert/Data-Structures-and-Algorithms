#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void mergesort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
void merge(std::vector<int>::iterator begin, std::vector<int>::iterator split, std::vector<int>::iterator end);

static std::uniform_int_distribution<int> intDistribution(0, 1000);
static std::mt19937 rng;

static int comparisons = 0;

int main() {
	for (int i = 5000; i <= 100000; i += 5000) {
		comparisons = 0;
		std::vector<int> random(i);
		std::for_each(random.begin(), random.end(), [](int& i) {i = intDistribution(rng); });
		mergesort(random.begin(), random.end());
		std::cout << "Size of Array: " << i << "; Comparisons: " << comparisons << std::endl;
	}
	return (0);
}

void mergesort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	int n = std::distance(begin, end);
	if (n > 1) {
		std::vector<int>::iterator split = begin + n / 2;
		mergesort(begin, split);
		mergesort(split, end);
		merge(begin, split, end);
	}
}

void merge(std::vector<int>::iterator begin, std::vector<int>::iterator split, std::vector<int>::iterator end) {
	std::vector<int> sum(std::distance(begin, end));
	auto i = begin, j = split;
	int k = 0;
	while (i != split && j != end) {
		if (*i < *j) {
			sum[k] = *i;
			++i;
		} else {
			sum[k] = *j;
			++j;
		}
		++k;
		++comparisons;
	}
	for (; i != split; ++i) {
		sum[k++] = *i;
	}
	for (; j != end; ++j) {
		sum[k++] = *j;
	}
	std::copy(sum.begin(), sum.end(), begin);
}