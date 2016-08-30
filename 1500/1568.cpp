#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> sum(1, 0);
	for(int i=1; ; i++){
		long long temp = 1LL*i*(i+1)/2;
		if(temp > N) break;
		sum.push_back(temp);
	}
	int result = 0;
	for(int i=sum.size()-1; N>0;){
		if(N >= sum[i]){
			N -= sum[i];
			result += i;
		}
		else i--;
	}
	printf("%d\n", result);
}