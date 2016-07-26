#include <cstdio>
using namespace std;

int main(){
	int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int M, D;
	char str[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	scanf("%d %d", &D, &M);
	int n = 3;
	for(int i=0; i<M-1; i++)
		n += day[i];
	n += D;
	puts(str[n%7]);
}