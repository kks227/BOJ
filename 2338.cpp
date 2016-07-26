#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class bigInt{
public:
	bigInt():value(""),sign(true){}
	friend istream& operator >>(istream& input, bigInt& bI);
	friend ostream& operator <<(ostream& output, const bigInt& bI);
	friend const bigInt operator +(const bigInt& A, const bigInt& B);
	friend const bigInt operator -(const bigInt& A, const bigInt& B);
	friend const bigInt operator *(const bigInt& A, const bigInt& B);
private:
	string value;
	bool sign; //true: +, false: -
	friend bool geValue(const string& A, const string& B);
	friend void trim(string &A);
	friend const string absSum(const string& A, const string& B);
	friend const string absSub(const string& A, const string& B);
	friend const string absMtp(const string& A, const char B);
	friend const string absMtp(const string& A, const string& B);
};

istream& operator >>(istream& input, bigInt& bI){
	input >> bI.value;
	if(bI.value[0] == '-'){
		bI.sign = false;
		bI.value.erase(bI.value.begin());
	}
	else bI.sign = true;
	reverse(bI.value.begin(), bI.value.end());
	return input;
}

ostream& operator <<(ostream& output, const bigInt& bI){
	if(!bI.sign && bI.value != "0") output.put('-');
	for(int i=bI.value.length()-1; i>=0; i--)
		output.put(bI.value[i]);
	return output;
}

bool geValue(const string& A, const string& B){
	int lenA = A.length(), lenB = B.length();
	if(lenA != lenB) return lenA > lenB;
	for(int i=lenA-1; i>=0; i--)
		if(A[i] != B[i]) return A[i] > B[i];
	return true;
}

void trim(string &A){
	int i;
	for(i=A.length()-1; i>0; i--)
		if(A[i] != '0') break;
	A = A.substr(0, i+1);
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

const string absSub(const string& A, const string& B){ // |A|>=|B|
	string result = A;
	int lenA = A.length(), lenB = B.length();
	//if(!geValue(A, B)) return "0";
	bool carry = false;
	for(int i=0; i<lenB; i++){
		result[i] -= (B[i]-'0');
		if(carry) result[i]--;
		carry = false;
		if(result[i] < '0'){
			result[i] += 10;
			carry = true;
		}
	}
	if(carry){
		int pos = lenB;
		result[pos]--;
		while(result[pos] < '0'){
			result[pos++] += 10;
			result[pos]--;
		}
	}
	trim(result);
	return result;
}

const string absMtp(const string& A, const char B){
	if(A == "0" || B == '0') return "0";
	string result = "";
	int lenA = A.length();
	int carry = 0;
	for(int i=0; i<lenA; i++){
		result.push_back( (A[i]-'0')*(B-'0')%10+'0' + carry );
		carry = (A[i]-'0')*(B-'0')/10;
		if(result[i] > '9'){
			result[i] -= 10;
			carry++;
		}
	}
	if(carry > 0) result.push_back(carry+'0');
	return result;
}

const string absMtp(const string& A, const string& B){
	if(A == "0" || B == "0") return "0";
	string result = "0", temp;
	int lenB = B.length();
	for(int i=0; i<lenB; i++){
		if(B[i] == '0') continue;
		temp = string(i, '0') + absMtp(A, B[i]);
		result = absSum(result, temp);
	}
	return result;
}

const bigInt operator +(const bigInt& A, const bigInt& B){
	bigInt result;
	if(A.sign == B.sign){
		result.sign = A.sign;
		result.value = absSum(A.value, B.value);
	}
	else{
		if(geValue(A.value, B.value)){
			result.sign = A.sign;
			result.value = absSub(A.value, B.value);
		}
		else{
			result.sign = B.sign;
			result.value = absSub(B.value, A.value);
		}
	}
	return result;
}

const bigInt operator -(const bigInt& A, const bigInt& B){
	bigInt result;
	if(A.sign != B.sign){
		result.sign = A.sign;
		result.value = absSum(A.value, B.value);
	}
	else{
		if(geValue(A.value, B.value)){
			result.sign = A.sign;
			result.value = absSub(A.value, B.value);
		}
		else{
			result.sign = !A.sign;
			result.value = absSub(B.value, A.value);
		}
	}
	return result;
}

const bigInt operator *(const bigInt& A, const bigInt& B){
	bigInt result;
	result.sign = (A.sign == B.sign);
	result.value = absMtp(A.value, B.value);
	return result;
}

int main(){

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	bigInt A, B;
	cin >> A >> B;
	cout << A+B << endl;
	cout << A-B << endl;
	cout << A*B << endl;

	return 0;
}