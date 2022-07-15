#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	long long ans = 0;
	int left = -1;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		if (i < n - 1)
		{
			ans += nums[i];
			if (nums[i] > 0 && left == -1)
			{
				left = i;
			}
		}
	}
	if (ans <= 0)
	{
		cout << ans << endl;
	}
	else
	{
		for (int i = left; i < n - 1; ++i)
		{
			if (nums[i] == 0)
			{
				++ans;
			}
		}
		cout << ans << endl;
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
