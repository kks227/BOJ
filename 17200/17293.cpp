#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    for(int i = N; i > 1; --i){
        printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
        printf("Take one down and pass it around, %d bottle%s of beer on the wall.\n\n", i-1, i-1 == 1 ? "" : "s");
    }
    puts("1 bottle of beer on the wall, 1 bottle of beer.");
    puts("Take one down and pass it around, no more bottles of beer on the wall.\n");
    puts("No more bottles of beer on the wall, no more bottles of beer.");
    printf("Go to the store and buy some more, %d bottle%s of beer on the wall.\n", N, N == 1 ? "" : "s");
}