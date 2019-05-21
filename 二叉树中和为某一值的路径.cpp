//剑指offer：二叉树中和为某一值的路径
//
//题目：输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)


//全局变量
vector<vector<int>> res;//保存最终结果
vector<int> path;//保存每一次的路径

void find(TreeNode* root, int sum)
{
	if (root == nullptr)   //空节点，返回
		return;

	path.push_back(root->val);  // 将结点放入path数组中。

	//当前结点等于期待值,并且当前结点是叶子结点(则将该路径入到res中)
	if (sum == root->val && (root->left == nullptr && root->right == nullptr))
		res.push_back(path);
	else//不相等时
	{
		if (root->left)
			find(root->left, sum - root->val);     // 左子树递归，并且期待值 = 原期待值 - 减去当前结点
		if (root->right)
			find(root->right, sum - root->val);    // 右子树递归，并且期待值 = 原期待值 - 减去当前结点
	}
	// 当左右子树都递归了之后，把此结点POP掉，返回上一层。
	path.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	find(root, expectNumber);
	return res;
}