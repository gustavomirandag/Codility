//Based in GeeksforGeeks solution
//http://www.geeksforgeeks.org/find-number-of-triangles-possible/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
	// Sort the vector in ascending order
	sort(A.begin(), A.end());
	int n = (signed)A.size();

	// Initialize count of triangles
	int count = 0;

	// Fix the first element.  We need to run till n-3
	// as the other two elements are selected from 
	// A[i+1...n-1]
	for (int i = 0; i < n - 2; ++i)
	{
		// Initialize index of the rightmost third 
		// element
		int k = i + 2;

		// Fix the second element
		for (int j = i + 1; j < n; ++j)
		{
			// Find the rightmost element which is
			// smaller than the sum of two fixed elements
			// The important thing to note here is, we 
			// use the previous  value of k. If value of 
			// A[i] + A[j-1] was greater than A[k],
			// then A[i] + A[j] must be greater than k, 
			// because the vector is sorted.
			while (k < n && A[i] + A[j] > A[k])
				++k;

			// Total number of possible triangles that can 
			// be formed with the two fixed elements is
			//  k - j - 1.  The two fixed elements are A[i]
			// and A[j].  All elements between A[j+1]/ to 
			// A[k-1] can form a triangle with A[i] and A[j].
			// One is subtracted from k because k is incremented 
			// one extra in above while loop.
			// k will always be greater than j. If j becomes equal
			// to k, then above loop will increment k, because A[k]
			//  + A[i] is always greater than A[k]
			count += k - j - 1;
		}
	}

	return count;
}