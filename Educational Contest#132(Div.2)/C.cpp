#include <iostream>
#include <string>
using namespace std;
void solve()
{
	string str;
	cin >> str;
	int n = str.size();
	int left = 0;
	int right = 0;
	int leftIndex = -1;
	int rightIndex = -1;
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '(')
		{
			++left;
		}
		else if (str[i] == ')')
		{
			++right;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '?')
		{
			if (left < n / 2)
			{
				++left;
				str[i] = '(';
				leftIndex = max(leftIndex, i);
			}
			else
			{
				++right;
				str[i] = ')';
				if (rightIndex == -1)
				{
					rightIndex = i;
				}
			}
		}
	}
	bool unique = true;
	if (leftIndex != -1 && rightIndex != -1)
	{
		swap(str[leftIndex], str[rightIndex]);
		long long sum = 0;
		bool valid = true;
		for (int i = 0; i < n; ++i)
		{
			if (str[i] == '(')
			{
				++sum;
			}
			else if (str[i] == ')')
			{
				--sum;
			}
			if (sum < 0)
			{
				valid = false;
				break;
			}
		}
		unique = (valid == false);
	}
	cout << (unique ? "YES" : "NO") << endl;
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
