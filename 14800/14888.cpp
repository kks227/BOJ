#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, pos, val, A[11], cnt[4], r1 = -INF, r2 = INF;
function<int(int, int)> func[4] = {
	[](int a, int b){ return a+b; },
	[](int a, int b){ return a-b; },
	[](int a, int b){ return a*b; },
	[](int a, int b){ return (a>0 ? a/b : -a/b*-1); }
};

void dfs(){
	if(pos == N){
		r1 = max(r1, val);
		r2 = min(r2, val);
		return;
	}
	
	int soFar = val;
	for(int i=0; i<4; i++){
		if(cnt[i] == 0) continue;

		cnt[i]--;
		val = func[i](soFar, A[pos]);
		pos++;
		dfs();
		cnt[i]++;
		val = soFar;
		pos--;
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	for(int i=0; i<4; i++)
		scanf("%d", cnt+i);
	val = A[0];
	pos = 1;
	dfs();
	printf("%d\n%d\n", r1, r2);
}