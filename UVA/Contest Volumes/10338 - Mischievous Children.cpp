#include<iostream>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int test_case,aux,cont[26];
    unsigned long long N;
    string s;
    
    scanf("%d",&test_case);
    
    for(int caso=1;caso<=test_case;caso++){
        cin>>s;
        
        memset(cont,0,sizeof(cont));
        
        for(int i=0;i<s.size();i++) cont[s[i]-'A']++;
        
        N=1;
        aux=0;
        
        for(int i=0;i<26;i++){
            for(int j=0;j<cont[i];j++){
                N=N*(aux+1)/(1+j);
                aux++;
            }
        }
        
        cout<<"Data set "<<caso<<": "<<N<<endl;
    }

    return 0;
}
