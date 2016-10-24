//http://codility-lessons.blogspot.com.br/2015/03/lesson-9-countsemiprimes.html
#include <vector>

using namespace std;

vector<int> sieve(int n) {
	vector<int> result(n + 1, 1);
	result[0] = 0;
	result[1] = 0;
	int i = 2;

	while (i * i <= n) {
		if (result[i]) {
			int k = i * i;
			while (k <= n) {
				result[k] = 0;
				k += i;
			}
		}
		i += 1;
	}
	return result;
}

int countSemiprimes(int start, int end, vector<int> &factors) {
	vector<int> semiPrimes(factors.size(),0);
	int count = 0;
	for (int i = start; i <= end; i++) {
		int current = i;
		if (factors[current] != 0) {
			current = current / factors[current];
			if (factors[current] == 0)
				count++;
		}
	}
	return count;
}

vector<int> solutionCountSemiPrimes(int N, vector<int> &P, vector<int> &Q) {
	vector<int> factors = sieve(N);
	vector<int> result(P.size());
	for (int i = 0; i < (signed)Q.size(); i++)
		result[i] = countSemiprimes(P[i], Q[i], factors);

	return result;
}