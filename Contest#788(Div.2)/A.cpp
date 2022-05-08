#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> nums(n);
		int negativeCount = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
			if (nums[i] < 0)
			{
				++negativeCount;
			}
		}
		for (int i = 0; i < negativeCount; ++i)
		{
			nums[i] = -abs(nums[i]);
		}
		for (int i = negativeCount; i < n; ++i)
		{
			nums[i] = abs(nums[i]);
		}
		bool isAvailable = true;
		for (int i = 0; i < n - 1; ++i)
		{
			if (nums[i] > nums[i + 1])
			{
				isAvailable = false;
				break;
			}
		}
		if (isAvailable)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
