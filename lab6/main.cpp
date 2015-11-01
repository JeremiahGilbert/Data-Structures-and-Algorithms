#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

std::string lcs(std::string x, std::string y);
void randomizeString(std::string& const string);

static std::uniform_int_distribution<int> lengthDistribution(1, 100);
static std::uniform_int_distribution<int> alpahbetDistribution(0, 25);
static std::mt19937 rng;

int main() {
	for (int i = 0; i < 100; ++i) {
		std::string a(lengthDistribution(rng), 'a');
		std::string b(lengthDistribution(rng), 'b');

		randomizeString(a);
		randomizeString(b);

		std::cout << "First String:\t" << a << std::endl;
		std::cout << "Second String:\t" << b << std::endl << std::endl;
		std::cout << "LCS:\t" << lcs(a, b) << std::endl << std::endl;
	}
	return (0);
}

std::string lcs(std::string x, std::string y) {
	int m = x.length(), n = y.length();
	std::vector<std::vector<int>> lengths = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1));//int L[m + 1][n + 1];
	for (auto i = lengths.begin(); i != lengths.end(); ++i) {
		for (auto j = (*i).begin(); j != (*i).end(); ++j) {
			if (i == lengths.begin() || j == (*i).begin()) {
				(*j) = 0;
			} else if (x.at(i - lengths.begin() - 1) == y.at(j - (*i).begin() - 1)) {
				(*j) = lengths[i - lengths.begin() - 1][j - (*i).begin() - 1] + 1;
			} else {
				(*j) = std::max(lengths[i - lengths.begin() - 1][j - (*i).begin()], lengths[i - lengths.begin()][j - (*i).begin() - 1]);
			}
		}
	}
	int i = m, j = n;
	std::string lcsString;
	while (i > 0 && j > 0) {
		if (lengths[i][j - 1] == lengths[i][j]) {
			--j;
		} else if (lengths[i - 1][j] == lengths[i][j]) {
			--i;
		} else {
			lcsString.append(1, x.at(i - 1));
			--i;
			--j;
		}
	}
	std::reverse(lcsString.begin(), lcsString.end());
	return (lcsString);
}

void randomizeString(std::string& const string) {
	for (auto& i = string.begin(); i != string.end(); ++i) {
		(*i) = alpahbetDistribution(rng) + 'A';
	}
}