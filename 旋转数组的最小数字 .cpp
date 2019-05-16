//题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{ 3, 4, 5, 1, 2 }为{ 1, 2, 3, 4, 5 }的一个旋转，该数组的最小值为1。 
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
//
//分析：非减排序的数组，就相当于是递增排序数组“”
//
//方法（1）：直接遍历，找到最小值。
//
//方法（2）：由于旋转后，前面是一个递增子序列，后面是一个递增子序列，找出不是递增的那个元素
//
//方法（3）：利用二分查找。如果中间元素值>最后一个元素值，说明最小值右半区间，
//如果中间元素<最后一个元素区间，说明最小值在左半区间，如果相等说明有相同元素，
//	需要将判断区间往前缩一下，继续判断，不断循环，
//	当二分查找的的左右区间相等了，就说明找到最小值了。

int minNumberInRotateArray(vector<int> rotateArray)
{
	int len = rotateArray.size();

	if (len == 0)
		return 0;

	int min = rotateArray[0];
	int len = rotateArray.size();

	for (int i = 1; i<len; i++)
	{
		if (rotateArray[i]<min)
		{
			min = rotateArray[i];
		}
	}

	return min;
}


int minNumberInRotateArray(vector<int> rotateArray)
{
	int len = rotateArray.size();

	if (len == 0)
		return 0;

	for (int i = 0; i<len; i++)
	{
		if (rotateArray[i] <= rotateArray[i + 1])
		{
			continue;
		}
		else
		{
			return rotateArray[i + 1];
		}
	}
	return rotateArray[0];
}

int minNumberInRotateArray(vector<int> rotateArray)
{
	int length = rotateArray.size();
	if (length == 0)
		return 0;
	int pre = 0;//第一个元素下标
	int last = length - 1;//最后一个元素下标
	while (pre < last)
	{
		int mid = (pre + last) / 2;

		//当中间元素 大于 最后一个元素，说明最小值在右半区间
		//更新pre下标
		if (rotateArray[mid] > rotateArray[last])
		{
			pre = mid + 1;
		}
		//当中间元素 小于 最后一个元素，说明最小值在左半区间
		//但是中间这个元素，可能就是最小值，因此是 last=mide,而不是
		//last=mid-1
		else if (rotateArray[mid] < rotateArray[last]) {
			last = mid;
		}
		//当中间元素 等于 最后一个元素，说明有重复元素，将区间缩小一个
		else {
			last = last - 1;
		}
	}
	return rotateArray[pre];
}