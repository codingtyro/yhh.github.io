#include<iostream>
#include<malloc.h>
using namespace std;
#define MaxSize 6
typedef struct queue{
	int data[MaxSize];
	int front;
	int rear;
}Queue;

void InitQueue(Queue &q){
	q.front = 0;
	q.rear  = 0;
}

bool QueEmpty(Queue q){
	if(q.front == q.rear)
		return true;
	return false;
}

bool QueFull(Queue q){
	if((q.rear + 1) % MaxSize == q.front){
		return true;
	}
	return false;
}

bool EnQueue(Queue &q, int num){
	if(QueFull(q)){
		cout << "Full Queue£¡£¡£¡\nThere is no place to be placed" << endl; 
		return false;
	}
	q.data[q.rear] = num;
	//´íÎóÐ´·¨ 
	//q.rear++;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(Queue &q, int &e){
	if(QueEmpty(q)){
		cout << "Empty Queue£¡£¡£¡\nNothing is here!!!" << endl; 
		return false;
	}
	e = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

bool PrintQueue(Queue q){
	if(QueEmpty(q)){
		cout << "Empty Queue£¡£¡£¡\nThere is nothing to be printed!!!" << endl;
		return false;
	}
	if(q.rear > q.front){
		for(int i = q.front; i < q.rear; i++){
			cout << q.data[i] << " ";
		}
	}
	else{
		for(int i = q.front; i <= MaxSize-1; i++){
			cout << q.data[i] << " ";
		}
		for(int i = 0; i < q.rear; i++){
			cout << q.data[i] << " ";
		}
	}
	cout << endl;
}

int main(){
	Queue q;
	InitQueue(q);
	for(int i = 0; i < 6; i++){
		EnQueue(q, i);
	}
	PrintQueue(q);
	int e;
	DeQueue(q, e);
	cout << "q.front: " << q.front  << "q.rear: " << q.rear << endl;
	DeQueue(q, e);
	PrintQueue(q);
	EnQueue(q, 77);
	EnQueue(q, 30);
	PrintQueue(q);
	return 0;
}
