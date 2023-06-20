// https://codeforces.com/contest/1716/problem/B
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	cout << n << endl;
	vector<int> nums(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		nums[i] = i;
		cout << i << " \n"[i == n];
	}
	for (int i = 1; i < n; ++i)
	{
		swap(nums[n - i + 1], nums[n - i]);
		for (int j = 1; j <= n; ++j)
		{
			cout << nums[j] << " \n"[j == n];
		}
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
