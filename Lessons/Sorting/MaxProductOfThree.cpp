#include <algorithm>
#include <vector>

using namespace std;

int solutionMaxProductOfThree(vector<int> &A) {
	sort(A.begin(), A.end());

	int resultWithNeg = 0;
	if (A[0] < 0 && A[1] < 0)
		resultWithNeg = A[0] * A[1] * A[A.size() - 1];
	int result = A[A.size() - 1] * A[A.size() - 2] * A[A.size() - 3];

	if (resultWithNeg > result)
		return resultWithNeg;
	else
		return result;
}