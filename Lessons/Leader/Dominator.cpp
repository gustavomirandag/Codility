#include <climits>
#include <unordered_map>

using namespace std;

int solutionDominator(vector<int> &A) {
	unordered_map<int, int> occurrences;

	for (int i = 0; i<(signed)A.size(); i++) {
		if (occurrences.find(A[i]) == occurrences.end())
			occurrences[A[i]] = 1;
		else
			occurrences[A[i]]++;
	}

	int dominatorQtd = INT_MIN;
	int dominatorValue = 0;
	int equalDominator = 0;
	for (auto iter : occurrences) {
		if (iter.second>dominatorQtd) {
			dominatorQtd = iter.second;
			dominatorValue = iter.first;
			equalDominator = 0;
		}
		else
			if (iter.second == dominatorQtd)
				equalDominator++;
	}

	if (equalDominator != 0 || dominatorQtd <= (signed)A.size() / 2)
		return -1;

	for (int i = 0; i<(signed)A.size(); i++)
		if (A[i] == dominatorValue)
			return i;

	return -1;
}