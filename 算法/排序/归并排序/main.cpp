#include<iostream>
#include<malloc.h>
#define number 6
using namespace std;
int Merge(int *arr, int left, int mid, int right);

//2022/06/27 02点04分 


void sort(int *arr, int left, int right){
	if(right > left){
		int mid = (left + right) / 2;
		cout << left << "  --  " << right << endl;
		sort(arr, left, mid);
		
		sort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}
}

int Merge(int *arr, int left, int mid, int right){
	
	int b[right];
	//把arr中 '所有元素' 复制到b 
	for(int i = left; i <= right; i++){
		b[i] = arr[i];
	}
	
	//用于遍历两个有序分组的指针 
	int i = left, j = mid + 1;
	int index = left;    
	
	while(i <= mid && j <= right){
		if(b[i] <= b[j]){
			arr[index] = b[i];
			i++;
		}
		else{
			arr[index] = b[j];
			j++;
		}
		index++;
	}
	
	while(i <= left)  arr[index++] = b[i++];
	while(j <= right) arr[index++] = b[j++];
	
}
int main(){
	cout << "请输入待排序数的个数：" << endl;
	int n;
	cin >> n;
	int nums[n];
	cout << "请输入待排序数：" << endl;
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(nums, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}
