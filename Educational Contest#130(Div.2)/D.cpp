// https://codeforces.com/contest/1697/problem/D
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

char askIndex(int index)
{
	cout << "? 1 " << index + 1 << endl;
	cout << flush;
	char ans;
	cin >> ans;
	return ans;
}
int askRange(int left, int right)
{
	cout << "? 2 " << left + 1 << " " << right + 1 << endl;
	cout << flush;
	int ans;
	cin >> ans;
	return ans;
}
void solve()
{
	int n;
	cin >> n;
	string s = "";
	vector<int> indexs;
	for (int i = 0; i < n; ++i)
	{
		sort(indexs.begin(), indexs.end());
		int tot = indexs.size();
		int left = -1;
		int right = tot - 1;
		while (left < right)
		{
			int mid = (left + right + 1) >> 1;
			int diff = askRange(indexs[mid], i);
			if (diff <= tot - mid)
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		if (left == -1)
		{
			s += askIndex(i);
			indexs.push_back(i);
		}
		else
		{
			s += s[indexs[left]];
			indexs[left] = i;
		}
	}
	cout << "! ";
	for (int i = 0; i < n; ++i)
	{
		cout << s[i];
	}
	cout << endl;
	cout << flush;
	return;
}
int main()
{
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
