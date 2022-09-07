#include<iostream>
#include<malloc.h>
using namespace std;
 
typedef struct node{
	int data;
	struct node *next;
}Stack, *LinkStack;

//带头结点的链栈 
void InitLinkStack(LinkStack &L){
	L = (Stack *)malloc(sizeof(Stack));
	L->data = 362;
	L->next = NULL;
}

bool StackEmpty(LinkStack L){
	if(L->next == NULL)
		return true;
	return false;
}

//头插法 把num压入栈 
bool Push(LinkStack &L, int num){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->data = num;
	s->next = L->next;
	L->next = s;
	cout << "Push: " << s->data << " \n";
	return true;
}

bool Pop(LinkStack &L, int &e){

	if(StackEmpty(L)){
		return false;
	}
	Stack *p = L->next;
	e = p->data;
	L->next = L->next->next;
	cout << "Pop： " << e << endl; 
	free(p);
	return true;
}

bool GetTop(LinkStack L, int &e){
	if(StackEmpty(L)){
		return false;
	}
	e = L->next->data;
	cout << "栈顶为： " << e << " \n";
	return true;
}

bool PrintStack(LinkStack L){
	if(StackEmpty(L)){
		return false;
	}
	cout << "输出栈中剩余元素："; 
	Stack *s = L->next;
	while(s){
		cout << s->data << " ";
		s = s->next;
	}
	cout << endl;
	return true;
}
int main(){
	LinkStack L;
	InitLinkStack(L);

	for(int i = 0; i < 6; i++){
		Push(L, i);
	}
//	int e;
//	for(int i = 0; i < 6; i++){
//		Pop(L, e);
//	}
//
//	GetTop(L, e);
	PrintStack(L);
}

