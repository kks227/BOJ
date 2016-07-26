#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main(){

	int W, H, N, result = 0;
	int a, b, shop[101];
	scanf("%d %d %d", &W, &H, &N);
	for(int i=0; i<N+1; i++){
		scanf("%d %d", &a, &b);
		switch(a){
		case 1:
			shop[i] = 2*(W+H)-b;
			break;
		case 2:
			shop[i] = H+b;
			break;
		case 3:
			shop[i] = b;
			break;
		default:
			shop[i] = 2*H+W-b;
		}
	}
	for(int i=0; i<N; i++)
		result += min(abs(shop[N]-shop[i]), 2*(W+H)-abs(shop[N]-shop[i]));
	printf("%d\n", result);
 
    return 0;
}