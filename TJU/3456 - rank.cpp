#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int sc[N];
    for(int i = 0;i<N;++i) scanf("%d",&sc[i]);
    
    int rank = 0;
    for(int i = 1;i<N;++i) if(sc[i]>sc[0]) ++rank;
    
    printf("%d\n",rank+1);
    
    return 0;
}
