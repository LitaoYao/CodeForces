// https://codeforces.com/contest/2120/problem/C
#include <iostream>
#include <vector>
using namespace std;
void init()
{
	return;
}
void solve()
{
	long long n, m;
	cin >> n >> m;
	long long nowSum = (n + 1) * n >> 1;
	vector<long long> parents(n + 1);
	long long root = -1;
	for (int i = n; i >= 1; --i)
	{
		if (nowSum > m)
		{
			long long remain = nowSum - m;
			remain = min(remain, (long long)i - 1);
			nowSum -= remain;
			parents[i] = i - remain;
		}
		else
		{
			parents[i] = i;
			if (root == -1)
			{
				root = i;
			}
		}
	}
	if (nowSum != m)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << root << endl;
		for (int i = n; i >= 1; --i)
		{
			if (i == root)
			{
				continue;
			}
			if (i != parents[i])
			{
				cout << parents[i] << " " << i << endl;
			}
			else
			{
				cout << i + 1 << " " << i << endl;
			}
		}
	}
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
	init();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
