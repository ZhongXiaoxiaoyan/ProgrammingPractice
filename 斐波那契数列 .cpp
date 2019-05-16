//题目：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。

//n <= 39

//分析：

//方法（1）：可以用数组将每个斐波那契数列值存起来
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

//方法（2）：用循环计算
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