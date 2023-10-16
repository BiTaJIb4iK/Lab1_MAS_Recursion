
#include <iostream>
#include <string.h>
#include <unordered_map>

// #1 Unefficient way    ------ Function calls : 392835 (n=25)
int uniqueJumpComb_Recursion(int n, int& func_calls) {
	func_calls++;

	if (n == 0) {
		return 1;
	}
	else if (n < 0)
		return 0;

	return uniqueJumpComb_Recursion(n - 1, func_calls) + uniqueJumpComb_Recursion(n - 2, func_calls);
}
// #2 Using map to store already calculated values
// ...

// #3 Using dp array
int UniqueJumpComb_DP_array(int n) {
	if (n <= 1) {
		return 1;
	}

	std::vector<int> dp(n + 1, 1);
	//dp[0] = 1;
	//dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main()
{
	const int n = 25;

	int func_calls = 0;
	std::cout << uniqueJumpComb_Recursion(n, func_calls) << "\nFunction calls : " << func_calls << "\n\n";

	std::cout << UniqueJumpComb_DP_array(n) << '\n';
}
