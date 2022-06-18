#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solve()
{
	int n;
	cin >> n;
	vector<int> stones(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> stones[i];
	}
	if ((n & 1) == 1)
	{
		cout << "Mike" << endl;
	}
	else
	{
		int minNum = *min_element(stones.begin(), stones.end());
		for (int i = 0; i < n; ++i)
		{
			if (stones[i] == minNum)
			{
				if ((i & 1) == 1)
				{
					cout << "Mike" << endl;
				}
				else
				{
					cout << "Joe" << endl;
				}
				break;
			}
		}
	}
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
