#include <iostream>
using namespace std;

int digit_n(int val, int n){
	for(int i=0; i<n; i++)
		val /= 10;
	return val % 10;
}
 
int main(){
 
    int N;
    cin >> N;
	if(N < 10){
		cout << "NO" << endl;
		return 0;
	}

	bool flag = false;
	int digit = 0;
	int front, rear;
	int temp = N;
	while(temp){
		digit++;
		temp /= 10;
	}
	for(int i=0; i<digit-1; i++){
		front = rear = 1;
		for(int j=0; j<=i; j++)
			front *= digit_n(N, j);
		for(int j=i+1; j<digit; j++)
			rear *= digit_n(N, j);
		if(front == rear){
			flag = true;
			break;
		}
	}

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
 
    return 0;
}