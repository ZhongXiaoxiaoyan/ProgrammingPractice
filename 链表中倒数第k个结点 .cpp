// 剑指offer：输入一个链表，输出该链表中倒数第k个结点。

//分析：快慢指针法。快慢指针一开始都指向第一个节点，先让快指针走k步，然后快慢指针一起走，当快指针走到空时，慢指针走到倒数第k个节点。

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* slow = pListHead;
	ListNode* fast = slow;//fast和slow都指向第一个节点

	while (k--)
	{
		if (fast)//判断的原因是可能k还没减完，fast为空了，即一共都不到k个数据
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}
	}
	//slow与fast一起开始走，当fast为空，slow指向倒数第k
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}