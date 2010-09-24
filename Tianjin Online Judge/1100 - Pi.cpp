#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int MCD(int a,int b)
{
    if(a%b==0) return b;
    return MCD(b,a%b);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int cont;
    int a;
    int N;
    vector<int> v;
    while(true)
    {
        cin>>N;
        if(N<=1 || N>=50) break;
        
        v.clear();
        for(int i=0;i<N;i++)
        {         
            cin>>a;
            v.push_back(a);            
        }
        
        cont=0;
        int t=N*(N-1)/2;
        
        for(int i=0;i<N-1;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(MCD(v[i],v[j])==1) cont++;
            }
        }
        if(cont==0) cout<<"No estimate for this data set."<<endl;
        else cout<<fixed<<setprecision (6) <<sqrt(6*t*1.0/cont)<<endl;
    }

    return 0;
}
