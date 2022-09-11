#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct Dnode{
	int data;
	struct Dnode *prior;
	struct Dnode *next;
}DNode, *DLinkList;

DLinkList InitDList(){
//	DNode *head;
	DNode *head = (DNode *)malloc(sizeof(DNode));
	head->data = 362;
	head->next = NULL;
	head->prior = NULL;
}

DLinkList HeadCreat(int *nums, int size){
	DLinkList L = InitDList();
	DNode *p = L;
	for(int i = 0; i < size; i++){
		DNode *q = (DNode *)malloc(sizeof(DNode));
		q->data = nums[i];
		q->next = p->next;
		//**********Attention**********
		if(p->next){
			p->next->prior = q;	
		}
		p->next = q;
		q->prior = p;
	}
	return L;
}

DLinkList TailCreat(int *nums, int size){
	DLinkList L = InitDList();
	DNode *tail = L;
	for(int i = 0; i < size; i++){
		DNode *q = (DNode *)malloc(sizeof(DNode));
		q->data = nums[i];
		q->next = NULL;
		q->prior = tail;
		tail->next = q;
		tail = tail->next;
	}
	return L;
}
void PrintDLinkList(DLinkList L){
	DNode *p = L->next;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main(){
	int nums[6] = {1, 2, 3, 4, 5, 6};
	DLinkList L1 = HeadCreat(nums, 6);
	DLinkList L2 = TailCreat(nums, 6);
	PrintDLinkList(L1);
	PrintDLinkList(L2);
	
	
	return 0;
}
