#include <vector>
#include <algorithm>
#include <iostream>

#define all(v) (v).begin(), (v).end()

using namespace std;

int N;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    int sum=0;    
    vector<int> v;
    
    while(cin>>n)
    {            
        v.push_back(n);
        sort(all(v));
            
        if(v.size()%2==1) cout<<v[(v.size()+1)/2-1]<<endl;
        else cout<<(v[(v.size()+1)/2-1]+v[(v.size()+1)/2])/2<<endl;            
        
    }

    return 0;
}
