#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int getMaxNonOverlapping(vector<int> &A, vector<int> &B, stack<int> &linesToProcess, int startWith) {
	vector<int> overlapping(B.back(), 0);

	int maxNonOverlapping = 0;

	//Check the first Element
	for (int i = A[startWith];i<(signed)B[startWith];i++)
		overlapping[i] = 1;

	for (int i = 0; i<(signed)A.size();i++) {
		if (i == startWith) //Jump the started element
			continue;
		for (int j = A[i]; j<(signed)B[i];j++) {
			if (overlapping[j] == 0)
				overlapping[j] = 1;//Occupied
			else {
				linesToProcess.push(j);
				maxNonOverlapping--;
				break;
			}

		}
		maxNonOverlapping++;
	}
	return maxNonOverlapping;
}

int solution(vector<int> &A, vector<int> &B) {
	vector<int> overlapping(B.back(), 0);
	int maxNonOverlapping = 0;
	vector<int, int> startedLines(A.size(), 0);
	stack<int> linesToProcess;

	if (A.size() == 0)
		return 0;

	startedLines.push_back(make_pair(0, 1));
	linesToProcess.push(0);
	while (!linesToProcess.empty()) {
		if (startedLines[linesToProcess.top()] == 1) {
			linesToProcess.pop();
			continue;
		}
		else {
			startedLines[linesToProcess.top()] = 1;
			linesToProcess.pop();
		}

		int currentMax = getMaxNonOverlapping(A, B, linesToProcess, linesToProcess.top());
		maxNonOverlapping = max(maxNonOverlapping, currentMax);
	}
	return maxNonOverlapping;
}