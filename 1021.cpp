#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class clistNode{
public:
    int n;
    clistNode *next, *prev;
 
    clistNode(int n1, clistNode* next1, clistNode* prev1):n(n1),next(next1),prev(prev1){}
};
 
class clist{
public:
    int size;
    clistNode* head;
 
    clist():size(0),head('\0'){}
 
    void insertFront(int n){
        clistNode *temp = new clistNode(n, '\0', '\0');
        if(size==0){
            temp->next = temp;
            temp->prev = temp;
            head = temp;
        }
        else{
            temp->next = head;
            temp->prev = head->prev;
            head = temp;
            head->next->prev = head;
            head->prev->next = head;
        }
        size++;
	}

	void erase(clistNode *target){
		if(size == 1){
			delete target;
			head = '\0';
			size = 0;
			return;
		}

		target->prev->next = target->next;
		target->next->prev = target->prev;
		delete target;
		size--;
	}
 
    void initialize(int n){
        for(int i=n; i>0; i--)
            insertFront(i);
    }

	int minOperation(int n, int m, int *target){
		initialize(n);

		int currentPos = 0;
		int nextPos;
		clistNode* currentNode = head;
		clistNode* tempNode;

		int result = 0;
		for(int i=0; i<m; i++){
			for(nextPos=currentPos; currentNode->n!=target[i]; nextPos++)
				currentNode = currentNode->next;
			result += min( abs(nextPos-currentPos), size - abs(nextPos-currentPos) );
			tempNode = currentNode;
			currentNode = currentNode->next;
			erase(tempNode);
		}

		return result;
	}
};

int main(){

	int N, M, target[50];
	scanf("%d %d", &N, &M);
	clist rq;
	for(int i=0; i<M; i++)
		scanf("%d", target+i);
	printf("%d\n", rq.minOperation(N, M, target));

	return 0;
}