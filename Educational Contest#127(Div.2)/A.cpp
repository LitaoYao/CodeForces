// https://codeforces.com/contest/1671/problem/A
#include <iostream>
#include <string>
using namespace std;
void solve()
{
	string str;
	cin >> str;
	bool ans = true;
	int n = str.size();
	if (n == 1)
	{
		ans = false;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (i == 0 && str[i] != str[i + 1])
			{
				ans = false;
				break;
			}
			else if (i == n - 1 && str[i] != str[i - 1])
			{
				ans = false;
				break;
			}
			else if (str[i] != str[i - 1] && str[i] != str[i + 1])
			{
				ans = false;
				break;
			}
		}
	}
	if (ans)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
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
