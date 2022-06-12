#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<long long> p(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	vector<long long> sum = p;
	for (int i = 1; i < n; ++i)
	{
		sum[i] += sum[i - 1];
	}
	int x, y;
	long long ans;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		ans = sum[x - 1];
		if (y < x)
		{
			ans -= sum[x - y - 1];
		}
		cout << ans << endl;
	}
	return;
}
int main()
{
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
