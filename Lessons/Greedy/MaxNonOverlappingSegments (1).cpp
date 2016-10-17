#include <vector>
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
	int N = A.size();
	if (N <= 1) {
		return N;
	}

	int nonOverlapping = 1;
	int prev_end = B[0];

	int curr;
	for (curr = 1; curr < N; curr++) {
		if (A[curr] > prev_end) {
			nonOverlapping++;
			prev_end = B[curr];
		}
	}

	return nonOverlapping;
}


