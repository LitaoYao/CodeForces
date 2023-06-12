// https://codeforces.com/contest/1840/problem/C
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve()
{
	int n, k, q;
	cin >> n >> k >> q;
	vector<long long> sigma(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		sigma[i] = sigma[i - 1] + i;
	}
	int m = 0;
	int temperature;
	long long ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> temperature;
		if (temperature <= q)
		{
			++m;
		}
		else
		{
			if (m >= k)
			{
				ans += sigma[m - k + 1];
			}
			m = 0;
		}
	}
	if (m >= k)
	{
		ans += sigma[m - k + 1];
	}
	cout << ans << endl;
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
