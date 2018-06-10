#include <cstdio>
using namespace std;

int main(){
	int S[2];
	bool wrong[2] = {0};
	scanf("%d %d", S, S+1);
	for(int i=0; i<2; i++){
		for(int j=0; j<S[i]; j++){
			int a, b;
			scanf("%d %d", &a, &b);
			if(a != b) wrong[i] = true;
		}
	}
	if(wrong[0]) puts("Wrong Answer");
	else puts(wrong[1] ? "Why Wrong!!!" : "Accepted");
}