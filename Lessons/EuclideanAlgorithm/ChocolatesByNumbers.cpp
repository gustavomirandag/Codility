int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	return gcd(b, a%b);
}


int solutionChocolatesByNumbers(int N, int M) {
	return N / gcd(N, M);
}