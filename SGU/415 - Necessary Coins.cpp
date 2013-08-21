#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool check[2000001];

int main(){
    int n,x;
    
    scanf("%d %d",&n,&x);
    
    int a[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    vector<int> sol;
    int m = 0;
    
    for(int i = 0;i < n;++i){
        memset(check,false,sizeof check);
        check[0] = true;
        
        int sum = 0;
        
        for(int j = 0;j < n;++j)
            if(j != i) sum += a[j];
        
        sum = min(sum,x);
        
        for(int j = 0;j < n;++j)
            if(j != i)
                for(int k = sum;k >= a[j];--k)
                    if(check[k - a[j]])
                        check[k] = true;
        
        if(!check[x]){
            sol.push_back(a[i]);
            ++m;
        }
    }
    
    printf("%d\n",m);
    
    for(int i = 0;i < m;++i){
        printf("%d",sol[i]);
        if(i < m - 1) printf(" ");
        else printf("\n");
    }
    
    return 0;
}
