#include <cstdio>
#include <cmath>
using namespace std;
const double PI = acos(-1);

int main(){
	int a, p, r, q;
	scanf("%d %d %d %d", &a, &p, &r, &q);
	puts(a*q >= r*r*PI*p ? "Slice of pizza" : "Whole pizza");
}