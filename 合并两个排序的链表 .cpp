// ��ָoffer���ϲ�������
//��Ŀ�����������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
//
//�������������������е�һ��Ԫ�ؽ�С�Ľ�����������ͷ��Ȼ�����αȽ����������Ԫ�أ���С��β������������(Ϊ��β�巽�㣬����ʹ����βָ�����������β)��ֻҪ��һ�������ˣ��ͽ���һ��(������ʣ��Ԫ�ص�����)֮������������β�ϡ�


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	//�������һ���ǿգ���ô�ͷ�������һ��
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;

	ListNode* head;//�������ͷ
	ListNode* tail;//�������β

	//���Ǹ�����ĵ�һ��Ԫ��С���������������ͷ
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
	tail = head;//���Ҹտ�ʼ��tailҲָ���һ���ڵ�

	//ֻҪ��һ�������ͽ���(���űȽϣ������������н�С��Ԫ��β������������)
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
		//�������ĸ�����С��β����ƶ��������tailָ��
		tail = tail->next;
	}

	//�����⣬������ĳһ�����������ˣ��򽫲�����Ǹ�����ֱ������������tail�ĺ���
	if (pHead1 != nullptr)
	{
		tail->next = pHead1;
	}
	if (pHead2 != nullptr)
	{
		tail->next = pHead2;
	}

	return head;//��󷵻��������ͷ
}