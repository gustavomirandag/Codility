#include <stack>
#include <string>

using namespace std;

int solutionNesting(string &S) {
	stack<char> checkStack;
	for (int i = 0; i<(signed)S.size();i++) {
		if (S[i] == '(')
			checkStack.push('(');
		else {
			if (!checkStack.empty())
				checkStack.pop();
			else
				return 0;
		}
	}

	if (checkStack.empty())
		return 1;
	else
		return 0;
}