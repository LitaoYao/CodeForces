// https://codeforces.com/contest/1684/problem/D
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	long long n, k;
	cin >> n >> k;
	vector<vector<long long>> traps(n, vector<long long>(2, 0));
	for (int i = 0; i < n; ++i)
	{
		cin >> traps[i][1];
		traps[i][0] = traps[i][1] - (n - i - 1);
	}
	sort(traps.begin(), traps.end());
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i >= n - k)
		{
			ans += traps[i][1] - traps[i][0];
		}
		else
		{
			ans += traps[i][1];
		}
	}
	ans -= (k - 1) * k / 2;
	cout << ans << endl;
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

