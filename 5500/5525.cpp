#include <cstdio>
#include <map>
using namespace std;
 
int main(){

	int N, M;
	char str[1000001];
	scanf("%d %d %s", &N, &M, str);

	int cnt = 0;
	map<int, int> subset;

	if(str[0] == 'I') cnt = 1;
	for(int i=1; i<M; i++){
		if(str[i] == 'I'){
			if(str[i-1] == 'I'){
				if(subset.count(cnt-1)) subset[cnt-1]++;
				else subset[cnt-1] = 1;
				cnt = 1;
			}
			else cnt++;
		}
		else{
			if(str[i-1] == 'O'){
				if(subset.count(cnt-1)) subset[cnt-1]++;
				else subset[cnt-1] = 1;
				cnt = 0;
			}
		}
	}
	if(subset.count(cnt-1)) subset[cnt-1]++;
	else subset[cnt-1] = 1;

	int result = 0;
	for(map<int, int>::iterator iter=subset.lower_bound(N); iter!=subset.end(); iter++)
		result += iter->second * (iter->first - N + 1);
	printf("%d\n", result);
 
    return 0;
}