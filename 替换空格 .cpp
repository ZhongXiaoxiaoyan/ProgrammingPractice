//
//题目描述

//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy。

//思路：先计算字符串中的空格数count，然后开辟一块新的内存空间大小为length + count * 2，
//然后从头开始拷贝新的字符串，遇到空格就替换成'%', '2', '0'，最后把替换后的字符串地址和源串拷贝过去。

//

void replaceSpace(char *str, int length)
{

	char* s = str;
	int count = 0;
	while (*s != '\0')
	{
		if (*s == ' ')
		{
			++count;
		}
		++s;
	}

	char* src = str;
	char* start = (char*)malloc(length + 2 * count + 1);
	char* cur = start;
	while (*src != '\0')
	{
		if (*src == ' ')
		{
			*start++ = '%';
			*start++ = '2';
			*start++ = '0';
			src++;
		}
		else
			*start++ = *src++;
	}
	*start = '\0';
	strcpy(str, cur);

}