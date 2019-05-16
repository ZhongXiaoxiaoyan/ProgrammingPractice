//题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//
//分析：先看B是不是以A的根结点为根结点的子树，是的话直接返回true, 
//否则看是不是以A的左子树为根结点的子树，再看右子树这是一个递归的过程。


//判断node2是不是以node1的根结点为根结点的子树
bool is_subtree(TreeNode* node1, TreeNode* node2)
{
	//第一次进来node2肯定不是空，因为在主逻辑HasSubtree
	//中已经判断过了

	if (node2 == nullptr)//node2能够走到空，说明node2之前的结点与node1已经匹配上了
		return true;

	if (node1 == nullptr)//既然来到这，说明node2不为空，那么node1为空，说明node2没有匹配完
		return false;

	if (node1->val == node2->val)//如果两个树当前结点值相同,则要看两个树的左子树与左子树，右子树与右子树
		return is_subtree(node1->left, node2->left)
		&& is_subtree(node1->right, node2->right);
	else
		return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//只要有一棵树是空树，就不是子结构
	if (pRoot1 == nullptr)
		return false;
	if (pRoot2 == nullptr)
		return false;

	bool flag = is_subtree(pRoot1, pRoot2);//看pRoot2是不是以pRoot1根结点为根结点的pRoot1的子树
	if (flag == false)//说明不是，则看以pRoot1的左子树为根结点的是不是
		flag = is_subtree(pRoot1->left, pRoot2);
	if (flag == false)//说明不是，则看以pRoot1的右子树为根结点的是不是
		flag = is_subtree(pRoot1->right, pRoot2);

	return flag;

}