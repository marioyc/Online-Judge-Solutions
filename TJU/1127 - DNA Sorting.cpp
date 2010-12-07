#include <cstdio>
#include <algorithm>

using namespace std;

struct DNA{
    char s[51];
    int inv;
    
    DNA(){}
}A[100];

bool comp(DNA a, DNA b){
    return a.inv<b.inv;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i<m;++i){
        scanf("%s",A[i].s);
        A[i].inv = 0;
        
        for(int j = 0;j<n;++j)
            for(int k = j+1;k<n;++k)
                if(A[i].s[j]>A[i].s[k])
                    ++A[i].inv;
    }
    
    stable_sort(A,A+m,comp);
    
    for(int i = 0;i<m;++i)
        printf("%s\n",A[i].s);
    
    return 0;
}
