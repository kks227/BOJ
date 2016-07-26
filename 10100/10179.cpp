#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		double price;
		scanf("%lf", &price);
		printf("$%.2lf\n", price * 0.8);
	}
}