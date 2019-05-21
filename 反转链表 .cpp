// 剑指offer：输入一个链表，反转链表后，输出新链表的表头

// 分析：

// 方法（1）：更改next指针域法。当没有节点或者只有一个结点时，直接返回这个节点；
// 否则至少有两个节点时，用三个指针n1, n2, n3, n1指向第一个节点，n2指向第二个节点，n3指向第三节点(可能为空)，
// 每次修改n2的next让其指向n1, 然后利用n3保存下一个节点，
// 然后利用n2移动n1和n2的相对位置（需要注意的是，最开始要将n1的next域置空，因为它反转后要做尾节点）。

ListNode* ReverseList(ListNode* pHead) {

	//没有节点，或者只有一个节点，则就返回这个节点
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	//来到这说明至少有2个节点
	ListNode* n1 = pHead;//n1指向第一个节点
	ListNode* n2 = n1->next;//n2指向第二个节点
	n1->next = nullptr;//反转后第一个节点要做尾节点，因此它的next指向nullptr

	ListNode* n3 = n2->next;//n3指向第三个节点(可能为空)

	while (n2 != NULL)//因为每次修改的是n2的next指向，因此当n2为空时，n1是头结点
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;

		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	return n1;
}


// 方法（2）：头插法。让cur指向当前结点，并且保存cur的下一个节点，创建一个新链表的头指针newnode,每次将cur拿下来头插，头插完后将newnode指针始终要做头，直到cur为空，即原链表结点被插完，此时newnode就是新链表的头。

ListNode* ReverseList(ListNode* pHead) {

	//头插法

	ListNode* cur = pHead;//cur指向第一个节点
	ListNode* newnode = nullptr;

	while (cur)
	{
		ListNode* next = cur->next;//保存cur的下一个节点
		cur->next = newnode;//以newnode为新链表头，将cur拿下来头插
		newnode = cur;//头插后，newnode要始终做头
		cur = next;//移动cur到上一次保存的cur的下一个节点，继续为头插做准备
	}
	return newnode;//当cur为空时，说明所有节点头插完了，此时newnode就是新链表的的头
}