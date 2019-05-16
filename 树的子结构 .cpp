//��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
//
//�������ȿ�B�ǲ�����A�ĸ����Ϊ�������������ǵĻ�ֱ�ӷ���true, 
//�����ǲ�����A��������Ϊ�������������ٿ�����������һ���ݹ�Ĺ��̡�


//�ж�node2�ǲ�����node1�ĸ����Ϊ����������
bool is_subtree(TreeNode* node1, TreeNode* node2)
{
	//��һ�ν���node2�϶����ǿգ���Ϊ�����߼�HasSubtree
	//���Ѿ��жϹ���

	if (node2 == nullptr)//node2�ܹ��ߵ��գ�˵��node2֮ǰ�Ľ����node1�Ѿ�ƥ������
		return true;

	if (node1 == nullptr)//��Ȼ�����⣬˵��node2��Ϊ�գ���ônode1Ϊ�գ�˵��node2û��ƥ����
		return false;

	if (node1->val == node2->val)//�����������ǰ���ֵ��ͬ,��Ҫ����������������������������������������
		return is_subtree(node1->left, node2->left)
		&& is_subtree(node1->right, node2->right);
	else
		return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	//ֻҪ��һ�����ǿ������Ͳ����ӽṹ
	if (pRoot1 == nullptr)
		return false;
	if (pRoot2 == nullptr)
		return false;

	bool flag = is_subtree(pRoot1, pRoot2);//��pRoot2�ǲ�����pRoot1�����Ϊ������pRoot1������
	if (flag == false)//˵�����ǣ�����pRoot1��������Ϊ�������ǲ���
		flag = is_subtree(pRoot1->left, pRoot2);
	if (flag == false)//˵�����ǣ�����pRoot1��������Ϊ�������ǲ���
		flag = is_subtree(pRoot1->right, pRoot2);

	return flag;

}