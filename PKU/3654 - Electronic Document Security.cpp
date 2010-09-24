#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string s;
    int L[27];
    int current;
    int pos,caso=1;
    vector<int> E;
    char x;
    vector<int> R;
    int mask;
    vector<int> print;
    char c;
    
    while(1){
        cin>>s;
        if(s=="#") break;
        
        cout<<caso<<":";
        caso++;
        
        pos=0;        
        
        memset(L,0,sizeof(L));
        
        while(pos<s.size()){
            E.clear();
            R.clear();
            for(int i=pos;;i++){
                pos++;                
                if(s[i]=='+'||s[i]=='='||s[i]=='-'){
                    x=s[i];
                    break;
                }
                E.push_back(s[i]-'A');
            }
            for(int i=pos;;i++){
                pos++;
                if(s[i]==',' || i==s.size()) break;
                R.push_back(s[i]-'a');
            }
            
            mask=0;
            
            for(int i=0;i<R.size();i++) mask|=(1<<R[i]);
            
            if(x=='+'){
                for(int i=0;i<E.size();i++) L[E[i]]|=mask;
            }else if(x=='-'){
                for(int i=0;i<E.size();i++){
                    L[E[i]]=L[E[i]]&(~mask);
                }
            }else{
                for(int i=0;i<E.size();i++){
                    L[E[i]]=mask;
                }
            }
        }
        
        current=0;
        print.clear();
        
        for(int i=0;i<27;i++){
            if(L[i]==0 && i!=26) continue;
            if(L[i]==current) print.push_back(i);
            else if(current==0){
                current=L[i];
                print.push_back(i);
            }else if(L[i]!=current || (i==26 && current!=0)){
                for(int j=0;j<print.size();j++){
                    c=print[j]+'A';
                    cout<<c;
                }
                
                for(int j=0;j<26;j++){
                    if((current & (1<<j))!=0){
                        c=j+'a';
                        cout<<c;
                    }
                }
                
                print.clear();
                if(L[i]==0){
                    current=0;
                    continue;
                }
                print.push_back(i);
                current=L[i];
            }
        }
        
        cout<<endl;
    }
    
    return 0;
}
