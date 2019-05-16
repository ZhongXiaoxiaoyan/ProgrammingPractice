//��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�

//���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//�����δ�ӡ������1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
//
//������˳���ߣ�������->����->����->���ϣ�һ��Ҫ�ߣ���*������
//�����߽�͸ı䷽�򣬵�������������ʱ���ĸ��߽綼��С

vector<int> printMatrix(vector<vector<int>>& matrix) {


	vector<int> ret;
	if (matrix.empty())
		return ret;


	int rows = matrix.size();
	int cols = matrix[0].size();
	int elem = rows * cols;

	//���������С���
	int x = 0;
	int y = 0;

	//��¼��ǰ�С��е����߽�
	int row_max = rows - 1;
	int col_max = cols - 1;

	//��¼��ǰ���ڵ��С���
	int row_cur = 0;
	int col_cur = 0;


	while (elem-->0)
	{
		//�Ƚ���ǰԪ��β�嵽ret������
		ret.push_back(matrix[x][y]);

		//�����ߣ��ߵ��߽�ֹͣ�����������ƶ�һ��
		if (x == row_cur)
		{
			if (y < col_max)//��ǰ�е���û���꣬����
			{
				y++;
			}
			else if (y == col_max) //��ǰ�������ˣ����в��䣬������һ��
			{
				x++;
			}
			continue;
		}

		//������
		if (y == col_max)
		{
			if (x < row_max)//��ǰ�е��л�û���꣬����
			{
				x++;
			}
			else if (x == row_max)//��ǰ�е��������ˣ�����ǰһ��
			{
				y--;
			}
			continue;

		}

		//������
		if (x == row_max)
		{
			if (y > col_cur)//��ǰ�е���û���꣬����
			{
				y--;
			}
			else if (y == col_cur)//��ǰ�е��������ˣ�������һ��
			{
				x--;
			}
			continue;

		}

		//������
		if (y == col_cur)
		{
			if (x > row_cur + 1)//��ǰ�е���û���꣬����
			{
				x--;
			}
			else if (x == row_cur + 1)//�����������ˣ�˵��һȦ�����ˣ���ô���߽綼��СһȦ,���Ҽ�¼��ǰ���и�����1
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