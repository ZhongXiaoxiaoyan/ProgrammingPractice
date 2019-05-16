//题目：在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

//思路：从第一行最后一个数开始查找，要找的数大于这个数，则当前列不变，行加加；
//要找的数小于这个数，当前行不变，列减减；否则说明找到了
#include <iostream>
#include <vector>
using namespace std;


bool Find(int target, vector<vector<int>> array) {

	int rows = array.size();
	int cols = array[0].size();

	//从第一行最后一个数据开始查找
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