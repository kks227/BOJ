#include <cstdio>
#include <climits>
using namespace std;

inline long long p2(long long n){ return n*n; }

int main(){
	int N, x[100], y[100];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", x+i, y+i);

	long long result = LLONG_MAX;
	int ra, rb;
	for(int a=1; a<=100; a++){
		for(int b=1; b<=100; b++){
			long long temp = 0;
			for(int i=0; i<N; i++)
				temp += p2(y[i] - a*x[i] - b);
			if(result > temp){
				result = temp;
				ra = a;
				rb = b;
			}
		}
	}
	printf("%d %d\n", ra, rb);
}