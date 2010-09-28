#include <iostream>
#include <vector>
#include <string>

using namespace std;

short n;
string ax;
vector<string> v;
vector<string> aux;
vector<string> y;

vector<string> f()
{    
    if(n==1) return v;
    
    n--;
    aux=f();
    y=aux;
    ax.clear();    
    for(int i=0;i<aux.size();i++) ax+=" ";
    for(int i=0;i<y.size();i++)
    {
        aux[i]+=ax;
        aux[i]+=y[i];
    }
    for(int i=0;i<y.size();i++)
    {
        aux.push_back(ax);
        aux.back()+=y[i];
        aux.back()+=ax;
    }
    for(int i=0;i<y.size();i++)
    {
        aux.push_back(aux[i]);
    }
    return aux;    
}

int main(){

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s="X";
    v.push_back(s);
    
    vector<string> x;
    while(cin>>n)
    {
        if(n==-1) break;
        x=f();
        for(int i=0;i<x.size();i++)
        {
            while(x[i][x[i].size()-1]==' ') x[i].erase(x[i].size()-1,1);
        }
        for(int i=0;i<x.size();i++) cout<<x[i]<<endl;
        cout<<"-"<<endl;
    }

	return 0;
}
