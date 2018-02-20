#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, t[100], result[100];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", t+i);
	sort(t, t+N);
	for(int i=0, j=N/2-!(N%2); j>=0; i+=2, j--)
		result[i] = t[j];
	for(int i=1, j=N/2+(N%2); j<N; i+=2, j++)
		result[i] = t[j];
	for(int i=0; i<N; i++)
		printf("%d ", result[i]);
}