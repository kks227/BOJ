#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int, int, string> student;
student s[100000];

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int kor, eng, mat;
		string name;
		cin >> name >> kor >> eng >> mat;
		s[i] = student(-kor, eng, -mat, name);
	}
	sort(s, s+N);
	for(int i=0; i<N; i++)
		cout << get<3>(s[i]) << endl;
}