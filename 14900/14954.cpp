#include <cstdio>
#include <set>
using namespace std;

int main(){
	int curr;
	scanf("%d", &curr);
	set<int> S;
	S.insert(curr);
	while(1){
		int next = 0;
		do{
			next += (curr%10)*(curr%10);
			curr /= 10;
		}while(curr);
		if(next == 1){
			puts("HAPPY");
			return 0;
		}
		if(S.count(next)) break;
		S.insert(next);
		curr = next;
	}
	puts("UNHAPPY");
}