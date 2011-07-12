#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a[100];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    sort(a,a+N);
    
    int last = 0;
    
    for(int i = 0;i < N;++i){
        if(a[i] - last > 1) break;
        else last += a[i];
    }
    
    printf("%d\n",last + 1);
    
    return 0;
}
