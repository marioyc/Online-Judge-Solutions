#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,k,ax;
    string s;
    
    int a[200];
    bool M[200];
    int ind[200][2];
    
    while(1){
        cin>>n;
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",a+i);
        for(int i=0;i<n;i++) a[i]--;
        
        getline(cin,s);
        
        memset(M,0,sizeof(M));
        
        vector< vector<int> > v;
        vector<int> u;
        
        for(int i=0;i<n;i++){
            if(M[i]) continue;
            
            u.clear();            
            M[i]=1;
            
            ind[i][0]=v.size(); ind[i][1]=0;
            u.push_back(i);
            
            ax=i;
            
            for(int j=0;;j++){
                ax=a[ax];
                
                if(ax==i) break;
                
                u.push_back(ax);
                
                M[ax]=1;
                ind[ax][0]=v.size(); ind[ax][1]=j+1;
            }
            
            v.push_back(u);
        }
        
        while(1){
        
            cin>>k;
        
            if(k==0) break;
        
            getline(cin,s);            
            s.erase(0,1);
            
            while(s.size()!=n) s+=" ";
            
            string ans(n,' ');
            
            for(int i=0;i<n;i++) ans[v[ind[i][0]][(ind[i][1]+k)%v[ind[i][0]].size()]]=s[i];
            
            cout<<ans<<endl;
        }
        cout<<endl;
    }
}
