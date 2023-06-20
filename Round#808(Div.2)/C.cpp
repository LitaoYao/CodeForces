// https://codeforces.com/contest/1708/problem/C
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	long long n, q;
	cin >> n >> q;
	vector<long long> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	vector<int> choose(n, 0);
	long long Q = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (Q < q)
		{
			choose[i] = 1;
		}
		else if (Q == q && nums[i] <= q)
		{
			choose[i] = 1;
		}
		if (Q < q && Q < nums[i])
		{
			++Q;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << choose[i];
	}
	cout << endl;
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
