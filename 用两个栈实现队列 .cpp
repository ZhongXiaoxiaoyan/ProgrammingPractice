//
//��Ŀ��������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�

//������ȷ��stack1Ϊ��ջ��stack2Ϊ��ջ������������Զ����stack1���룬��������Զ����stack2�г���
//���ǵ�stack2Ϊ��ʱ�������ݵô�stack1�е����ݣ�����Ϊ��ջ�е�Ԫ�ص�һ��ͽ����ݵ����ˣ�
//�Ϳ��Դﵽ���е�Ч��



class Deque{

	void push(int node) {
		//ָ��stack1Ϊ��ջ��stack2Ϊ��ջ
		stack1.push(node);
	}

	int pop() {
		int top = 0;
		if (stack2.empty())//��ջջΪ�գ���Ҫ������
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		//��ջ���գ����ߵ������ˣ�ֱ�ӳ�
		top = stack2.top();
		stack2.pop();
		return top;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
}