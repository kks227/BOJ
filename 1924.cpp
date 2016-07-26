#include <cstdio>
using namespace std;

int main(){
	int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int x, y;
	char str[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	scanf("%d %d", &x, &y);
	int n = 0;
	for(int i=0; i<x-1; i++)
		n += day[i];
	n += y;
	puts(str[n%7]);
}