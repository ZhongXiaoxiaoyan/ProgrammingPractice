//��ָoffer���������к�Ϊĳһֵ��·��
//
//��Ŀ������һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)


//ȫ�ֱ���
vector<vector<int>> res;//�������ս��
vector<int> path;//����ÿһ�ε�·��

void find(TreeNode* root, int sum)
{
	if (root == nullptr)   //�սڵ㣬����
		return;

	path.push_back(root->val);  // ��������path�����С�

	//��ǰ�������ڴ�ֵ,���ҵ�ǰ�����Ҷ�ӽ��(�򽫸�·���뵽res��)
	if (sum == root->val && (root->left == nullptr && root->right == nullptr))
		res.push_back(path);
	else//�����ʱ
	{
		if (root->left)
			find(root->left, sum - root->val);     // �������ݹ飬�����ڴ�ֵ = ԭ�ڴ�ֵ - ��ȥ��ǰ���
		if (root->right)
			find(root->right, sum - root->val);    // �������ݹ飬�����ڴ�ֵ = ԭ�ڴ�ֵ - ��ȥ��ǰ���
	}
	// �������������ݹ���֮�󣬰Ѵ˽��POP����������һ�㡣
	path.pop_back();
}

vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {
	find(root, expectNumber);
	return res;
}