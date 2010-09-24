#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int i;
char x,y;
vector<char> v;
string s;
int M[26];
vector< vector<char> > u;
bool ya[20];
vector<int> X;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    
    while(getline(cin,s)){
        istringstream is1(s);
        
        i=0;
        
        while(is1>>x){
            v.push_back(x);
            M[x-'a']=i;
            i++;
        }
        
        getline(cin,s);
        istringstream is2(s);
        
        u.clear();
        u.resize(26);
        
        while(is2>>x>>y){
            u[x-'a'].push_back(y);
            u[y-'a'].push_back(x);        
        }
        
        cout<<i<<endl;
    }
    
    return 0;
}
