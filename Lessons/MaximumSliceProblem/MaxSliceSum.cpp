//Kadane’s algorithm
//Jay Kadane of Carnegie-Mellon University (Bentley 1984)

#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
	int maxSum = A[0];
	int sum = A[0];

	for (int i = 1; i < (signed)A.size(); i++) {
		sum = max(A[i], sum + A[i]);
		maxSum = max(maxSum, sum);
	}
	return maxSum;
}