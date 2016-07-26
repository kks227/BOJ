#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int P = 10000000;

bool np[P] = {1, 1};
vector<int> prime1;
set<int> prime2;
int N, val[6], maxR = -1, minR = 0x7FFFFFFF;

bool isPrime(int n){
	if(n <= 0) return false;
	if(n < P) return !np[n];
	if(prime2.find(n) != prime2.end()) return true;
	for(int p: prime1)
		if(n%p == 0) return false;
	prime2.insert(n);
	return true;
}

void scanResult(int n){
	if(n == 1){
		if(isPrime(val[0])){
			maxR = max(maxR, val[0]);
			minR = min(minR, val[0]);
		}
		return;
	}
	int a, b;
	for(int i=0; i<n-1; i++){
		a = val[i];
		for(int j=i+1; j<n; j++){
			b = val[j];
			val[j] = val[n-1];

			val[i] = a+b;
			scanResult(n-1);
			val[i] = a-b;
			scanResult(n-1);
			val[i] = b-a;
			scanResult(n-1);
			val[i] = a*b;
			scanResult(n-1);
			if(b != 0){
				val[i] = a/b;
				scanResult(n-1);
			}
			if(a != 0){
				val[i] = b/a;
				scanResult(n-1);
			}

			val[n-1] = val[j];
			val[j] = b;
		}
		val[i] = a;
	}
}

int main(){
	for(int i=4; i<P; i+=2)
		np[i] = true;
	prime1.push_back(2);
	for(int i=3; i<P; i+=2){
		if(np[i]) continue;
		prime1.push_back(i);
		if(1LL*i*i >= P) continue;
		for(int j=i*i; j<P; j+=i*2)
			np[j] = true;
	}

	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	scanResult(N);
	if(maxR == -1) puts("-1");
	else printf("%d\n%d\n", minR, maxR);
}