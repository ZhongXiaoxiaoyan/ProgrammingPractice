//��ָoffer����������˳��ʹ����λ��ż��ǰ��


//��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
//
//����������ǰ��ָ�뷨��ǰ���ָ���ҵ�ż��ͣ�����������ָ���ҵ�����ͣ������Ȼ���ӦԪ�ؽ�������Ϊ������ı���ż�������λ�á�
//
//������1�����������±�odd, even, even�������飬����ż�����������ߣ����������ͽ�����������odd��Ӧλ�ã�Ȼ��odd�����ƶ����Ƚ���odd��ʼ��λ�õ�����Ԫ������Ų��һ������������Ŀ�����ܹ�����ż�����λ�ò��䣩�����˼·Ҳ����ʹ��oddǰ��Ķ����������������λ�ò��䣬��odd��even֮��Ķ���ż����Ȼ��even��������ͣ������������ŵ�oddλ�ã�����ǰ���ǽ�oddλ���ϵ�ż�����Ų����֤ż�����λ�ò��䣬������even�ߵ����ʱ����ʹ��odd֮ǰ�Ķ���������odd��even֮��Ķ���ż����


void reOrderArray(vector<int> &array) {

	int len = array.size();
	int odd = 0;
	int even = 0;

	while (even < len)
	{
		if (array[even] % 2 != 0)
		{
			int tmp = array[even];
			for (int i = even; i > odd; i--)
			{
				array[i] = array[i - 1];
			}

			array[odd] = tmp;
			even++;
			odd++;
		}
		else
		{
			even++;
		}
	}
}

//
//������2����������ð�����򣬴�ͷ��ʼ������Ԫ��ֻҪ��ǰż����ͽ�������ͬ������ѭ��ÿ�ζ���ͷ��ʼ����ֹһ��ʼ�������������ż�����

void reOrderArray(vector<int> &array) {

	int len = array.size();

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (array[j] % 2 == 0 && array[j + 1] % 2 != 0)
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}



//������3��������һ����ԭ����һ�����vector, ��ͷ����һ�齫��������ǰ�棬Ȼ���ٱ���һ�飬��ż�����ŷ��ں��档

void reOrderArray(vector<int> &array) {

	vector<int> v(array.size());
	int end = array.size() - 1;
	int j = 0;

	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] % 2 != 0)//����
		{
			v[j] = array[i];
			j++;
		}
	}

	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] % 2 == 0)//ż��
		{
			v[j] = array[i];
			j++;
		}
	}
	array = v;
}

