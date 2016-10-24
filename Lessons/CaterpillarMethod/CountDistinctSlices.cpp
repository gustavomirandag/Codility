#include <vector>

using namespace std;

int solutionCountDistinctSlices(int M, vector<int> &A) {
	vector<int> found(M, -1);
	int last = -1;
	int count = 0;

	for (int i = 0; i < (signed)A.size(); i++) {
		if (found[A[i]] > last)
			last = found[A[i]];

		count += i - last;
		found[A[i]] = i;

		if (count>1000000000)
			return 1000000000;
	}
	return count;
}