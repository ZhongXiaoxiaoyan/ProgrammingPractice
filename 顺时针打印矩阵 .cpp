//题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，

//例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
//
//分析：顺着走，即向右->向下->向左->向上，一共要走（长*宽）步。
//遇到边界就改变方向，当向上碰到顶的时候，四个边界都缩小

vector<int> printMatrix(vector<vector<int>>& matrix) {


	vector<int> ret;
	if (matrix.empty())
		return ret;


	int rows = matrix.size();
	int cols = matrix[0].size();
	int elem = rows * cols;

	//用来遍历行、列
	int x = 0;
	int y = 0;

	//记录当前行、列的最大边界
	int row_max = rows - 1;
	int col_max = cols - 1;

	//记录当前所在的行、列
	int row_cur = 0;
	int col_cur = 0;


	while (elem-->0)
	{
		//先将当前元素尾插到ret数组中
		ret.push_back(matrix[x][y]);

		//往左走，走到边界停止，并且往下移动一行
		if (x == row_cur)
		{
			if (y < col_max)//当前行的列没走完，继续
			{
				y++;
			}
			else if (y == col_max) //当前列走完了，则列不变，移向下一行
			{
				x++;
			}
			continue;
		}

		//往下走
		if (y == col_max)
		{
			if (x < row_max)//当前列的行还没走完，继续
			{
				x++;
			}
			else if (x == row_max)//当前列的行走完了，移向前一列
			{
				y--;
			}
			continue;

		}

		//往左走
		if (x == row_max)
		{
			if (y > col_cur)//当前行的列没走完，继续
			{
				y--;
			}
			else if (y == col_cur)//当前行的列走完了，移向上一行
			{
				x--;
			}
			continue;

		}

		//往上走
		if (y == col_cur)
		{
			if (x > row_cur + 1)//当前列的行没走完，继续
			{
				x--;
			}
			else if (x == row_cur + 1)//向上碰到顶了，说明一圈走完了，那么将边界都缩小一圈,并且记录当前行列各增加1
			{
				y++;
				row_max--;
				col_max--;

				row_cur++;
				col_cur++;
			}
			continue;

		}
	}
	return ret;
}