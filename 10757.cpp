#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class bigInt{
public:
	bigInt():value(""){}
	friend istream& operator >>(istream& input, bigInt& bI);
	friend ostream& operator <<(ostream& output, const bigInt& bI);
	friend const bigInt operator +(const bigInt& A, const bigInt& B);
private:
	string value;
	friend const string absSum(const string& A, const string& B);
};

istream& operator >>(istream& input, bigInt& bI){
	input >> bI.value;
	reverse(bI.value.begin(), bI.value.end());
	return input;
}

ostream& operator <<(ostream& output, const bigInt& bI){
	for(int i=bI.value.length()-1; i>=0; i--)
		output.put(bI.value[i]);
	return output;
}

const string absSum(const string& A, const string& B){
	string result = "";
	int lenA = A.length(), lenB = B.length();
	bool carry;
	if(lenA >= lenB){
		result = A;
		carry = false;
		for(int i=0; i<lenB; i++){
			result[i] += (B[i]-'0');
			if(carry) result[i]++;
			carry = false;
			if(result[i] > '9'){
				result[i] -= 10;
				carry = true;
			}
		}
		if(carry){
			int pos = lenB;
			if(lenA == pos) result.push_back('1');
			else result[pos]++;
			while(result[pos] > '9'){
				result[pos++] -= 10;
				if(lenA == pos) result.push_back('1');
				else result[pos]++;
			}
		}
	}
	else{
		result = B;
		carry = false;
		for(int i=0; i<lenA; i++){
			result[i] += (A[i]-'0');
			if(carry) result[i]++;
			carry = false;
			if(result[i] > '9'){
				result[i] -= 10;
				carry = true;
			}
		}
		if(carry){
			int pos = lenA;
			if(lenB == pos) result.push_back('1');
			else result[pos]++;
			while(result[pos] > '9'){
				result[pos++] -= 10;
				if(lenB == pos) result.push_back('1');
				else result[pos]++;
			}
		}
	}
	return result;
}

const bigInt operator +(const bigInt& A, const bigInt& B){
	bigInt result;
	result.value = absSum(A.value, B.value);
	return result;
}

int main(){
	bigInt A, B;
	cin >> A >> B;
	cout << A+B << endl;
}