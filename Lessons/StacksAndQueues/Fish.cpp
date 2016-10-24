#include <stack>
#include <vector>

using namespace std;

int solutionFish(vector<int> &A, vector<int> &B) {
	stack<int> downstream;
	int alive = 0;

	for (int i = 0; i<(signed)A.size(); i++) {
		if (B[i] == 0) {//Upstream
			while (!downstream.empty() && A[i] > downstream.top())
				downstream.pop();
			if (downstream.empty())
				alive++;
		}
		else {
			downstream.push(A[i]);
		}
	}
	alive += downstream.size();
	return alive;
}