//Based in Kadane’s algorithm
//Jay Kadane of Carnegie-Mellon University (Bentley 1984)

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <vector>

using namespace std;

int solutionMaxProfit(vector<int> &A) {
	if (A.size() == 0)
		return 0;
	int maxProfit = 0;
	int buy = A[0]; //Starts buying first position
	for (int i = 1; i < (signed)A.size(); i++) {
		maxProfit = max(maxProfit, A[i] - buy);
		buy = min(buy, A[i]);
	}
	return maxProfit;
}