#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> nums(2 * n);
	for (int i = 0; i < 2 * n; ++i)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	bool valid = true;
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] + x > nums[n + i])
		{
			valid = false;
			break;
		}
	}
	cout << (valid ? "YES" : "NO") << endl;
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
