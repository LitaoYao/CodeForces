#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<long long> trees(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> trees[i];
	}
	long long ans = 0;
	for (int i = 1; i < n; ++i)
	{
		ans += abs(trees[i] - trees[i - 1]);
		if (trees[i] < trees[i - 1])
		{
			trees[0] -= abs(trees[i] - trees[i - 1]);
		}
	}
	ans += abs(trees[0]);
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
