#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int K;
		scanf("%d", &K);
		bool result = true;
		for(int b = 1; b <= 30; ++b)
			if(K == 1<<b) result = false;
		puts(result ? "Gazua" : "GoHanGang");
	}
}