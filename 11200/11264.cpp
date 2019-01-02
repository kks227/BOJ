#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		char op[4];
		double W[2], B;
		scanf("%s %lf %lf %lf", op, W, W+1, &B);
		bool X[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
		bool A[4] = {0, op[0]=='O', op[0]=='O', 1};
		bool result = true;
		for(int i = 0; i < 4; ++i)
			if((X[i][0]*W[0]+X[i][1]*W[1]+B >= 0) != A[i]) result = false;
		puts(result ? "true" : "false");
	}
}