#include <cstdio>
#include <set>
using namespace std;

int main(){
	int N;
	set<int> s;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		s.insert(n);
	}
	for(int n: s)
		printf("%d ", n);
}