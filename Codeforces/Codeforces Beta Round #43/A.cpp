#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 0,pos = 0;i<N-1;++i){
        pos = (pos+i+1)%N;
        if(i>0) putchar(' ');
        printf("%d",1+pos);
    }
    
    putchar('\n');
    
    return 0;
}
