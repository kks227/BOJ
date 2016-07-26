#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	string input;
	bool row[50]={0}, col[50]={0};
	int rowcnt=0, colcnt=0;
	int N, M;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> input;
		for(int j=0; j<M; j++){
			if(input[j] == 'X'){
				if(!col[j]){
					col[j] = true;
					colcnt++;
				}
				if(!row[i]){
					row[i] = true;
					rowcnt++;
				}
			}
		}
	}
	cout << max(N-rowcnt, M-colcnt) << endl;

	return 0;
}