// ��ָoffer������һ��������ת��������������ı�ͷ

// ������

// ������1��������nextָ���򷨡���û�нڵ����ֻ��һ�����ʱ��ֱ�ӷ�������ڵ㣻
// ���������������ڵ�ʱ��������ָ��n1, n2, n3, n1ָ���һ���ڵ㣬n2ָ��ڶ����ڵ㣬n3ָ������ڵ�(����Ϊ��)��
// ÿ���޸�n2��next����ָ��n1, Ȼ������n3������һ���ڵ㣬
// Ȼ������n2�ƶ�n1��n2�����λ�ã���Ҫע����ǣ��ʼҪ��n1��next���ÿգ���Ϊ����ת��Ҫ��β�ڵ㣩��

ListNode* ReverseList(ListNode* pHead) {

	//û�нڵ㣬����ֻ��һ���ڵ㣬��ͷ�������ڵ�
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	//������˵��������2���ڵ�
	ListNode* n1 = pHead;//n1ָ���һ���ڵ�
	ListNode* n2 = n1->next;//n2ָ��ڶ����ڵ�
	n1->next = nullptr;//��ת���һ���ڵ�Ҫ��β�ڵ㣬�������nextָ��nullptr

	ListNode* n3 = n2->next;//n3ָ��������ڵ�(����Ϊ��)

	while (n2 != NULL)//��Ϊÿ���޸ĵ���n2��nextָ����˵�n2Ϊ��ʱ��n1��ͷ���
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


// ������2����ͷ�巨����curָ��ǰ��㣬���ұ���cur����һ���ڵ㣬����һ���������ͷָ��newnode,ÿ�ν�cur������ͷ�壬ͷ�����newnodeָ��ʼ��Ҫ��ͷ��ֱ��curΪ�գ���ԭ�����㱻���꣬��ʱnewnode�����������ͷ��

ListNode* ReverseList(ListNode* pHead) {

	//ͷ�巨

	ListNode* cur = pHead;//curָ���һ���ڵ�
	ListNode* newnode = nullptr;

	while (cur)
	{
		ListNode* next = cur->next;//����cur����һ���ڵ�
		cur->next = newnode;//��newnodeΪ������ͷ����cur������ͷ��
		newnode = cur;//ͷ���newnodeҪʼ����ͷ
		cur = next;//�ƶ�cur����һ�α����cur����һ���ڵ㣬����Ϊͷ����׼��
	}
	return newnode;//��curΪ��ʱ��˵�����нڵ�ͷ�����ˣ���ʱnewnode����������ĵ�ͷ
}