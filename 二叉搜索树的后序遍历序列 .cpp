//��ָoffer������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No���������������������������ֶ�������ͬ��
//��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes, �������No���������������������������ֶ�������ͬ��
//
//�������������������һ�������Ǹ�������ݣ���ô������ֱؽ����зֳ����������֣�������������е����ݣ�С���ұ����е����ݣ������ҵ�����ֽ�������Ұ벿�ִ���һ��С����������ݵģ���˵�����Ǻ���������Ȼ����ͬ���ķ�ʽ�ݹ��ж���������������������


bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() <= 0)
		return false;

	return _VerifySquenceOfBST(sequence, 0, sequence.size() - 1);

}

//�ж����һ�������ǲ��ǽ�����ֳ���߶�С����������ұ߶����������
bool  _VerifySquenceOfBST(vector<int> v, int start, int end)
{
	if (start >= end)
		return true;

	int root = v[end];

	int i = start;
	//�ҵ���һ���ȸ�����ķֽ��
	while (v[i]<root)
	{
		i++;
	}

	//������˵��i>=root����i�Ǹø�������������
	//����������д���һ��ֵ<����㣬��ô���Ǻ�����ֱ��return false
	int j = i;
	while (j<end)
	{
		if (v[j]<root)
		{
			return false;
		}
		j++;
	}
	//������˵����ǰ��������� ����������У�С���ұ����У�������������������ҲҪ
	//�����������
	return _VerifySquenceOfBST(v, start, i - 1) && _VerifySquenceOfBST(v, i, end - 1);
}