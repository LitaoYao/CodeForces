#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int mod = 998244353;
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> counts(n + 1);
	vector<int> dp(n + 1);
	dp[0] = 1;
	bool valid = true;
	while (valid)
	{
		valid = false;
		vector<int> tmp(n + 1);
		for (int i = k; i <= n; ++i)
		{
			tmp[i] = (tmp[i - k] + dp[i - k]) % mod;
			valid |= tmp[i];
		}
		for (int i = 0; i <= n; ++i)
		{
			counts[i] = (counts[i] + tmp[i]) % mod;
			dp[i] = tmp[i];
		}
		++k;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << counts[i] % mod << " \n"[i == n];
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}


