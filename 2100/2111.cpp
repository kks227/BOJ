#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX = 20000;
typedef pair<int, int> P;

class BigInt{
public:
    BigInt(): BigInt(""){}
    BigInt(int n){
        value = "";
        do{
            value.push_back(n%10 + '0');
            n /= 10;
        }while(n);
    }
    BigInt(string value1): value(value1){}
    friend ostream& operator <<(ostream& output, const BigInt& bI);
    friend const BigInt operator +(const BigInt& A, const BigInt& B);
    friend const BigInt operator *(const BigInt& A, const BigInt& B);

private:
    string value;
    friend const string absSum(const string& A, const string& B);
    friend const string absMtp(const string& A, const char B);
    friend const string absMtp(const string& A, const string& B);
};

ostream& operator <<(ostream& output, const BigInt& bI){
    for(int i = bI.value.length()-1; i >= 0; --i)
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
        for(int i = 0; i < lenB; ++i){
            result[i] += (B[i]-'0');
            if(carry) ++result[i];
            carry = false;
            if(result[i] > '9'){
                result[i] -= 10;
                carry = true;
            }
        }
        if(carry){
            int pos = lenB;
            if(lenA == pos) result.push_back('1');
            else ++result[pos];
            while(result[pos] > '9'){
                result[pos++] -= 10;
                if(lenA == pos) result.push_back('1');
                else ++result[pos];
            }
        }
    }
    else{
        result = B;
        carry = false;
        for(int i = 0; i < lenA; ++i){
            result[i] += (A[i]-'0');
            if(carry) ++result[i];
            carry = false;
            if(result[i] > '9'){
                result[i] -= 10;
                carry = true;
            }
        }
        if(carry){
            int pos = lenA;
            if(lenB == pos) result.push_back('1');
            else ++result[pos];
            while(result[pos] > '9'){
                result[pos++] -= 10;
                if(lenB == pos) result.push_back('1');
                else ++result[pos];
            }
        }
    }
    return result;
}

const string absMtp(const string& A, const char B){
    if(A == "0" || B == '0') return "0";
    string result = "";
    int lenA = A.length();
    int carry = 0;
    for(int i = 0; i < lenA; ++i){
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
    for(int i = 0; i < lenB; ++i){
        if(B[i] == '0') continue;
        temp = string(i, '0') + absMtp(A, B[i]);
        result = absSum(result, temp);
    }
    return result;
}

const BigInt operator +(const BigInt& A, const BigInt& B){
    return BigInt(absSum(A.value, B.value));
}

const BigInt operator *(const BigInt& A, const BigInt& B){
    return BigInt(absMtp(A.value, B.value));
}

int V, dcnt, dfsn[MAX];
BigInt ans;
vector<int> adj[MAX];
stack<P> S;

int getBCC(int curr, int prev = -1){
    int result = dfsn[curr] = dcnt++;
    for(int next: adj[curr]){
        if(next == prev) continue;

        if(dfsn[curr] > dfsn[next]) S.push(P(curr, next));
        if(dfsn[next] >= 0) result = min(result, dfsn[next]);
        else{
            int temp = getBCC(next, curr);
            result = min(result, temp);
            if(temp >= dfsn[curr]){
                unordered_set<int> vset;
                int ecnt = 0;
                while(!S.empty()){
                    int u = S.top().first, v = S.top().second;
                    S.pop();
                    vset.insert(u);
                    vset.insert(v);
                    ++ecnt;
                    if(curr == u && next == v) break;
                }
                if(ecnt > 1){
                    if(vset.size() != ecnt) ans = BigInt(0);
                    else if(ecnt > 1) ans = ans * BigInt(ecnt + 1);
                }
            }
        }
    }
    return result;
}



int main(){
    int M;
    cin >> V >> M;
    for(int i = 0; i < M; ++i){
        int K, u, v;
        cin >> K >> u;
        for(int j = 1; j < K; ++j){
            cin >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
            u = v;
        }
    }

    ans = BigInt(1);
    dcnt = 0;
    fill(dfsn, dfsn + V, -1);
    getBCC(0);
    for(int i = 1; i < V; ++i)
        if(dfsn[i] < 0) ans = BigInt(0);
    cout << ans << '\n';
}