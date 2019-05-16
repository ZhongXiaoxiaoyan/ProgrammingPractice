//题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

//分析：斐波那契数列问题，但是注意初值

int jumpFloor(int number) {

	//1级有1种，2级有2种，3级有3种，4级有5种
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