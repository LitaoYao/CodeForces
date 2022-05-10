#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int lowbit(int x)
{
	return x & -x;
}
void add(vector<long long>& t, int n, int x)
{
	while (x <= n)
	{
		++t[x];
		x += lowbit(x);
	}
}
long long sum(vector<long long>& t, int x)
{
	long long res = 0;
	while (x >= 1)
	{
		res += t[x];
		x -= lowbit(x);
	}
	return res;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<long long> endPoints(n + 1);
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			if (i > 0)
			{
				ans += i - sum(endPoints, x - 1);
			}
			add(endPoints, n, x);
		}
		cout << ans << endl;
	}
	return 0;
}
