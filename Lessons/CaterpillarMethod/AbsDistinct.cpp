#include <cmath>
#include <vector>

using namespace std;

int solutionAbsDistinct(vector<int> &A) {
	int posL = 0;
	int posR = (signed)A.size() - 1;
	int countUniqueValues = 0;

	/*if (A[posL] == -2147483648) {
		countUniqueValues++;
		while (posL<(signed)A.size() && A[posL] == -2147483648)
			posL++;
	}*/

	while (posL <= posR) {
		int absL = abs(A[posL]);
		int absR = abs(A[posR]);

		countUniqueValues++;

		if (absL<absR) {
			while (posR>0 && absR == abs(A[posR]))
				posR--;
		}
		else if (absL > absR) {
			while (posL<(signed)A.size() && absL == abs(A[posL]))
				posL++;
		}
		else { //absL == absR
			while (posL<(signed)A.size() && absL == abs(A[posL]))
				posL++;
			while (posR>0 && absR == abs(A[posR]))
				posR--;
		}

	}
	return countUniqueValues;
}