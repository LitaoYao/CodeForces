#include <iostream>
#include <algorithm>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	int x;
	int odd = 0;
	int even = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (x % 2 == 0)
		{
			++even;
		}
		else
		{
			++odd;
		}
	}
	cout << min(odd, even) << endl;
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
