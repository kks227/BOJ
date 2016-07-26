#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

typedef tuple<int, int, string> member;
member m[100000];

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int age;
		string name;
		cin >> age >> name;
		m[i] = member(age, i, name);
	}
	sort(m, m+N);
	for(int i=0; i<N; i++)
		cout << get<0>(m[i]) << ' ' << get<2>(m[i]) << endl;
}