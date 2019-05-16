//��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
//��������{ 3, 4, 5, 1, 2 }Ϊ{ 1, 2, 3, 4, 5 }��һ����ת�����������СֵΪ1�� 
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
//
//�������Ǽ���������飬���൱���ǵ����������顰��
//
//������1����ֱ�ӱ������ҵ���Сֵ��
//
//������2����������ת��ǰ����һ�����������У�������һ�����������У��ҳ����ǵ������Ǹ�Ԫ��
//
//������3�������ö��ֲ��ҡ�����м�Ԫ��ֵ>���һ��Ԫ��ֵ��˵����Сֵ�Ұ����䣬
//����м�Ԫ��<���һ��Ԫ�����䣬˵����Сֵ��������䣬������˵������ͬԪ�أ�
//	��Ҫ���ж�������ǰ��һ�£������жϣ�����ѭ����
//	�����ֲ��ҵĵ�������������ˣ���˵���ҵ���Сֵ�ˡ�

int minNumberInRotateArray(vector<int> rotateArray)
{
	int len = rotateArray.size();

	if (len == 0)
		return 0;

	int min = rotateArray[0];
	int len = rotateArray.size();

	for (int i = 1; i<len; i++)
	{
		if (rotateArray[i]<min)
		{
			min = rotateArray[i];
		}
	}

	return min;
}


int minNumberInRotateArray(vector<int> rotateArray)
{
	int len = rotateArray.size();

	if (len == 0)
		return 0;

	for (int i = 0; i<len; i++)
	{
		if (rotateArray[i] <= rotateArray[i + 1])
		{
			continue;
		}
		else
		{
			return rotateArray[i + 1];
		}
	}
	return rotateArray[0];
}

int minNumberInRotateArray(vector<int> rotateArray)
{
	int length = rotateArray.size();
	if (length == 0)
		return 0;
	int pre = 0;//��һ��Ԫ���±�
	int last = length - 1;//���һ��Ԫ���±�
	while (pre < last)
	{
		int mid = (pre + last) / 2;

		//���м�Ԫ�� ���� ���һ��Ԫ�أ�˵����Сֵ���Ұ�����
		//����pre�±�
		if (rotateArray[mid] > rotateArray[last])
		{
			pre = mid + 1;
		}
		//���м�Ԫ�� С�� ���һ��Ԫ�أ�˵����Сֵ���������
		//�����м����Ԫ�أ����ܾ�����Сֵ������� last=mide,������
		//last=mid-1
		else if (rotateArray[mid] < rotateArray[last]) {
			last = mid;
		}
		//���м�Ԫ�� ���� ���һ��Ԫ�أ�˵�����ظ�Ԫ�أ���������Сһ��
		else {
			last = last - 1;
		}
	}
	return rotateArray[pre];
}