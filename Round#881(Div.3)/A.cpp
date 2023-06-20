// https://codeforces.com/contest/1843/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		ans += a[n - i - 1] - a[i];
	}
	cout << ans << endl;
	return;
}
void fastRead()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
int main()
{
	fastRead();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
