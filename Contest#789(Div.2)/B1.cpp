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
		for (int i = 0; i < n; i += 2)
		{
			if (s[i] != s[i + 1])
			{
				++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
