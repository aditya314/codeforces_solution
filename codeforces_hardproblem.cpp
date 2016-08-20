#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
/*We will solve the problem with the help of dynamic programming.
 dp[i][j] is the minimum amount of energy that should be spent to make first i strings sorted
 in lexicographical order and i-th of them will be reversed if j = 1 and not reversed if j = 0.
 dp[i][j] is updated by dp[i-1][0] and dp[i-1][1].
 It remains to verify that the i-th string is lexicographically greater than (i-1)-th
 (if j = 1 then we should check reversed i-th string, similar to (i-1)-th).
 Then we update dp[i][j] = min(dp[i][j], dp[i-1][0] + c[i] * j), dp[i][j] = min(dp[i][j], dp[i-1][1] + j * c[i]).
  The answer is a minimum of dp[n][0] and dp[n][1].
Time Complexity: O(n+sum_length).*/
int n;
vector <string> str;
long long c[200000];
long long dp[200000][2];

string rev(string x)
{
	string y;
	for (int i = x.size() - 1; i >= 0; i--)
		y += x[i];
	return y;
}

bool check(string a, string b)
{
	for (int i = 0; i < min(a.size(), b.size()); i++)
	{
		if (a[i] < b[i])
			return 0;
		if (a[i] > b[i])
			return 1;
	}
	return a.size() >= b.size();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		str.push_back(s);
	}
	for (int i = 0; i < 200000; i++)
	{
		dp[i][0] = 1000000000000000000;
		dp[i][1] = 1000000000000000000;
	}
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for (int i = 1; i < n; i++)
	{
		if (check(str[i], str[i - 1]) && dp[i - 1][0] < dp[i][0])
			dp[i][0] = dp[i - 1][0];
		if (check(str[i], rev(str[i - 1])) && dp[i - 1][1] < dp[i][0])
			dp[i][0] = dp[i - 1][1];
		if (check(rev(str[i]), str[i - 1]) && dp[i - 1][0] + c[i] < dp[i][1])
			dp[i][1] = dp[i - 1][0] + c[i];
		if (check(rev(str[i]), rev(str[i - 1])) && dp[i - 1][1] + c[i] < dp[i][1])
			dp[i][1] = dp[i - 1][1] + c[i];
	}
	if (dp[n - 1][0] == 1000000000000000000 && dp[n - 1][1] == 1000000000000000000)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}
