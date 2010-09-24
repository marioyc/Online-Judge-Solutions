#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int memo[52][52];
vector<int> v;

int f(int a, int b)
{
    if(b-a==1) return 0;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    int x=4000000;
    
    for(int i=a+1;i<b;i++)
        x=min(v[b]-v[a]+f(a,i)+f(i,b),x);
        
    memo[a][b]=x;
    return x;
    
}

int main()
{
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
        
    int L;
    int n;
    int aux;
    
    while(true)
    {
        scanf("%d", &L);
        if(L==0) break;
        
        cin>>n;
        
        v.clear();
        v.push_back(0);
        for(int i=0;i<n;i++)
        {
            cin>>aux;
            v.push_back(aux);
        }
        v.push_back(L);
        
        memset(memo,-1,sizeof(memo));
        
        printf("The minimum cutting is %d.\n",f(0,n+1));
        
    }


    return 0;
}
