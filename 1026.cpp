#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int N;
	int a[50];
	int b[50];
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> a[i];
	for(int i=0; i<N; i++)
		cin >> b[i];

	sort(a, a+N);
	sort(b, b+N);
	int sum=0;
	for(int i=0; i<N; i++)
		sum += a[i]*b[N-i-1];
	cout << sum << endl;
 
    return 0;
}