#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> cards(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> cards[i];
	}
	int m;
	cin >> m;
	int nowCnt = 0;
	int x;
	for (int i = 0; i < m; ++i)
	{
		cin >> x;
		nowCnt = (nowCnt + x) % n;
	}
	cout << cards[nowCnt] << endl;
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
