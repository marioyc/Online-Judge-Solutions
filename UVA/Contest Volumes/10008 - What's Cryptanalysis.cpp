#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct nodo{
    char letra;
    int frecuencia;
    
    nodo(char a, int b){
        letra=a;
        frecuencia=b;
    }
    
    bool operator <(nodo P)const{
        if(frecuencia!=P.frecuencia) return frecuencia>P.frecuencia;
        return letra<P.letra;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    vector<nodo> M;
    
    for(int i=0;i<26;i++) M.push_back(nodo('A'+i,0));

    string s;
    int n;
    cin>>n;
    getline(cin,s);    

    for(int i=0;i<n;i++){
        getline(cin,s);
        
        for(int j=0;j<s.size();j++){
            if(s[j]>='a' && s[j]<='z') M[s[j]-'a'].frecuencia++;
            else if(s[j]>='A' && s[j]<='Z') M[s[j]-'A'].frecuencia++;
        }
    }

    sort(M.begin(),M.end());
    
    for(int i=0;i<26 && M[i].frecuencia!=0;i++) cout<<M[i].letra<<" "<<M[i].frecuencia<<endl;

    return 0;
}
