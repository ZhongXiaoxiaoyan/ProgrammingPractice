// 剑指offer：合并单链表
//题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则
//
//分析：先找两个链表中第一个元素较小的结点做新链表的头，然后依次比较两个链表的元素，将小的尾插在新链表中(为了尾插方便，这里使用了尾指针标记新链表的尾)，只要有一个结束了，就将另一个(即还有剩余元素的链表)之间挂在新链表的尾上。


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	//如果其中一个是空，那么就返回另外一个
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode* head;//新链表的头
	ListNode* tail;//新链表的尾

	//看那个链表的第一个元素小，让其做新链表的头
	if (pHead1->val<pHead2->val)
	{
		head = pHead1;
		pHead1 = pHead1->next;
	}
	else
	{
		head = pHead2;
		pHead2 = pHead2->next;
	}
	tail = head;//并且刚开始让tail也指向第一个节点

	//只要有一个结束就结束(挨着比较，将两个链表中较小的元素尾插在新链表中)
	while (pHead2 && pHead1)
	{
		if (pHead1->val<pHead2->val)
		{
			tail->next = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			tail->next = pHead2;
			pHead2 = pHead2->next;
		}
		//无论是哪个链表小，尾插后移动新链表的tail指针
		tail = tail->next;
	}

	//来到这，可能是某一个链表走完了，则将不完的那个链表直接链在新链表tail的后面
	if (pHead1 != nullptr)
	{
		tail->next = pHead1;
	}
	if (pHead2 != nullptr)
	{
		tail->next = pHead2;
	}

	return head;//最后返回新链表的头
}