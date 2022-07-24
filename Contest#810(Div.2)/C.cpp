#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> colors(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> colors[i];
	}
	sort(colors.begin(), colors.end());
	bool valid = false;
	long long fill = 0;
	for (int i = 0; i < k; ++i)
	{
		if (colors[i] < m * 2)
		{
			continue;
		}
		int x = colors[i] / m;
		if (fill + x == n - 1)
		{
			if (x > 2)
			{
				fill += x - 1;
			}
			continue;
		}
		else
		{
			fill += x;
		}
		if (fill >= n)
		{
			break;
		}
	}
	if (fill >= n)
	{
		valid = true;
	}
	if (!valid)
	{
		fill = 0;
		for (int i = 0; i < k; ++i)
		{
			if (colors[i] < n * 2)
			{
				continue;
			}
			int x = colors[i] / n;
			if (fill + x == m - 1)
			{
				if (x > 2)
				{
					fill += x - 1;
				}
				continue;
			}
			else
			{
				fill += x;
			}
			if (fill >= m)
			{
				break;
			}
		}
		if (fill >= m)
		{
			valid = true;
		}
	}
	cout << (valid ? "YES" : "NO") << endl;
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
