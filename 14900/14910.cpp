#include <cstdio>
using namespace std;

int main(){
	int prev = -1000000, curr;
	bool result = true;
	while(scanf("%d", &curr) > 0){
		if(prev > curr) result = false;
		prev = curr;
	}
	puts(result ? "Good" : "Bad");
}