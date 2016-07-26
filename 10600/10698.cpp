#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int X, Y, Z;
		char op;
		scanf("%d %c %d = %d", &X, &op, &Y, &Z);
		bool result;
		if(op == '+') result = X+Y == Z;
		else result = X-Y == Z;
		printf("Case %d: %s\n", t, result ? "YES" : "NO");
	}
}