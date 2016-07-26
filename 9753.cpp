#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int main(){

	int T, K;
	scanf("%d", &T);

	set<int> mtp;
	vector<int> prime;
	bool isP[100000];
	memset(isP, 1, 100000);
	prime.push_back(2);
	int len = 1;
	for(int i=3; i<100000; i+=2){
		if(!isP[i]) continue;
		prime.push_back(i);
		for(int j=0; j<len; j++){
			if((long long)i*prime[j] > 100001) break;
			mtp.insert(i*prime[j]);
		}
		len++;
		if((long long)i*i >= 100000) continue;
		for(int j=i*i; j<100000; j+=i)
			isP[j] = false;
	}

	set<int>::iterator iter;
	for(int t=0; t<T; t++){
		scanf("%d", &K);
		iter = mtp.lower_bound(K);
		printf("%d\n", *iter);
	}

	return 0;
}