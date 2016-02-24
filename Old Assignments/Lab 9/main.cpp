#include <algorithm>
#include <vector>

void heapify(std::vector<int>::iterator start, std::vector<int>::iterator end);
void heapify(std::vector<int>::iterator start, std::vector<int>::iterator split, std::vector<int>::iterator end);

int main() {
	std::vector<int> a = {12, 10, 20, 19, 8, 7, 15};//{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
	heapify(a.begin(), a.end());
	return (0);
}

void heapify(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	heapify(start, start, end);
}

void heapify(std::vector<int>::iterator start, std::vector<int>::iterator split, std::vector<int>::iterator end) {
	int i = std::distance(start, split);
	int j = std::distance(start, end);
	if (2 * i + 1 > j) {
		return;
	}
	auto l = start + 2 * i + 1;
	auto r = start + 2 * i + 2;
	std::vector<int>::iterator largest;

	if (l < end && *l > *split) {
		largest = l;
	} else {
		largest = split;
	}
	if (r < end && *r > *largest) {
		largest = r;
	}
	if (largest != split) {
		int temp = *split;
		*split = *largest;
		*largest = temp;
		heapify(start, largest, end);
	}
}