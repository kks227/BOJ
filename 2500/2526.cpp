#include <iostream>
#include <map>
using namespace std;

int main(){

	map<int, int> path;
	int N, P, current, cnt;
	cin >> N >> P;
	current = N;
	cnt = 0;
	map<int, int>::iterator iter;
	while( (iter = path.find(current)) == path.end() ){
		path[current] = cnt++;
		current = current * N % P;
	}
	cout << cnt - iter->second << endl;

	return 0;
}