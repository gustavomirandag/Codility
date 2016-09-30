#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
	unordered_map<unsigned int, unsigned int> counterMap;

	for (unsigned int i = 0; i < A.size(); i++) {
		if (counterMap.find(A[i]) == counterMap.end()) {
			counterMap[A[i]] = 1;
		}
		else {
			counterMap[A[i]]++;
		}
	}

	for (auto iterMap : counterMap) {
		if (iterMap.second % 2 != 0)
			return iterMap.first;
	}
	return 0;
}