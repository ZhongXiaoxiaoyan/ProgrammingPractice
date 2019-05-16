//��Ŀ����һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

//˼·���ӵ�һ�����һ������ʼ���ң�Ҫ�ҵ����������������ǰ�в��䣬�мӼӣ�
//Ҫ�ҵ���С�����������ǰ�в��䣬�м���������˵���ҵ���
#include <iostream>
#include <vector>
using namespace std;


bool Find(int target, vector<vector<int>> array) {

	int rows = array.size();
	int cols = array[0].size();

	//�ӵ�һ�����һ�����ݿ�ʼ����
	int i = 0;
	int j = cols - 1;

	while (i<rows && j >= 0)
	{
		if (target>array[i][j])
		{
			i++;
		}
		else if (target<array[i][j])
		{
			j--;
		}
		else
		{
			return true;
		}
	}
	return false;
}