// https://codeforces.com/contest/1700/problem/A
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	int m;
	cin >> n >> m;
	vector<long long> dp(m, 0);
	dp[0] = 1;
	for (int j = 1; j < m; ++j)
	{
		dp[j] = dp[j - 1] + j + 1;
	}
	for (int i = 1; i < n; ++i)
	{
		dp[m - 1] = dp[m - 1] + i * m + m;
	}
	cout << dp[m - 1] << endl;
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
