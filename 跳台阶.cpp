//��Ŀ��һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
//�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������

//������쳲������������⣬����ע���ֵ

int jumpFloor(int number) {

	//1����1�֣�2����2�֣�3����3�֣�4����5��
	if (number == 1)
		return 1;
	else if (number == 2)
		return 2;

	int first = 1;
	int second = 2;
	int sum = 0;
	while (number>2)
	{
		sum = first + second;
		first = second;
		second = sum;
		number--;
	}
	return sum;
}