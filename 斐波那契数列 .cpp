//��Ŀ����Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����

//n <= 39

//������

//������1�������������齫ÿ��쳲���������ֵ������
int Fibonacci(int n)
{
	int a[40] = { 0 };
	a[0] = 0;
	a[1] = 1;

	for (int i = 2; i <= 39; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}

//������2������ѭ������
int Fibonacci(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	int first = 0;
	int second = 1;
	int sum = 0;

	while (n >= 2)
	{
		sum = first + second;
		first = second;
		second = sum;
		n--;
	}

	return sum;
}