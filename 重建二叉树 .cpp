//��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������
//���������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{ 1, 2, 4, 7, 3, 5, 6, 8 }�������������{ 4, 7, 2, 1, 5, 3, 8, 6 }��
//���ؽ������������ء�
//
//������������ǰ��ĸ���ȥ�����������У��ҵ��������Ϊһ����������������
//Ȼ����������ǰ�������ҳ�����������vector�У�ȥ������������
//����������ǰ�������������vector�У�������������Ȼ�����ڵ�ǰ�����������ߡ�
//(���Ϲ����ǵݹ�ģ�ֱ�������vector��Ԫ����0���ˣ�������һ���ս�����һ�㣬����ͷ��ص�ǰ�����)


TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

	int vin_len = vin.size();//�������г���

	if (vin_len == 0)//�ս�㷵�ظ���һ��Ҷ���NULL
		return NULL;

	TreeNode* root = new TreeNode(pre[0]);//��ǰ���һ���ڵ㴴����

	//�浱ǰ���������ģ�ǰ������
	vector<int> left_pre;
	vector<int> left_vin;

	//�浱ǰ���������ģ�ǰ������
	vector<int> right_pre;
	vector<int> right_vin;

	//��ǰ��ĸ��ҵ����������λ��
	int mid = 0;
	for (int i = 0; i<vin_len; i++)
	{
		if (vin[i] == pre[0])
		{
			mid = i;
			break;
		}
	}

	//����ǰ���������ģ�ǰ������ŵ���Ӧ��vector��
	for (int i = 0; i<mid; i++)
	{
		left_pre.push_back(pre[i + 1]);
		left_vin.push_back(vin[i]);
	}

	//����ǰ���������ģ�ǰ������ŵ���Ӧ��vector��
	for (int i = mid + 1; i<vin_len; i++)
	{
		right_pre.push_back(pre[i]);
		right_vin.push_back(vin[i]);
	}

	//���������������������ڵ�ǰ������(�ݹ�)
	root->left = reConstructBinaryTree(left_pre, left_vin);
	root->right = reConstructBinaryTree(right_pre, right_vin);

	return root;
}