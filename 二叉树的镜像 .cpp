//
//��Ŀ�����������Ķ�����������任ΪԴ�������ľ���

//�������ľ����壺Դ������
//     8
//   /  \
//  6    10
// / \   / \
// 5  7  9 11
//���������
//     8
//    /  \
//   10   6
//  / \  / \
// 11 9 7  5
//
//����������ײ㿪ʼ����һ����(��������)��������������Ϊ�������ǽ��ָ�룬��˵��ϲ㽻��ʱ���Զ����²��Ѿ��������Ľ���������

//����һ��������������(�ݹ飬������ײ㿪ʼ����)
//���ڽ������ǽ�㣬��˽����ϲ���ʱ���Զ��Ὣ�²��Ѿ��������Ľ�������

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