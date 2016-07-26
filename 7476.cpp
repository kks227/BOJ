#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int Alen, Blen, A[500], B[500], dp[500][500], back[500][500];

int LCIS(int Apos, int Bpos){
	if(Apos==Alen || Bpos==Blen) return 0;
	int &ret = dp[Apos][Bpos];
	if(ret != -1) return ret;

	ret = 1;
	back[Apos][Bpos] = Alen*1000 + Blen;
	for(int i=Apos+1; i<Alen; i++){
		if(A[Apos] >= A[i]) continue;
		for(int j=Bpos+1; j<Blen; j++){
			if(A[i] == B[j]){
				int temp = LCIS(i, j) + 1;
				if(ret < temp){
					ret = temp;
					back[Apos][Bpos] = i*1000 + j;
				}
				break;
			}
		}
	}
	return ret;
}

void trace(int Apos, int Bpos){
	if(Apos==Alen || Bpos==Blen) return;
	printf("%d ", A[Apos]);
	trace(back[Apos][Bpos]/1000, back[Apos][Bpos]%1000);
}

int main(){
	scanf("%d", &Alen);
	for(int i=0; i<Alen; i++)
		scanf("%d", A+i);
	scanf("%d", &Blen);
	for(int i=0; i<Blen; i++)
		scanf("%d", B+i);

	memset(dp, -1, sizeof(dp));
	int result = 0, start = -1;
	for(int i=0; i<Alen; i++){
		for(int j=0; j<Blen; j++){
			if(A[i] == B[j]){
				int temp = LCIS(i, j);
				if(result < temp){
					result = temp;
					start = i*1000 + j;
				}
				break;
			}
		}
	}
	printf("%d\n", result);
	if(start != -1) trace(start/1000, start%1000);
}