//
//题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

//分析：确定stack1为入栈，stack2为出栈（即入数据永远都往stack1中入，出数据永远都从stack2中出，
//但是当stack2为空时，出数据得从stack1中倒数据），因为将栈中的元素倒一遍就将数据倒序了，
//就可以达到队列的效果



class Deque{

	void push(int node) {
		//指定stack1为入栈，stack2为出栈
		stack1.push(node);
	}

	int pop() {
		int top = 0;
		if (stack2.empty())//出栈栈为空，需要倒数据
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		//出栈不空，或者倒过来了，直接出
		top = stack2.top();
		stack2.pop();
		return top;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
}