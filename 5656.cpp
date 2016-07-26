#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		int a, b;
		char op[3];
		scanf("%d %s %d", &a, op, &b);
		if(op[0] == 'E') break;

		bool result;
		if(op[0] == '=') result = a==b;
		else if(op[0] == '!') result = a!=b;
		else if(op[0] == '>'){
			if(op[1] == '=') result = a>=b;
			else result = a>b;
		}
		else{
			if(op[1] == '=') result = a<=b;
			else result = a<b;
		}
		printf("Case %d: %s\n", t, result ? "true" : "false");
	}
}