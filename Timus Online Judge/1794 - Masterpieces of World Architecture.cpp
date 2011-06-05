#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int a[100000],cont[100000];
    
    for(int i = 0;i < N;++i) scanf("%d",&a[i]);
    
    memset(cont,0,sizeof(cont));
    
    for(int i = 0;i < N;++i)
        ++cont[((i - a[i] + 1) % N + N) % N];
    
    int best = 0,pos = 0;
    
    for(int i = 0;i < N;++i){
        if(cont[i] > best){
            best = cont[i];
            pos = i;
        }
    }
    
    printf("%d\n",pos + 1);
    
    return 0;
}
