#include <iostream>
#include <vector>
#include <string>
using namespace std;
void solve()
{
	string str;
	cin >> str;
	int n = str.size();
	vector<int> zeroCount(n + 2, 0);
	vector<int> oneCount(n + 2, 0);
	for (int i = 1; i <= n; ++i)
	{
		int zero = 0;
		if (str[i - 1] == '0')
		{
			zero = 1;
		}
		zeroCount[i] = zeroCount[i - 1] + zero;
		oneCount[i] = oneCount[i - 1] + (1 - zero);
	}
	oneCount[n + 1] = oneCount[n];
	int ans = oneCount[n];
	for (int i = 1; i <= n; ++i)
	{
		int rightOne = oneCount[n + 1] - oneCount[i];
		int leftZero = zeroCount[i];
		if (leftZero <= rightOne)
		{
			ans = min(ans, rightOne);
		}
		else
		{
			/*
				The important mathematical property:
				leftZero - rightOne = index = zeroCount[index] + oneCount[index]
				We should find an index in order to make the function below minimized.
				minimize max(zeroCount[i] - zeroCount[index], rightOne + oneCount[index])
				=> minimize max(leftZero - rightOne - zeroCount[index], oneCOunt[index])
				=> leftZero - rightOne - zeroCount[index] = oneCount[index]
				=> leftZero - rightOne = oneCount[index] + zeroCount[index] = index
				=> leftZero - rightOne = index
			*/
			int index = leftZero - rightOne;
			if (index <= i)
			{
				ans = min(ans, max(zeroCount[i] - zeroCount[index], rightOne + oneCount[index]));
			}
		}
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
