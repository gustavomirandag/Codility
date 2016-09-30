// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<climits>
#include<vector>

using namespace std;

int solution(vector<int> &A) {
	vector<int> maxValues(A.size(), INT_MIN);

	maxValues[0] = A[0];
	for (int pebble = 0; pebble<(signed)A.size() - 1; pebble++) {
		for (int dice = 1; dice <= 6; dice++) {
			int pebbleNextStep = pebble + dice;
			if (pebbleNextStep >(signed)A.size() - 1)
				continue;
			int tempMax = A[pebbleNextStep] + maxValues[pebble];
			if (maxValues[pebbleNextStep] < tempMax)
				maxValues[pebbleNextStep] = tempMax;
		}
	}

	return maxValues[A.size() - 1];
}