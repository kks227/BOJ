#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	vector<bool> np(B+1, false);
	vector<int> result;
	for(int i=3; i<=B; i+=2){
		if(np[i]) continue;
		if(i >= A){
			int a = i, b = 0;
			while(a){
				b = b*10 + a%10;
				a /= 10;
			}
			if(b == i) result.push_back(i);
		}
		if(1LL*i*i > B) continue;
		for(int j=i*i; j<=B; j+=i*2)
			np[j] = true;
	}
	for(int p: result)
		printf("%d\n", p);
	puts("-1");
}