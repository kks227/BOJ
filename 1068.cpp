#include <iostream>
#include <set>
using namespace std;

typedef set<int> IntSet;
IntSet childNode[50];
int root;

int countLeafNode(int start){
	IntSet currentSet = childNode[start];
	if(currentSet.size() == 0) return 1;
	int result = 0;
	for(IntSet::iterator iter=currentSet.begin(); iter!=currentSet.end(); iter++){
		result += countLeafNode(*iter);
	}
	return result;
}

int main(){
	int N, input;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> input;
		if(input == -1) root = i;
		else childNode[input].insert(i);
	}
	cin >> input;
	if(input == root){
		cout << 0 << endl;
	}
	else{
		for(int i=0; i<N; i++){
			if(childNode[i].find(input) != childNode[i].end())
				childNode[i].erase(input);
		}
		cout << countLeafNode(root) << endl;
	}

	return 0;
}