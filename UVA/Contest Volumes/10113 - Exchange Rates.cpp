#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

struct nodo{
    int m;
    int n;
    string s;
    
    nodo(int a, int b, string c){
        m=a;
        n=b;
        s=c;
    }
};

map<string, vector<nodo> > M;
vector<nodo> v,v1,v2,v3,v4;

int mcd(int a, int b){
    if(a%b==0) return b;
    return mcd(b,a%b);
}

int main(){
    int m,n,a,b,d;
    char signo;
    string s1,s2;
    bool enc;
    
    while(1){
        cin>>signo;
        if(signo=='.') break;
        else if(signo=='!'){
            cin>>m>>s1>>signo>>n>>s2;            
            
            d=mcd(m,n);
            m/=d;
            n/=d;
            
            v1=M[s1];
            v2=M[s2];
            M[s1].push_back(nodo(m,n,s2));
            
            for(int i=0;i<v1.size();i++){
                a=v1[i].n*m;
                b=n*v1[i].m;
                d=mcd(a,b);
                a/=d;
                b/=d;
                M[v1[i].s].push_back(nodo(a,b,s2));
                M[s2].push_back(nodo(b,a,v1[i].s));
            }
            
            M[s2].push_back(nodo(n,m,s1));
            
            for(int i=0;i<v2.size();i++){
                a=v2[i].n*n;
                b=m*v2[i].m;
                d=mcd(a,b);
                a/=d;
                b/=d;
                M[v2[i].s].push_back(nodo(a,b,s1));
                M[s1].push_back(nodo(b,a,v2[i].s));
            }
            
            v1=M[s1];
            
            for(int i=0;i<v1.size();i++){
                v3=M[v1[i].s];
                for(int j=i+1;j<v1.size();j++){
                    enc=false;
                    
                    for(int k=0;k<v3.size();k++){
                        if(v3[k].s==v1[j].s){
                            enc=true;
                            break;
                        }
                    }
                    
                    if(!enc){                        
                        a=v1[i].n*v1[j].m;
                        b=v1[j].n*v1[i].m;
                        d=mcd(a,b);
                        a/=d;
                        b/=d;
                        M[v1[i].s].push_back(nodo(a,b,v1[j].s));
                        M[v1[j].s].push_back(nodo(b,a,v1[i].s));
                    }
                }
            }
            
        }else{
            cin>>s1>>signo>>s2;
            v=M[s1];
            enc=false;
            
            for(int i=0;i<v.size();i++){
                if(v[i].s==s2){
                    enc=true;
                    cout<<v[i].m<<" "<<s1<<" = "<<v[i].n<<" "<<s2<<endl;
                }
            }
            
            if(!enc) cout<<"? "<<s1<<" = ? "<<s2<<endl;
        }
    }

    return 0;
}
