#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;

int main(){
	char x[102];
	scanf("%s", x);
	int n = strlen(x) * (x[0]-'0');
	unordered_set<int> S;
	S.insert(n);
	while(1){
		int m = n, p = 0, q = 0;
		do{
			if(m < 10) p = n;
			m /= 10;
			++q;
		}while(m > 0);
		m = p*q;
		if(n == m){
			puts("FA");
			return 0;
		}
		if(S.find(m) != S.end()) break;
		S.insert(m);
		n = m;
	}
	puts("NFA");
}