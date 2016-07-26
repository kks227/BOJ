#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MODULA 1234567

int cache[1001][10];

int password(int length, int start){
	int &ret = cache[length][start];
	if(ret != -1) return ret;
	if(length == 0) return ret = 0;
	if(length == 1) return ret = 1;

	ret = 0;
	if(start==2 || start==4) ret += password(length-1, 1);
	if(start==1 || start==3 || start==5) ret += password(length-1, 2);
	if(start==2 || start==6) ret += password(length-1, 3);
	if(start==1 || start==5 || start==7) ret += password(length-1, 4);
	if(start==2 || start==4 || start==6 || start==8) ret += password(length-1, 5);
	if(start==3 || start==5 || start==9) ret += password(length-1, 6);
	if(start==4 || start==8 || start==0) ret += password(length-1, 7);
	if(start==5 || start==7 || start==9) ret += password(length-1, 8);
	if(start==6 || start==8) ret += password(length-1, 9);
	if(start==7) ret += password(length-1, 0);
	return ret %= MODULA;
}

int main(){

	int T, N, result;
	scanf("%d", &T);
	memset(cache, -1, sizeof(int)*1001*10);
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		result = 0;
		for(int j=0; j<10; j++)
			result += password(N, j);
		printf("%d\n", result % MODULA);
	}

	return 0;
}