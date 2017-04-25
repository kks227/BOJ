#include <cstdio>
using namespace std;

int main(){
	char addr[9];
	sprintf(addr, "%x", new int);
	int temp = 0;
	for(int i=0; i<8; i++)
		temp = (temp + addr[i]) % 2;
	puts(temp ? "Yonsei" : "Korea");
}