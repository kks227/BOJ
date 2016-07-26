#include <iostream>
using namespace std;

int main(){

	int a[10], b[10];
	int recent_won_A=0, recent_won_B=0;
	int score_A=0, score_B=0;
	for(int i=0; i<10; i++)
		cin >> a[i];
	for(int i=0; i<10; i++)
		cin >> b[i];

	for(int i=0; i<10; i++){
		if(a[i] == b[i]){
			score_A++; score_B++;
		}
		else if(a[i] > b[i]){
			score_A += 3;
			recent_won_A = i;
		}
		else{
			score_B += 3;
			recent_won_B = i;
		}
	}

	cout << score_A << ' ' << score_B << endl;
	if(score_A == score_B){
		if(recent_won_A == recent_won_B) cout << 'D' << endl;
		else if(recent_won_A > recent_won_B) cout << 'A' << endl;
		else cout << 'B' << endl;
	}
	else if(score_A > score_B) cout << 'A' << endl;
	else cout << 'B' << endl;

	return 0;
}