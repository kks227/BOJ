#include <cstdio>
using namespace std;

int main(){
	while(1){
		char P[32];
		scanf("%s", P);
		if(P[0] == '#') break;
		int i, cnt = 0;
		for(i=0; P[i]!='o' && P[i]!='e'; i++)
			if(P[i]-'0') cnt++;
		if(P[i]=='o' && cnt%2==0 || P[i]=='e' && cnt%2==1) P[i] = '1';
		else P[i] = '0';
		puts(P);
	}
}