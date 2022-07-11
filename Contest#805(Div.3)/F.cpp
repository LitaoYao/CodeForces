#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	map<int, int> counts;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		while ((a[i] & 1) == 0)
		{
			a[i] >>= 1;
		}
		counts[a[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		while ((b[i] & 1) == 0)
		{
			b[i] >>= 1;
		}
	}
	sort(b.begin(), b.end());
	bool valid = true;
	for (int i = n - 1; i >= 0; --i)
	{
		bool has = false;
		while (b[i] != 0)
		{
			if (counts.count(b[i]) && counts[b[i]] > 0)
			{
				--counts[b[i]];
				has = true;
				break;
			}
			b[i] >>= 1;
		}
		if (!has)
		{
			valid = false;
			break;
		}
	}
	cout << (valid ? "YES" : "NO") << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
