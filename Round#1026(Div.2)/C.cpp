// https://codeforces.com/contest/2110/problem/C
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> l(n + 1);
	vector<int> r(n + 1);
	vector<int> d(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> d[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> l[i] >> r[i];
	}
	vector<int> minH(n + 1);
	vector<int> maxH(n + 1);
	minH[0] = 0;
	maxH[0] = 0;
	bool enable = true;
	for (int i = 1; i <= n; ++i)
	{
		if (d[i] == -1)
		{
			minH[i] = minH[i - 1];
			maxH[i] = maxH[i - 1] + 1;
		}
		else
		{
			minH[i] = minH[i - 1] + d[i];
			maxH[i] = maxH[i - 1] + d[i];
		}
		if (minH[i] > r[i] || maxH[i] < l[i])
		{
			enable = false;
			break;
		}
		else
		{
			minH[i] = max(minH[i], l[i]);
			maxH[i] = min(maxH[i], r[i]);
		}
	}
	if (enable)
	{
		for (int i = n - 1; i >= 1; --i)
		{
			if (d[i + 1] == -1)
			{
				maxH[i] = min(maxH[i + 1], maxH[i]);
				minH[i] = max(minH[i + 1] - 1, minH[i]);
			}
			else
			{
				maxH[i] = min(maxH[i + 1] - d[i + 1], maxH[i]);
				minH[i] = max(minH[i + 1] - d[i + 1], minH[i]);
			}
			if (minH[i] > r[i] || maxH[i] < l[i])
			{
				enable = false;
				break;
			}
		}
	}
	if (enable)
	{
		int h = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (d[i] == -1)
			{
				if (h < maxH[i])
				{
					d[i] = 1;
				}
				else
				{
					d[i] = 0;
				}
			}
			h += d[i];
			cout << d[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
