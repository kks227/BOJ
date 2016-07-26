#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	int N;
	cin >> N;
	string input;
	string book[1000];
	for(int i=0; i<N; i++)
		cin >> book[i];
	sort(book, book+N);
	int max = 1, cnt = 1;
	string max_sold = book[0];
	for(int i=1; i<N; i++){
		if(book[i] == book[i-1]) cnt++;
		else{
			if(cnt > max){
				max = cnt;
				max_sold = book[i-1];
			}
			else if(cnt == max){
				if(max_sold > book[i-1]) max_sold = book[i-1];
			}
			cnt = 1;
		}
	}
	if(cnt > max) max_sold = book[N-1];
	else if(cnt == max){
		if(max_sold > book[N-1]) max_sold = book[N-1];
	}
	cout << max_sold << endl;

    return 0;
}