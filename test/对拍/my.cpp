
#include<iostream>
using namespace std;
 
int main() {
	int a, b;
	cin >> a >> b;
	a += b;
	if(a % 2 == 0)a += 1;
	cout << a <<endl;
	return 0;
}
