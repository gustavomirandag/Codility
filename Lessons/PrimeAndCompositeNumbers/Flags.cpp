#include <cmath>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
	int lastPeak = 0;
	int flags = 0;

	int leftPos = 0; //Pos 0
	int rightPos = -1;

	for (int i = 1; i < (signed)A.size() - 1; i++) {
		rightPos = i + 1;
		if (A[i]>A[leftPos] && A[i]>A[rightPos]) { //It's a peak
			if (abs(i - lastPeak)>flags)
				flags++;
			lastPeak = i;
		}
	}

	return flags;
}
