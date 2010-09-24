#include <vector>
#include <string>
#include <iostream>

using namespace std;

int memo[26][5];
int r;

int f(int a, int b)
{
    if(b==0) return 1;
    if(a==25 && b>0) return 0;
    
    int x=0;
    for(int i=a+1;i<=25;i++)
        x+=f(i,b-1);
        
    return x;    
    
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector< vector<int> > v;
    vector<int> aux;
        
    aux.push_back(0);
    v.push_back(aux);
    int sum=27;
    int aux2;
        
    memset(memo,-1,sizeof(memo));
        
    for(int i=0;i<4;i++)
    {
        aux.clear();
        for(int j=0;j<25-i;j++)
        {
            aux2=sum;
            for(int k=0;k<i+2;k++)
            {
                aux2-=(j+k+1);
            }
            aux.push_back(aux2);
            sum+=f(j,i+1);
            //cout<<i<<" "<<j<<" "<<'a'+j<<" "<<i+1<<" "<<f(j,i+1)<<endl;
        }
        v.push_back(aux);
    }
    
    /*cout<<endl<<"valores"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<"i : "<<i<<endl;
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<endl;
        }
    }*/

    string s;
    bool ok;
    while(cin>>s)
    {
        cout<<s<<endl;
        
        /*sum=v[s.size()-1][s[0]-'a'];
        cout<<sum<<endl;*/
        if(s.size()==1)
        {
            cout<<s[0]-'a'+1<<endl;
        }
        else
        {
            ok=true;
            for(int i=0;i<s.size()-1;i++)
            {
                if(s[i]>=s[i+1])
                {
                    cout<<0<<endl;
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                sum=v[s.size()-1][s[0]-'a'];
                for(int i=0;i<s.size();i++)
                    sum+=s[i]-'a'+1;
            
                for(int i=1;k<s.size()-1;i++)
                    sum+=
            
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
