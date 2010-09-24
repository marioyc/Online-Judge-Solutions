#include<iostream>
#include<vector>

using namespace std;

vector<int> a;
int N;
int n;
int cont;

void f(int x, int z)
{
    if(__builtin_popcount(x)==6)
    {
        cont=0;
        for(int i=0;i<N;i++)
        {
            if((x&(1<<i))!=0)
            {
                cont++;
                cout<<a[i];
                if(cont<6) cout<<" ";
            }
        }
        cout<<endl;
        return;
    }    
    for(int i=z+1;i<N;i++) f((x|(1<<i)),i);
    return;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    bool aux=false;
    
    while(true)
    {
        cin>>N;
        if(N==0) break;
        if(aux) cout<<endl;        
        a.clear();
        for(int i=0;i<N;i++)
        {
            cin>>n;
            a.push_back(n);
        }                
        f(0,-1);
        aux=true;
    }
    return 0;
}
