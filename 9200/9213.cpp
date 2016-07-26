#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000000

int main(){

	int *divsum = new int[MAX+1];
	memset(divsum, 0, (MAX+1)*sizeof(int));
	for(int i=2; i<=MAX; i++){
		divsum[i]++;
		for(int j=i*2; j<=MAX; j+=i)
			if(j%i == 0) divsum[j] += i;
	}

	int start, stop, badness, cnt, T=0;
	while(1){
		T++;
		cin >> start >> stop >> badness;
		if(start==0) break;
		cnt = 0;
		for(int i=start; i<=stop; i++){
			if(abs(i-divsum[i]) <= badness) cnt++;
		}
		cout << "Test " << T << ": " << cnt << endl;
	}
	delete[] divsum;

    return 0;
}