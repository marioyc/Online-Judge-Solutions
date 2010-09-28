#include<iostream>
#include<vector>
#include<hash_set.h>

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int N,n;    
    int x;
    vector<int> v;
    hash_set<int> S;
    hash_set<int> :: iterator it;
    
    while(true)
    {
        scanf("%d",&N);
        if(N==0) break;        
        
        v.clear();
        S.clear();    
        for(int i=0;i<N;i++)
        {
            scanf("%d",&n);
            v.push_back(n);
            S.insert(n);
        }        
        sort(v.begin(),v.end());
        
        x=-1;
        
        for(int i=v.size()-2;i>=1;i--)
        {
            if((v[i]+v[i-1]<v[i+1])||(v[i]+v[0]>v[v.size()-1])) continue;
            for(int j=i-1;j>=0;j--)
            {
                if((it=S.find(v[i]+v[j]))!=S.end())
                {
                    x=max(x,v[i]+v[j]);
                    break;
                }
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
