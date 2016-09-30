//It is asked to check if it's possible to make a Triangle with 3 elements of
//the array/vector. I SORT it to guarantee two conditions:
// - A[index] <= A[index+1] <= A[index+2]
// - A[index+1] <= A[index] + A[index+2]
//
//So, i just need to iterate one more time O(N) to verify if the condition
//below is true:
// - A[index+2] <= A[index] + A[index+1]
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
	sort(A.begin(), A.end());

	long long int sum;
	for (int i = 0; i<(signed)A.size() - 2;i++) {
		sum = (long long int)A[i] + (long long int)A[i + 1];
		if (sum>A[i + 2])
			return 1;
	}
	return 0;
}