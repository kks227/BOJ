#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	string channel[100];
	for(int i=0; i<N; i++)
		cin >> channel[i];
	int p = 0;
	for(; channel[p]!="KBS1"; p++)
		cout << 1;
	for(; p>0; p--){
		cout << 4;
		swap(channel[p], channel[p-1]);
	}
	for(; channel[p]!="KBS2"; p++)
		cout << 1;
	for(; p>1; p--){
		cout << 4;
		swap(channel[p], channel[p-1]);
	}
}