// ��ָoffer������һ����������������е�����k����㡣

//����������ָ�뷨������ָ��һ��ʼ��ָ���һ���ڵ㣬���ÿ�ָ����k����Ȼ�����ָ��һ���ߣ�����ָ���ߵ���ʱ����ָ���ߵ�������k���ڵ㡣

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	ListNode* slow = pListHead;
	ListNode* fast = slow;//fast��slow��ָ���һ���ڵ�

	while (k--)
	{
		if (fast)//�жϵ�ԭ���ǿ���k��û���꣬fastΪ���ˣ���һ��������k������
		{
			fast = fast->next;
		}
		else
		{
			return NULL;
		}
	}
	//slow��fastһ��ʼ�ߣ���fastΪ�գ�slowָ������k
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}