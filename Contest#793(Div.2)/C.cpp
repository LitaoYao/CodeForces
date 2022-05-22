#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int ans = 0;
	sort(nums.begin(), nums.end());
	int singleCount = 0;
	int multiCount = 0;
	int index = 0;
	while (index < n)
	{
		int nextIndex = index;
		while(nextIndex < n && nums[nextIndex] == nums[index])
		{
			++nextIndex;
		}
		if (nextIndex != index + 1)
		{
			++multiCount;
		}
		else
		{
			++singleCount;
		}
		index = nextIndex;
	}
	ans = (singleCount + 1) / 2 + multiCount;
	cout << ans << endl;
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
