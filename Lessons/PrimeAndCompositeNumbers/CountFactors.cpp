#include <math.h>

using namespace std;

int solution(int N) {
	int max = sqrt(N);
	int count = 0;
	for (int a = 1; a <= max; a++) {
		if (N % a == 0) {
			if (N / a <= max)
				count++;
			else
				count += 2;
		}
	}
	return count;
}