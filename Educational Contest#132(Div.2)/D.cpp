#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct TreeNode
{
	int left;
	int right;
	int val;
	TreeNode* leftNode;
	TreeNode* rightNode;
	TreeNode(int left, int right): left(left), right(right)
	{
		val = 0;
		leftNode = nullptr;
		rightNode = nullptr;
	}
};
void ensure(TreeNode* node)
{
	if (node->left == node-> right)
	{
		return;
	}
	int mid = (node->left + node-> right) >> 1;
	if (node->leftNode == nullptr)
	{
		node->leftNode = new TreeNode(node->left, mid);
	}
	if (node->rightNode == nullptr)
	{
		node->rightNode = new TreeNode(mid + 1, node->right);
	}
}
void add(TreeNode* node, int x, int val)
{
	if (node->left == x && node->right == x)
	{
		node->val = val;
		return;
	}
	ensure(node);
	int mid = (node->left + node-> right) >> 1;
	if (x <= mid)
	{
		add(node->leftNode, x, val);
	}
	else
	{
		add(node->rightNode, x, val);
	}
	node->val = max(node->leftNode->val, node->rightNode->val);
}
int query(TreeNode* node, int left, int right)
{
	if (node->left == left && node->right == right)
	{
		return node->val;
	}
	int mid = (node->left + node-> right) >> 1;
	if (right <= mid)
	{
		return query(node->leftNode, left, right);
	}
	else if (left > mid)
	{
		return query(node->rightNode, left, right);
	}
	else
	{
		return max(query(node->leftNode, left, mid), query(node->rightNode, mid + 1, right));
	}
}
void solve()
{
	int n, m, q;
	cin >> n >> m;
	TreeNode* root = new TreeNode(1, m);
	vector<int> nums(m + 1);
	for (int j = 1; j <= m; ++j)
	{
		cin >> nums[j];
		add(root, j, nums[j]);
	}
	cin >> q;
	int x1, y1, x2, y2, k;
	for (int i = 0; i < q; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		if (y2 < y1)
		{
			swap(y1, y2);
		}
		if (x2 < x1)
		{
			swap(x1, x2);
		}
		bool valid = true;
		int maxHeight = 0;
		if (y1 + 1 < y2)
		{
			maxHeight = query(root, y1 + 1, y2 - 1);
		}
		if ((y2 - y1) % k != 0)
		{
			valid = false;
		}
		if ((x2 - x1) % k != 0)
		{
			valid = false;
		}
		int maxStep = (n - x1) / k;
		if (x1 + maxStep * k <= maxHeight)
		{
			valid = false;
		}
		cout << (valid ? "YES" : "NO") << endl;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
