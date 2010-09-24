#include<iostream>
#include<string>
#include<sstream>

using namespace std;

struct country{
    string name;
    int cont;
    
    country(){
    }
    
    country(string s){
        name=s;
        cont=1;
    }
    
    bool operator < (country X) const{
        return name<X.name;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,m=0;
    string line,name;
    bool found;
    
    country a[2000];
    
    cin>>n;
    getline(cin,line);
    for(int i=0;i<n;i++){
        getline(cin,line);
        istringstream is(line);
        is>>name;
        
        found=false;
        for(int j=0;j<m;j++)
            if(a[j].name==name){
                found=true;
                a[j].cont++;
                break;
            }
        
        if(!found) a[m++]=country(name);
    }
    
    sort(a,a+m);
    
    for(int i=0;i<m;i++) cout<<a[i].name<<" "<<a[i].cont<<endl;
    
    return 0;
}
