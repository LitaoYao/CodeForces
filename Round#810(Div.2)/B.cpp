// https://codeforces.com/contest/1711/problem/A
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> c(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	vector<pair<int, int>> r(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> r[i].first;
		cin >> r[i].second;
		++c[r[i].first];
		++c[r[i].second];
	}
	if ((m & 1) == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		int ans = INT_MAX;
		for (int i = 1; i <= n; ++i)
		{
			if ((c[i] & 1) == 1)
			{
				ans = min(ans, a[i]);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			int x = r[i].first;
			int y = r[i].second;
			if ((c[x] & 1) == 0 && (c[y] & 1) == 0)
			{
				ans = min(ans, a[x] + a[y]);
			}
		}
		cout << ans << endl;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
