#include <cstdio>
using namespace std;

int digitSum(int n, int m){
	int result = 0;
	while(n){
		result += n%m;
		n /= m;
	}
	return result;
}

int main(){

	int temp;
	for(int i=1000; i<10000; i++){
		temp = digitSum(i, 10);
		if(temp==digitSum(i, 12) && temp==digitSum(i, 16)) printf("%d\n", i);
	}

	return 0;
}