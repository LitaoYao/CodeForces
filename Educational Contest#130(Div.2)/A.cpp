// https://codeforces.com/contest/1697/problem/A
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> dists(n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> dists[i];
		ans += dists[i];
	}
	if (ans > m)
	{
		cout << ans - m << endl;
	}
	else
	{
		cout << 0 << endl;
	}
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
