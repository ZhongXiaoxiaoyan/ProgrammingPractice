//剑指offer：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？


int rectCover(int number) {
	//也是斐波那契数列，n==1时1种，n==2时2种，n==3时3种...f(n)=f(n-1)+f(n-2)
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