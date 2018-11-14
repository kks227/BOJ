#include <cstdio>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;
typedef unsigned long long unitType;
const int MAX_V = 12;
const int BITS = sizeof(unitType)*8;
const int MAX = (1<<MAX_V) / BITS;
const int MAX_L = 300000;



char E[MAX_L+1];
int bcnt, ppos, scnt;
unitType V[MAX][MAX_V], ival[MAX_L][MAX];
bool chosen[MAX_V];

enum NodeType{Expr, Imply, Disj, Conj, Term};

struct Node{
    NodeType type;
    vector<Node*> implyList;
    Node *lNode, *rNode;
    char c;
    bool notFlag;
    Node(): Node('\0'){};
    Node(char c1): type(Term), lNode(nullptr), rNode(nullptr), c(c1), notFlag(false){};
    ~Node(){
        if(lNode) delete lNode;
        if(rNode) delete rNode;
        for(int i = 0; i < implyList.size(); ++i)
            delete implyList[i];
    }
    void calc(){
        if(type == Expr){
            int k = implyList.size();
            for(int i = 0; i < k; ++i){
                implyList[i]->calc();
            }
            for(int i = 0; i < MAX; ++i){
                unitType temp[2] = {0, unitType(-1)};
                for(int j = 0; j < k; ++j){
                    temp[0] |= ival[scnt-k+j][i];
                    temp[1] &= ival[scnt-k+j][i];
                }
                ival[scnt-k][i] = ~temp[0] | temp[1];
            }
            scnt -= k-1;
        }
        else if(type == Imply){
            lNode->calc();
            rNode->calc();
            for(int i = 0; i < MAX; ++i)
                ival[scnt-2][i] = ~ival[scnt-2][i] | ival[scnt-1][i];
            --scnt;
        }
        else if(type == Disj){
            lNode->calc();
            rNode->calc();
            for(int i = 0; i < MAX; ++i)
                ival[scnt-2][i] |= ival[scnt-1][i];
            --scnt;
        }
        else if(type == Conj){
            lNode->calc();
            rNode->calc();
            for(int i = 0; i < MAX; ++i)
                ival[scnt-2][i] &= ival[scnt-1][i];
            --scnt;
        }
        else{
            if(notFlag){
                lNode->calc();
                for(int i = 0; i < MAX; ++i)
                    ival[scnt-1][i] = ~ival[scnt-1][i];
            }
            else{ // literal or variable
                for(int i = 0; i < MAX; ++i)
                    ival[scnt][i] = isdigit(c) ? unitType(c-'0' ? -1 : 0) : V[i][c-'A'];
                ++scnt;
            }
        }
    }
};

Node* parseExpr();
Node* parseImply();
Node* parseDisj();
Node* parseConj();
Node* parseTerm();

void dfs(int v){
    if(v == MAX_V){
        unitType k = bcnt / BITS, l = bcnt % BITS;
        for(int i = 0; i < MAX_V; ++i)
            V[k][i] |= unitType(chosen[i]) << l;
        ++bcnt;
        return;
    }

    dfs(v+1);
    chosen[v] = true;
    dfs(v+1);
    chosen[v] = false;
}



int main(){
    scanf("%s", E);
    Node *root = parseExpr();
    dfs(0);

    int F = 0;
    vector<unitType> f[2];
    root->calc();
    for(int i = 0; i < MAX; ++i){
        unitType temp = ival[0][i];
        for(unitType k = 0; k < BITS; ++k){
            bool flag = (temp & 1ULL << k);
            if(flag) ++F;
            f[flag].push_back(i*BITS + k);
        }
    }
        
    if(F == 0){
        printf("2\n1 0\n1 0\n");
    }
    else if(F == 1<<MAX_V){
        printf("2\n1 0\n1 ~0\n");
    }
    else if(F <= 1<<MAX_V-1){
        printf("%d\n", F+1);
        for(int i = 0; i < F; ++i){
            printf("%d ", MAX_V*2-1);
            for(int k = MAX_V-1; k >= 0; --k){
                if(f[1][i] / (1ULL<<k) % 2);
                else putchar('~');
                printf("%c ", 'A'+MAX_V-1-k);
            }
            for(int k = 0; k < MAX_V-1; ++k)
                printf("0 ");
            puts("");
        }
        if(F == 1) printf("2 1 ~0\n");
        else{
            printf("%d ", F*2-1);
            for(int i = 0; i < F; ++i)
                printf("%d ", i+1);
            for(int i = 0; i < F-1; ++i)
                printf("~0 ");
        }
    }
    else{
        F = (1<<MAX_V) - F;
        printf("%d\n", F+1);
        for(int i = 0; i < F; ++i){
            printf("%d ", MAX_V*2-1);
            for(int k = MAX_V-1; k >= 0; --k){
                if(f[0][i] / (1ULL<<k) % 2);
                else putchar('~');
                printf("%c ", 'A'+MAX_V-1-k);
            }
            for(int k = 0; k < MAX_V-1; ++k)
                printf("0 ");
            puts("");
        }
        printf("%d ", F*2-1);
        for(int i = 0; i < F; ++i)
            printf("~%d ", i+1);
        for(int i = 0; i < F-1; ++i)
            printf("0 ");
    }
        
    delete root;
}



Node* parseExpr(){
    Node *temp = parseImply();
    if(E[ppos] == '<'){
        Node *node = new Node();
        node->type = Expr;
        node->implyList.push_back(temp);
        while(E[ppos] == '<'){
            ppos += 3;
            node->implyList.push_back(parseImply());
        }
        return node;
    }
    return temp;
}

Node* parseImply(){
    Node *temp = parseDisj();
    if(E[ppos] == '-'){
        Node *node = new Node();
        node->type = Imply;
        node->lNode = temp;
        ppos += 2;
        node->rNode = parseImply();
        return node;
    }
    return temp;
}

Node* parseDisj(){
    Node *temp = parseConj();
    if(E[ppos] == '|'){
        Node *node = new Node();
        node->type = Disj;
        node->lNode = temp;
        ++ppos;
        node->rNode = parseDisj();
        if(temp->c == '1' || node->rNode->c == '1') return new Node('1');
        if(temp->c && temp->c == node->rNode->c) return temp;
        return node;
    }
    return temp;
}

Node* parseConj(){
    Node *temp = parseTerm();
    if(E[ppos] == '&'){
        Node *node = new Node();
        node->type = Conj;
        node->lNode = temp;
        ++ppos;
        node->rNode = parseConj();
        if(temp->c == '0' || node->rNode->c == '0') return new Node('0');
        if(temp->c && temp->c == node->rNode->c) return temp;
        return node;
    }
    return temp;
}

Node* parseTerm(){
    Node *temp;
    if(E[ppos] == '~'){
        ++ppos;
        temp = parseTerm();
        if(temp->notFlag) return temp->lNode;
        if(temp->c == '1') return new Node('0');
        if(temp->c == '0') return new Node('1');

        Node *node = new Node();
        node->type = Term;
        node->notFlag = true;
        node->lNode = temp;
        return node;
    }
    else if(E[ppos] == '('){
        ++ppos;
        temp = parseExpr();
        ++ppos;
    }
    else{
        Node *node = new Node();
        node->type = Term;
        node->c = E[ppos++];
        return node;
    }
    return temp;
}