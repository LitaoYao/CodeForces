// https://codeforces.com/contest/1701/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	cout << 2 << endl;
	vector<int> nums(n + 1, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (nums[i] == 0)
		{
			int x = i;
			while (x <= n)
			{
				nums[x] = 1;
				cout << x << " ";
				x *= 2;
			}
		}
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
