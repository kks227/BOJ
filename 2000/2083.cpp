#include <cstdio>
using namespace std;

int main(){
	while(1){
		char name[11];
		int age, weight;
		scanf("%s %d %d", name, &age, &weight);
		if(name[0] == '#') break;
		printf("%s %s\n", name, (age > 17 || weight >= 80 ? "Senior" : "Junior"));
	}
}