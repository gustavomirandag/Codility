#include <math.h>

using namespace std;

int solution(int N) {
	int a = sqrt(N);
	for (; a >= 1; a--) {
		if (N % a == 0)
			break;
	}
	int b = N / a;
	return (a + b)*2;
}