// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <limits>
#include <string>

using namespace std;

std::string toBinStr(unsigned n) {
	const int size = sizeof(n) * 8;
	std::string res;
	bool s = 0;
	for (int a = 0;a<size;a++) {
		bool bit = n >> (size - 1);
		if (bit)
			s = 1;
		if (s)
			res.push_back(bit + '0');
		n <<= 1;
	}
	if (!res.size())
		res.push_back('0');
	return res;
}

int solutionBinaryGap(int N) {
	int maxGap = 0;
	int newGap = 0;
	bool startCounting = false;
	string binaryN = toBinStr(N);

	for (unsigned int i = 0; i<binaryN.size(); i++) {
		if (startCounting == false) {
			if (binaryN[i] == '1')
				startCounting = true;
		}
		else {
			if (binaryN[i] == '1') {
				if (newGap > maxGap)
					maxGap = newGap;
				newGap = 0;
			}
			else
				newGap++;
		}
	}
	return maxGap;
}