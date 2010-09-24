#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

#define SZ 26

int n,pref_men[SZ][SZ],pref_women[SZ][SZ],inv[SZ][SZ],cont[SZ],wife[SZ],husband[SZ];

void Stable_Marriage(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            inv[i][pref_women[i][j]]=j;
    
    queue<int> Q;
    for(int i=0;i<n;i++) Q.push(i);
    fill(cont,cont+n,0);
    fill(wife,wife+n,-1);
    fill(husband,husband+n,-1);
    
    int m,w;
    
    while(!Q.empty()){
        m=Q.front();
        w=pref_men[m][cont[m]];
        
        if(husband[w]==-1){
            wife[m]=w;
            husband[w]=m;
            Q.pop();
        }else{
            if(inv[w][m]<inv[w][husband[w]]){
                wife[m]=w;
                wife[husband[w]]=-1;
                Q.pop();
                Q.push(husband[w]);
                husband[w]=m;
            }
        }
        
        cont[m]++;
    }
}

int main(){
    int T,M,W;
    int men_letter_index[26],women_letter_index[26];
    char men_index_letter[26],women_index_letter[26];
    string s; char c;
    int ind;
    bool start=true;
    
    cin>>T;
    
    for(int tc=1;tc<=T;tc++){
        cin>>n;
        
        M=W=0;
        
        memset(men_letter_index,-1,sizeof(men_letter_index));
        
        for(int i=2*n-1;i>=0;i--){
            cin>>c;
            if(islower(c)){
                men_letter_index[c-'a']=M;
                men_index_letter[M]=c;
                M++;
            }else{
                women_letter_index[c-'A']=W;
                women_index_letter[W]=c;
                W++;
            }
        }
        
        for(int i=0;i<n;i++){
            cin>>s;
            ind=men_letter_index[s[0]-'a'];
            for(int j=0;j<n;j++) pref_men[ind][j]=women_letter_index[s[j+2]-'A'];
        }
        
        for(int i=0;i<n;i++){
            cin>>s;
            ind=women_letter_index[s[0]-'A'];
            for(int j=0;j<n;j++) pref_women[ind][j]=men_letter_index[s[j+2]-'a'];
        }
        
        Stable_Marriage();
        
        if(!start) cout<<endl;
        start=false;
        
        for(int i=0;i<n;i++){
            if(men_letter_index[i]==-1) continue;
            cout<<(char)('a'+i)<<" "<<women_index_letter[wife[men_letter_index[i]]]<<endl;
        }
    }
    
    return 0;
}
