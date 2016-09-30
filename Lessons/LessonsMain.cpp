#include <iostream>
#include <vector>
//#include "BinaryGapp.h"
#include " "

using namespace std;

int main() {
	//cout<<solution(1045); //BinaryGapp
	vector<int> vecAux = { 3,8,9,7,6 };
	vector <int> result = solution(vecAux, 3);
	for (int i = 0; i < result.size();i++) {
		cout << result[i]<<" ";
	}
	int i;
	cin>>i;
	return 0;
}