//剑指offer：调整数组顺序使奇数位于偶数前面


//题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//
//分析：不能前后指针法，前面的指针找到偶数停下来，后面的指针找到奇数停下来，然后对应元素交换，因为这样会改变奇偶数的相对位置。
//
//方法（1）：用两个下标odd, even, even遍历数组，遇到偶数继续往后走，遇到奇数就将该奇数赋给odd对应位置，然后odd往后移动（先将从odd开始的位置的所有元素往后挪动一个，这样做的目的是能够保持偶数相对位置不变）。这个思路也就是使得odd前面的都是奇数，而且相对位置不变，而odd与even之间的都是偶数，然后even遇到奇数停下来，并将其放到odd位置，并且前提是将odd位置上的偶数向后挪动保证偶数相对位置不变，这样当even走到最后时，就使得odd之前的都是奇数，odd与even之间的都是偶数。


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
//方法（2）：类似于冒泡排序，从头开始，相邻元素只要是前偶后奇就交换，不同的是内循环每次都从头开始，防止一开始就有许多连续的偶数情况

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



//方法（3）：开辟一个与原数组一样大的vector, 从头遍历一遍将奇数放在前面，然后再遍历一遍，将偶数接着放在后面。

void reOrderArray(vector<int> &array) {

	vector<int> v(array.size());
	int end = array.size() - 1;
	int j = 0;

	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] % 2 != 0)//奇数
		{
			v[j] = array[i];
			j++;
		}
	}

	for (int i = 0; i<array.size(); i++)
	{
		if (array[i] % 2 == 0)//偶数
		{
			v[j] = array[i];
			j++;
		}
	}
	array = v;
}

