#include <iostream>
#include <vector>
using namespace std;
void solve()
{
	long long n, k;
	cin >> n >> k;
	if (k % 2 == 1)
	{
		cout << "YES" << endl;
		for (int i = 1; i <= n; i += 2)
		{
			cout << i << " " << i + 1 << endl;
		}
	}
	else
	{
		vector<int> a;
		vector<int> b;
		vector<int> c;
		for (int i = 1; i <= n; ++i)
		{
			if (i % 4 == 0)
			{
				b.push_back(i);
			}
			else if ((i + k) % 4 == 0)
			{
				a.push_back(i);
			}
			else
			{
				c.push_back(i);
			}
		}
		int aSize = a.size();
		int bSize = b.size();
		int cSize = c.size();
		if (aSize + bSize < cSize)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
			int aCnt = 0;
			int bCnt = 0;
			int cCnt = 0;
			while (aCnt < aSize && cCnt < cSize)
			{
				cout << a[aCnt++] << " " << c[cCnt++] << endl;
			}
			while (cCnt < cSize && bCnt < bSize)
			{
				cout << c[cCnt++] << " " << b[bCnt++] << endl;
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
