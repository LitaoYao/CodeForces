// https://codeforces.com/contest/1680/problem/E
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<vector<char>> line(2, vector<char>(n));
	int from = n;
	int to = -1;
	for (int i = 0 ; i < 2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> line[i][j];
			if (line[i][j] == '*')
			{
				from = min(from, j);
				to = max(to, j);
			}
		}
	}
	vector<vector<int>> dp(2, vector<int>(n, 0));
	if (line[0][from] == '*')
	{
		dp[1][from] = 1;
	}
	if (line[1][from] == '*')
	{
		dp[0][from] = 1;
	}
	for (int i = from + 1; i <= to; ++i)
	{
		dp[0][i] = dp[0][i - 1] + 1;
		if (line[1][i] == '*')
		{
			dp[0][i] += 1;
		}
		dp[0][i] = min(dp[0][i], dp[1][i - 1] + 2);
		dp[1][i] = dp[1][i - 1] + 1;
		if (line[0][i] == '*')
		{
			dp[1][i] += 1;
		}
		dp[1][i] = min(dp[1][i], dp[0][i - 1] + 2);
	}
	cout << min(dp[0][to], dp[1][to]) << endl;
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
