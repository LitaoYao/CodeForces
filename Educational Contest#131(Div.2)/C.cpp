#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> workers(n, 0);
	vector<int> diffs(n, 0);
	int index;
	for (int i = 0; i < m; ++i)
	{
		cin >> index;
		++workers[index - 1];
	}
	sort(workers.begin(), workers.end());
	reverse(workers.begin(), workers.end());
	int maxTime = workers[0];
	int left = 1;
	int right = maxTime;
	while (left < right)
	{
		int mid = (left + right) >> 1;
		int more = 0;
		for (int i = 0; i < n; ++i)
		{
			if (workers[i] > mid)
			{
				more += workers[i] - mid;
			}
			int now = min(workers[i], mid);
			if (now < mid)
			{
				more -= (mid - now) / 2;
				more = max(0, more);
			}
		}
		if (more > 0)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	cout << left << endl;
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
