// https://codeforces.com/contest/1708/problem/A
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	bool valid = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
		if (i > 0 && nums[i] % nums[0] != 0)
		{
			valid = false;
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
