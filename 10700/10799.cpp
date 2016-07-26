#include <cstdio>
using namespace std;

int main(){
	char c, prev = '.';
	int sum = 0, cnt = -1;
	while((c=getchar())>'\n'){
		if(c=='(') cnt++;
		else{
			if(prev=='(') sum += cnt;
			else sum++;
			cnt--;
		}
		prev = c;
	}
	printf("%d\n", sum);
}