#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;
 
class ArrayQueue {
public:
	ArrayQueue(int maxsize = 100) :maxsize(maxsize)
	{
		myqueue = new int[maxsize];
		assert(myqueue);//断言处理，若申请内存失败，则引发中断
		curSize = 0;
		this->Front = 1;
		tail = 0;
	}
	~ArrayQueue()
	{
		delete myqueue;
	}
	void push(int data);
	void pop();
	int front();
	bool empty();
	int size();
protected:
	int maxsize;//最大容量
	int* myqueue;//队列数组
	int Front; //指向队头元素
	int tail;//指向队尾元素
	int curSize;//队列中的元素个数
};
 
int main()
{
	int temp[] = { 3,5,7,1,3,6 };
	ArrayQueue que(20);
	for (int i = 0; i < 6; i++) que.push(temp[i]);
 
	while (que.empty() != true)
	{
		cout << que.front() << endl;
		que.pop();
	}
 
	return 0;
}
 
void ArrayQueue::push(int data)
{
	if (curSize < maxsize)
	{
		myqueue[++tail] = data;
		curSize++;
	}
	else cout << "队列已满，无法插入" << endl;
}
 
void ArrayQueue::pop()
{
	if (curSize > 0)
	{
		Front++;
		--curSize;
	}
	else cout << "队列已空，无法出队" << endl;
}
 
int ArrayQueue::front()
{
	return myqueue[Front];
}
 
bool ArrayQueue::empty()
{
	if (curSize == 0)
		return true;
	return false;
}
 
int ArrayQueue::size()
{
	return curSize;
}
 