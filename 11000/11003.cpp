#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, L, A[5000000];
	deque<int> D;
	scanf("%d %d", &N, &L);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		while(!D.empty() && D.back() > A[i]) D.pop_back();
		D.push_back(A[i]);
		if(i >= L && A[i-L] == D.front()) D.pop_front();
		printf("%d ", D.front());
	}
}