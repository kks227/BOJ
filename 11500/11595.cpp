#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<vector<int>, string> P;

int main(){
	int N;
	cin >> N;
	vector<P> arr;
	for(int i=0; i<N; i++){
		string name, rank;
		cin >> name;
		name.pop_back();
		vector<int> v;
		while(1){
			cin >> rank;
			if(rank == "class") break;
			else if(rank == "upper") v.push_back(-1);
			else if(rank == "middle") v.push_back(0);
			else v.push_back(1);
		}
		reverse(v.begin(), v.end());
		arr.push_back(P(v, name));
	}
	sort(arr.begin(), arr.end(), [](auto &p, auto &q){
		for(int i=0; i<p.first.size() || i<q.first.size(); i++){
			int a = (i < p.first.size() ? p.first[i] : 0);
			int b = (i < q.first.size() ? q.first[i] : 0);
			if(a != b) return a < b;
		}
		return p.second < q.second;
	});
	for(auto &p: arr)
		cout << p.second << endl;
}