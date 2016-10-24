// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int solutionDistinct(vector<int> &A) {
	set<int> uniqueElements(A.begin(), A.end());

	return uniqueElements.size();
}