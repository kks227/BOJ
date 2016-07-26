#include <cstdio>
#include <utility>
using namespace std;

int main(){
	pair<int, int> P, S(2, 18);
	scanf("%d %d", &P.first, &P.second);
	if(P == S) puts("Special");
	else if(P < S) puts("Before");
	else puts("After");
}