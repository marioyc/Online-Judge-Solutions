#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;

int aux;
vector<int> v;

bool palin(int a, int b)
{
    v.clear();
    while(a!=0)
    {
        v.push_back(a%b);
        a/=b;
    }
    for(int i=0;i<=(v.size()-1)/2;i++)
        if(v[i]!=v[v.size()-1-i]) return false;
    return true;
}

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    bool ax;
        
    while(true)
    {
        scanf("%d",&n);
        if(n==0) break;
        
        ostringstream os;
        os<<"Number "<<n<<" is palindrom in basis";
        ax=false;
        
        for(int i=2;i<17;i++)
        {
            if(n%i==0) continue;
            if(n<i || palin(n,i))
            {
                ax=true;
                os<<" "<<i;
            }
        }
        if(ax) cout<<os.str()<<endl;
        else cout<<"Number "<<n<<" is not palindrom"<<endl;
    }

    return 0;
}
