//��ָoffer�����ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����


int rectCover(int number) {
	//Ҳ��쳲��������У�n==1ʱ1�֣�n==2ʱ2�֣�n==3ʱ3��...f(n)=f(n-1)+f(n-2)
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