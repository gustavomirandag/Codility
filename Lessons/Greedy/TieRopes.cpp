// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>

using namespace std;

int solution(int K, vector<int> &A) {
	int count = 0;
	for (int i = 0; i<(signed)A.size(); i++) {
		if (A[i] >= K)
			count++;
		else {
			if (i<(signed)A.size() - 1)
				A[i + 1] += A[i];
		}
	}
	return count;
}