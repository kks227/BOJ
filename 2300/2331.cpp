#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int A, P, curr;
	map<int, int> R;
	scanf("%d %d", &A, &P);
	R[A] = 0;
	curr = A;
	for(int i=0; ; i++){
		int next = 0, temp = curr;
		while(temp){
			next += pow(temp%10, P);
			temp /= 10;
		}
		auto finder = R.find(next);
		if(finder == R.end()){
			R[next] = i+1;
			curr = next;
		}
		else{
			printf("%d\n", finder->second);
			break;
		}
	}
}