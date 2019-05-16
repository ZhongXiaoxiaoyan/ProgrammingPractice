//题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1, 2, 4, 7, 3, 5, 6, 8 }和中序遍历序列{ 4, 7, 2, 1, 5, 3, 8, 6 }，
//则重建二叉树并返回。
//
//分析：先拿着前序的根，去中序中数组中，找到以这个根为一棵树的左右子树，
//然后将左子树的前序、中序找出来存在两个vector中，去构建左子树；
//将右子树的前序、中序存在两个vector中，构建右子树，然后链在当前根的左右两边。
//(以上过程是递归的，直到中序的vector中元素是0个了，即返回一个空结点给上一层，否则就返回当前根结点)


TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

	int vin_len = vin.size();//中序序列长度

	if (vin_len == 0)//空结点返回给上一层叶结点NULL
		return NULL;

	TreeNode* root = new TreeNode(pre[0]);//拿前序第一个节点创建根

	//存当前树左子树的，前序、中序
	vector<int> left_pre;
	vector<int> left_vin;

	//存当前树右子树的，前序、中序
	vector<int> right_pre;
	vector<int> right_vin;

	//由前序的根找到其在中序的位置
	int mid = 0;
	for (int i = 0; i<vin_len; i++)
	{
		if (vin[i] == pre[0])
		{
			mid = i;
			break;
		}
	}

	//将当前树左子树的，前序、中序放到对应的vector中
	for (int i = 0; i<mid; i++)
	{
		left_pre.push_back(pre[i + 1]);
		left_vin.push_back(vin[i]);
	}

	//将当前树右子树的，前序、中序放到对应的vector中
	for (int i = mid + 1; i<vin_len; i++)
	{
		right_pre.push_back(pre[i]);
		right_vin.push_back(vin[i]);
	}

	//将左子树、右子树，挂在当前树两边(递归)
	root->left = reConstructBinaryTree(left_pre, left_vin);
	root->right = reConstructBinaryTree(right_pre, right_vin);

	return root;
}