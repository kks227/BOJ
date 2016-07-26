#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[2097152];

int main(){

	int N, M, start = 2, o, p, q;
	long long sum, temp;
	scanf("%d %d", &N, &M);
	while(start <= N) start *= 2;
	for(int m=0; m<M; m++){
		scanf("%d %d %d", &o, &p, &q);
		if(o){
			p += start-1;
			temp = q - arr[p];
			while(p){
				arr[p] += temp;
				p /= 2;
			}
		}
		else{
			p += start-1;
			q += start-1;
			if(p == q){
				printf("%lld\n", arr[p]);
				continue;
			}
			if(p > q) swap(p, q);
			sum = 0;
			while(p != q){
				if(p%2){
					sum += arr[p];
					p = p/2+1;
				}
				else p /= 2;
				if(q%2==0){
					sum += arr[q];
					q = q/2-1;
				}
				else q /= 2;
				if(p >= q){
					if(p == q) sum += arr[p];
					break;
				}
			}
			printf("%lld\n", sum);
		}
	}

	return 0;
}