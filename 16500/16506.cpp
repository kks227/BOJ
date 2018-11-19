#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	unordered_map<string, int> opcode;
	opcode["ADD"] = 0;
	opcode["SUB"] = 1;
	opcode["MOV"] = 2;
	opcode["AND"] = 3;
	opcode["OR"] = 4;
	opcode["NOT"] = 5;
	opcode["MULT"] = 6;
	opcode["LSFTL"] = 7;
	opcode["LSFTR"] = 8;
	opcode["ASFTR"] = 9;
	opcode["RL"] = 10;
	opcode["RR"] = 11;

	int N;
	cin >> N;
	for(int i = 0; i < N; ++i){
		string opc;
		int a, b, c, result;
		cin >> opc >> a >> b >> c;
		bool cFlag = false;
		if(opcode.find(opc) != opcode.end()) result = opcode[opc];
		else{
			cFlag = true;
			opc.pop_back();
			result = opcode[opc];
		}
		result <<= 12;
		if(cFlag){
			result += 1<<11;
			result += c;
		}
		else result += c<<1;
		result += a<<7;
		result += b<<4;
		for(int j = 0; j < 16; ++j)
			cout << (result & 1<<15-j ? '1' : '0');
		cout << '\n';
	}
}