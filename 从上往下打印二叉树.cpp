// ��ָoffer���������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ
//��Ŀ���������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
//
//����������һ�����У��Ƚ�������ָ������У�����ʱ��������Ȼ���������Һ��Ӵ���������(��Ҳ�Ƕ����зŵ��ǽ���ָ��ԭ����ΪҪͨ�����ҵ����Һ���)��Ȼ��ֻҪ�Ӳ��գ��ͷ��ʶ�ͷ��㣬�����Һ��ӡ�����ֱ����Ϊ�գ�˵������Ԫ�ط������ˡ�

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> v;
	if (root == nullptr)
		return v;

	TreeNode* cur = root;
	queue<TreeNode*> q;
	q.push(cur);

	while (!q.empty())
	{
		v.push_back(q.front()->val);//�ȷ��ʶ�ͷԪ��

		//�����Һ��Ӵ�������
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