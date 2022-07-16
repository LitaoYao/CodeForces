#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	long long n, l, r;
	cin >> n >> l >> r;
	vector<long long> nums(n + 1);
	bool valid = true;
	for (int i = 1; i <= n; ++i)
	{
		long long k;
		if (l % i == 0)
		{
			k = l / i;
		}
		else
		{
			k = l / i + 1;
		}
		nums[i] = i * k;
		if (nums[i] > r)
		{
			valid = false;
			break;
		}
	}
	if (valid)
	{
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++i)
		{
			cout << nums[i] << " \n"[i == n];
		}
	}
	else
	{
		cout << "NO" << endl;
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
