#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct node{
	int data;
	struct node * next;
} Node, *LinkList;

LinkList InitList()
{
	Node *L;
	L = (Node *)malloc(sizeof(Node));
	L->data = 362;
	L->next = NULL;
	return L; 
}
//Node InitList()
//{
//	Node L;
//	L.data = 362;
//	L.next = NULL;
//	return L; 
//}

LinkList HeadCreat(int *nums, int n){
	LinkList L = InitList();
	Node *p = L;
	
	for(int i = 0; i < n; i++){
		Node *q;
		q = (Node *)malloc(sizeof(Node));
		q->data = nums[i];
		q->next = p->next;
		p->next = q;
	}
	return L;
}

LinkList TailCreat(int *nums, int n){
	LinkList L = InitList();
	Node *p = L;
	
	for(int i = 0 ; i < n; i++){
		Node *q;
		q = (Node *)malloc(sizeof(Node));
		p->next = q;
		q->data = nums[i];
		p = q;
	}
	p->next = NULL;
	return L;
}

Node * SearchByNum(LinkList L, int num){
	//计数，初值为1 
	int n = 1;
	Node *p = L->next;
	if(num < 0) return NULL;
	if(num == 0) return L;
	while(p && n < num){
		p = p->next;
		n++;
	}
	return p;
}

Node  * SearchByData(LinkList L, int num){
	if(L->next == NULL) return NULL;
	Node *p = L->next;
	while(p){
		if(p->data == num){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

bool DeleElem(LinkList &L, int i){
	Node *p = SearchByNum(L, i-1);
	if(p == NULL){
		cout << "Wrong Location!!!" << endl;
	}
	Node *q = p->next;
	p->next = q->next;
	free(q);
	return true;
}

int Length(LinkList L){
	Node *p = L->next;
	int sum = 0;
	while(p){
		sum++;
		p = p->next;
	}
	return sum;
} 

bool PrintList(LinkList L){
	if(L->next == NULL){
		cout << "NULL LinkList!!!" << endl;
		return false;
	}
	Node *p = L->next;
	while(p != NULL){
		cout << p->data << " ";
		p= p->next;
	}
	cout << endl;
	return true;
}

bool PrintNode(Node *p){
	if(p){
		cout << p->data << endl;
		return true;
	}
	else
		cout << "NULL Node!!!"  << endl;
	return false;
}

int main(){
	int nums[6] = {1, 2, 3, 4, 5, 6}; 
	//测试尾插法和头插法 
	LinkList L1 = TailCreat(nums, 6);
	LinkList L2 = HeadCreat(nums, 6);
	
	PrintList(L1);
	PrintList(L2);
	
	//测试按序号查找 
	Node *p = SearchByNum(L1, 2);
	PrintNode(p);
	cout << "p->data : " << p->data << endl << endl;
	
	//测试按值查找
	Node *q = SearchByData(L1, 3);
	PrintNode(q);
	cout << "q->data : " << q->data << endl << endl;
	
	//测试删除元素 
	DeleElem(L1, 3);
	PrintList(L1);
	
	//测试求表长 
	cout << "链表L1的表长： " << Length(L1) << endl;
}
