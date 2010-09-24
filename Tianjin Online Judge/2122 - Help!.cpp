#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,time,cont,total;
    char c;
    string s;
    
    int score[26];
    int incorrect[26];
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        memset(score,-1,sizeof(score));
        memset(incorrect,0,sizeof(incorrect));
        
        for(int i=0;i<N;i++){
            cin>>c>>time>>s;
            
            if(s[0]=='c'){
                score[c-'A']=time;
            }else incorrect[c-'A']++;
        }
        
        cont=total=0;
        
        for(int i=0;i<26;i++){
            if(score[i]!=-1){
                total+=score[i]+20*incorrect[i];
                cont++;
            }
        }
        
        cout<<cont<<" "<<total<<endl;
    }
    
    return 0;
}
