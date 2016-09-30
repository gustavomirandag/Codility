#include <stack>
#include <string>

using namespace std;

int solution(string &S) {
	stack<char> checkStack;
	for (int i = 0; i<(signed)S.size();i++) {
		if (S[i] == '(' || S[i] == '{' || S[i] == '[')
			checkStack.push(S[i]);
		else {
			if (!checkStack.empty()) {
				if (checkStack.top() == '(' && S[i] == ')') {
					checkStack.pop();
					continue;
				}
				if (checkStack.top() == '{' && S[i] == '}') {
					checkStack.pop();
					continue;
				}
				if (checkStack.top() == '[' && S[i] == ']') {
					checkStack.pop();
					continue;
				}
				return 0;
			}
			else
				return 0;
		}
	}

	if (checkStack.empty())
		return 1;
	else
		return 0;
}