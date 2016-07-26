#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int value[26];

class node{
public:
	node():data('\0'),left('\0'),right('\0'){}
	node(char init):data(init),left('\0'),right('\0'){}
	node *left, *right;
	char data;
};

double calculate(node* current){
	if(current == '\0') return 0;
	switch(current->data){
	case '+':
		return calculate(current->left) + calculate(current->right);
	case '-':
		return calculate(current->left) - calculate(current->right);
	case '*':
		return calculate(current->left) * calculate(current->right);
	case '/':
		return calculate(current->left) / calculate(current->right);
	default:
		return value[current->data-'A'];
	}
}

int main(){

	int N;
	string postfix;
	cin >> N >> postfix;
	stack<node*> tree;
	for(int i=0; i<N; i++)
		cin >> value[i];

	int len = postfix.length();
	node *temp;
	for(int i=0; i<len; i++){
		if(isupper(postfix[i])) tree.push(new node(postfix[i]));
		else{
			temp = new node(postfix[i]);
			temp->right = tree.top();
			tree.pop();
			temp->left = tree.top();
			tree.pop();
			tree.push(temp);
		}
	}

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << calculate(tree.top()) << endl;

	return 0;
}