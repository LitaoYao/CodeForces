#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		string str = "";
		for (int i = 0; i < n; i += 2)
		{
			if (s[i] != s[i + 1])
			{
				++ans;
				str += '*';
			}
			else
			{
				str += s[i];
			}
		}
		char now = '*';
		int minSeg = 0;
		for (int i = 0; i < n / 2; ++i)
		{
			if (str[i] == '*')
			{
				continue;
			}
			if (now != str[i])
			{
				++minSeg;
				now = str[i];
			}
		}
		if (minSeg == 0)
		{
			minSeg = 1;
		}
		cout << ans << " " << minSeg << endl;
	}
	return 0;
}
