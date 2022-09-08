#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(){

    }
    node(int data){
        this->data = data;
        this->next = nullptr;
    }

};

class LinkList{
public:
    LinkList(){}
    ~LinkList(){}
    //利用数组创建一个新的单链表。
    LinkList(int a[],int n);
    int length();
    int get(int i);
    int locate(int i);
    void insert(int i,int x);
    int remove(int i);
    void printList();

private:
    node *head,*p,*t;
};

LinkList::LinkList(int nums[],int n){
    head = new node();
    head->next = nullptr;
    for(int i = n - 1;i >= 0;i--){
        //头插法建立链表。
        p = new node();
        p->data = nums[i];
        p->next = head->next;
        head->next = p;
    }
}

int LinkList::length(){
    t = head->next;
    int sum = 0;
    while(t){
        sum++;
        t = t->next;
    }
    return sum;
}

int LinkList::get(int i){
    t = head->next;
    int sum = 0;
    while(t && sum < i){
        sum++;
        t = t->next;
    }
    return t->data;
}

int LinkList::locate(int i){
    int sum = 0;
    t = head->next;
    while(t){
        t = t->next;
        sum++;
        if(i == t->data)break;
    }
    return sum;
}

void LinkList::insert(int i,int x){
    p = new node();
    t = head -> next;
    int sum = 1;
    while(t && sum < i){
        sum++;
        t = t -> next;
    }
    p->data = x;
    p->next = t->next;//挂链
    t->next = p;//摘链
}

int LinkList::remove(int i){
    p = new node();
    t = head->next;
    int sum = 1;
    int x;
    while(t && sum < i){
        sum++;
        t = t->next;
    }
    p = t->next;
    x = p->data;
    t->next = p->next;
    delete p;
    return x;
}

void LinkList::printList(){
    t = head->next;
    while(t){
        cout << t->data << " " ;
        t = t->next;
    }
    cout << endl;
}

int main(){
    int n ;
    cout << "数组的长度为: " << endl;
    cin >> n;
    int * nums = new int[n];
    for(int i = 0;i < n;i++){
        cin >> nums[i];
    }
    LinkList list(nums,n);
    cout << endl;

    cout << "链表的长度为： " << list.length() << endl;
    cout << "链表为：" << endl;
	list.printList();
    delete []nums;
    return 0;
}

