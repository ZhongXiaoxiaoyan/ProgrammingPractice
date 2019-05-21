// 剑指offer：从上往下打印出二叉树的每个节点，同层节点从左至右打印
//题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
//
//分析：借助一个队列，先将根结点的指针入队列，出来时访问它，然后将它的左右孩子带到队列中(这也是队列中放的是结点的指针原因，因为要通过它找到左右孩子)，然后只要队不空，就访问队头结点，带左右孩子。。。直到队为空，说明所有元素访问完了。

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> v;
	if (root == nullptr)
		return v;

	TreeNode* cur = root;
	queue<TreeNode*> q;
	q.push(cur);

	while (!q.empty())
	{
		v.push_back(q.front()->val);//先访问队头元素

		//将左右孩子带进队列
		if (q.front()->left != nullptr)
		{
			q.push(q.front()->left);
		}
		if (q.front()->right != nullptr)
		{
			q.push(q.front()->right);
		}

		q.pop();
	}

	return v;
}