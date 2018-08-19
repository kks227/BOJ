#include <cstdio>
using namespace std;

int main(){
	char t[4] = {'U', 'C', 'P', 'C'};
	int cnt = 0;
	do{
		char c = getchar();
		if(c < 0) break;
		if(c == t[cnt]) cnt++;
	}while(cnt < 4);
	printf("I %s UCPC\n", cnt == 4 ? "love" : "hate");
}