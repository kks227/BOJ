#include <cstdio>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

int power(int n, int k, int m){
	if(k == 0) return 1;
	if(k == 1) return n%m;
	int temp = power(n, k/2, m);
	return temp*temp*(k%2?n:1)%m;
}

int main(){
	int N, A, D, H, MA, MD, MH, Ap, Dp, Hp, Aa, Da, Ha, nextA[101], nextD[4], nextH[1001];
	scanf("%d %d %d %d %d %d %d", &N, &A, &D, &H, &MA, &MD, &MH);
	scanf("%d %d %d %d %d %d", &Ap, &Aa, &Dp, &Da, &Hp, &Ha);
	for(int i=1; i<=100; i++) nextA[i] = power(i, Ap, 100);
	for(int i=1; i<=3; i++) nextD[i] = power(i, Dp, 3);
	for(int i=1; i<=1000; i++) nextH[i] = power(i, Hp, 1000);

	bool success = false, fail = false;
	for(int i=0; i<N && !fail; i++){
		int myDamage = max(A-MD, 1), yourDamage = max(MA-D, 1);
		if(!success && (MH-1)/myDamage > (H-1)/yourDamage) fail = true;
		else{
			A += MA; D += MD; H += MH;
			if(A > 200) success = true;
			if(success){ A %= MOD; D %= MOD; H %= MOD; }
			MA = (nextA[MA] + Aa) % 100 + 1;
			MD = (nextD[MD] + Da) % 3 + 1;
			MH = (nextH[MH] + Ha) % 1000 + 1;
		}
	}
	if(fail) puts("-1");
	else printf("%d %d %d\n", A%MOD, D%MOD, H%MOD);
}