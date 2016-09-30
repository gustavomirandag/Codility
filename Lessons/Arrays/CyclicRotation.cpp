// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>

using namespace std;


int getNewIndex(int index, vector<int> &A, int K) {
	if (index + K < A.size()) 
		return abs(index + K);
	else{
		K = K - ((A.size() - 1) - index + 1); //The +1 at the end is to go to position 0
		K =  K%A.size();
		return K;
	}	
}

vector<int> solution(vector<int> &A, int K) {
	if (A.empty())
		return A;

	if (K > A.size())
		K = K%A.size();
	vector<bool> aControl(A.size(), false);
	int index = 0;
	int indexValue = A[index];
	int auxValue;
	int newIndex;
	for (int i = 0; i < A.size(); i++) { //Used to guarantee that all have moved
		index = i;
		indexValue = A[i];
		while (aControl[index] == false) {
			newIndex = getNewIndex(index, A, K);
			auxValue = A[newIndex];
			A[newIndex] = indexValue;
			aControl[index] = true;//Mark as Rotated
			index = newIndex;
			indexValue = auxValue;
		}
	}
	return A;
}