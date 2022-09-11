#include<iostream>
#include<malloc.h>
using namespace std;
//无头结点链队 入队时需要考虑队列为空的情况 
//出队时要考虑只有一个元素的情况 
typedef struct LinkNode{
	int data;
	struct LinkNode* next;
}LNode;

typedef struct Queue{
	LNode* front, * rear;
}Queue;

void InitQueue(Queue &q){
	q.front = NULL;
	q.rear  = NULL; 
}

bool EmptyQueue(Queue q){
	if(q.front == NULL){
		return true;
	}	
	return false;
}

bool EnQueue(Queue &q, int num){
	LNode* node = (LNode* )malloc(sizeof(LNode));
	node->data = num;
	node->next = NULL;
	
	if(EmptyQueue(q)){
		q.front = q.rear = node;
		return true;
	}
	q.rear->next = node;
	q.rear = node;
	return true;
}

bool DeQueue(Queue &q, int &e){
	if(EmptyQueue(q)){
		cout << "Empty Queue??????\nNothing is here!!!!!!" << endl;
		return false;
	}
	LNode* p =  q.front;
	e = p->data;
	q.front = q.front->next;
	if(q.rear == p){
		q.rear  = NULL;
		q.front = NULL;
	}
	p->next = NULL;
	free(p);
	return true;
}

bool PrintQueue(Queue q){
	if(EmptyQueue(q)){
		cout << "Empty Queue??????\nThere is nothing to be printed!!!" << endl;
		return false;
	}
	LNode* p = q.front;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	
	return true;
}

int main(){
	Queue q;
	InitQueue(q);
	for(int i = 0; i < 6; i++){
		EnQueue(q, i);
	}
//	EnQueue(q, 1);
	PrintQueue(q);
	
	int e;
	DeQueue(q, e);
	DeQueue(q, e);
	DeQueue(q, e);
	DeQueue(q, e);
	DeQueue(q, e);
	DeQueue(q, e);
	EnQueue(q, 11);
	cout << "e: " << e << endl;
	PrintQueue(q);
	return 0;
}
