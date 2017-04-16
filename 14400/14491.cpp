#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	vector<int> N;
	while(T){
		N.push_back(T%9);
		T /= 9;
	}
	for(int i=N.size()-1; i>=0; i--)
		printf("%d", N[i]);
}