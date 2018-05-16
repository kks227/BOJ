#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int L, R, A;
	scanf("%d %d %d", &L, &R, &A);
	if(L < R) swap(L, R);
	if(L-R <= A) printf("%d\n", L*2 + (A-(L-R))/2*2);
	else printf("%d\n", 2*(R+A));
}