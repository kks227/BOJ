#include <iostream>
using namespace std;

int main(){

	int A, B, C, N;
	cin >> A >> B >> C;
	N = A*B*C;

	int digit[10] = {0};
	do{
		digit[N%10]++;
		N/=10;
	}while(N);

	for(int i=0; i<10; i++)
		cout << digit[i] << endl;

    return 0;
}