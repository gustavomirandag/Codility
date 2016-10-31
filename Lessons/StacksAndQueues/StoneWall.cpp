#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> &H) {
	stack<int> stones;
	int result = 0;//blocks

	for (int i = 0; i < (signed)H.size(); i++) {
		while (!stones.empty() && H[i]<stones.top())
			stones.pop();
		if (stones.empty() || H[i]>stones.top()) {
			stones.push(H[i]);
			result++;
		}
		if (H[i] < stones.top()) {
			stones.push(H[i]);
			result++;
		}
	}
	return result;
}