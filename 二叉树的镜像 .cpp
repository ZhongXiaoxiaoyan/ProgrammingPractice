//
//题目：操作给定的二叉树，将其变换为源二叉树的镜像。

//二叉树的镜像定义：源二叉树
//     8
//   /  \
//  6    10
// / \   / \
// 5  7  9 11
//镜像二叉树
//     8
//    /  \
//   10   6
//  / \  / \
// 11 9 7  5
//
//分析：从最底层开始交换一棵树(树的子树)的左右子树，因为交换的是结点指针，因此当上层交换时会自动将下层已经交换过的结点带过来。

//交换一棵树的左右子树(递归，即从最底层开始交换)
//由于交换的是结点，因此交换上层结点时，自动会将下层已经交换过的结点带过来

void exchange(TreeNode* root)
{
	if (root == NULL)
		return;
	exchange(root->left);
	exchange(root->right);

	TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}

void Mirror(TreeNode *pRoot) {
	if (pRoot == nullptr)
		return;

	exchange(pRoot);
}