#include <iostream>
#include <vector>
using namespace std;
int merge(int l1, int r1, int l2)
{
	int ans = 0;
	if (r1 < l2)
	{
		ans = l1 + l2;
	}
	else
	{
		ans = l2;
	}
	return ans;
}
void solve()
{
	int l1, r1, l2, r2;
	cin >> l1;
	cin >> r1;
	cin >> l2;
	cin >> r2;
	int ans = 0;
	if (l1 < l2)
	{
		ans = merge(l1, r1, l2);
	}
	else
	{
		ans = merge(l2, r2, l1);
	}
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
