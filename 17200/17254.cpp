#include <cstdio>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 1000;
typedef tuple<int, int, char> T;

int main(){
	int N, M;
	T t[MAX];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; ++i){
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);
		t[i] = T(b, a, c);
	}
	sort(t, t+M);
	for(int i = 0; i < M; ++i)
		putchar(get<2>(t[i]));
}