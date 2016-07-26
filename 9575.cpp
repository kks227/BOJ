#include <iostream>
#include <set>
using namespace std;

int main(){

	int T, j, k, l;
	int a[50], b[50], c[50];
	set<int> lucky;
	bool flag;
	int n, temp;

	cin >> T;
	for(int i=0; i<T; i++){
		cin >> j;
		for(int p=0; p<j; p++) cin >> a[p];
		cin >> k;
		for(int q=0; q<k; q++) cin >> b[q];
		cin >> l;
		for(int r=0; r<l; r++) cin >> c[r];

		lucky.clear();
		for(int p=0; p<j; p++){
			for(int q=0; q<k; q++){
				for(int r=0; r<l; r++){
					flag = true;
					n = temp = a[p]+b[q]+c[r];
					while(n){
						if(n%10 != 5 && n%10 != 8){
							flag = false;
							break;
						}
						n /= 10;
					}
					if(flag) lucky.insert(temp);
				}
			}
		}
		cout << lucky.size() << endl;
	}

    return 0;
}