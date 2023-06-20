// https://codeforces.com/contest/1719/problem/C
#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n, q;
	int no, k;
	cin >> n >> q;
	vector<int> nums(n + 1);
	vector<int> begins(n + 1, -1);
	vector<int> ends(n + 1, -1);
	int index = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> nums[i];
		if (nums[i] == n)
		{
			index = i;
		}
	}
	int a = 1;
	int b = 2;
	int round = 1;
	while (a < index && b < index)
	{
		if (begins[a] == -1)
		{
			begins[a] = round;
		}
		begins[b] = round;
		if (nums[a] > nums[b])
		{
			++b;
			ends[b] = round;
		}
		else
		{
			ends[a] = round;
			a = b;
			++b;
		}
		++round;
	}
	if (begins[a] == -1)
	{
		begins[a] = round;
	}
	ends[a] = round;
	for (int i = 0; i < q; ++i)
	{
		cin >> no >> k;
		if (no > index)
		{
			cout << 0 << endl;
		}
		else if (no < index)
		{
			int r = 0;
			r = max(0, min(k - begins[no] + 1, ends[no] - begins[no]));
			cout << r << endl;
		}
		else
		{
			if (index >= 2)
			{
				cout << max(0, k - index + 2) << endl;
			}
			else
			{
				cout << k << endl;
			}
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
