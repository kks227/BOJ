#include <cstdio>
using namespace std;

int main(){
	int T, cnt = 0;
	scanf("%d", &T);
	for(int i = 0; i < 5; ++i){
		int val;
		scanf("%d", &val);
		if(T == val) ++cnt;
	}
	printf("%d\n", cnt);
}