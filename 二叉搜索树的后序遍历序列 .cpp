//剑指offer：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。
//题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes, 否则输出No。假设输入的数组的任意两个数字都互不相同。
//
//分析：后续遍历的最后一个数据是根结点数据，那么这个数字必将序列分成左右两部分，它大于左边所有的数据，小于右边所有的数据，其中找到这个分界点后，如果右半部分存在一个小于这个根数据的，就说明不是后续遍历，然后用同样的方式递归判断它的左子树、右子树。


bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.size() <= 0)
		return false;

	return _VerifySquenceOfBST(sequence, 0, sequence.size() - 1);

}

//判断最后一个数据是不是将数组分成左边都小于这个数，右边都大于这个数
bool  _VerifySquenceOfBST(vector<int> v, int start, int end)
{
	if (start >= end)
		return true;

	int root = v[end];

	int i = start;
	//找到第一个比根结点大的分界点
	while (v[i]<root)
	{
		i++;
	}

	//来到这说明i>=root，即i是该根结点的右子树了
	//如果右子树中存在一个值<根结点，那么不是后续，直接return false
	int j = i;
	while (j<end)
	{
		if (v[j]<root)
		{
			return false;
		}
		j++;
	}
	//来到这说明当前根结点满足 大于左边序列，小于右边序列，接下来它的左右子树也要
	//满足这个特性
	return _VerifySquenceOfBST(v, start, i - 1) && _VerifySquenceOfBST(v, i, end - 1);
}