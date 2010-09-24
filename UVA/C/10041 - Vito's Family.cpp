#include<iostream>
#include<vector>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,r,ax,mediana,a,b,dist;
    vector<int> s;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&r);
        
        s.clear();
        
        for(int i=0;i<r;i++){
            scanf("%d",&ax);
            s.push_back(ax);
        }
        
        sort(s.begin(),s.end());
        //hallamos la mediana
        if(r%2==0){
            a=s[(r-1)/2];
            ax=0;            
            for(int i=0;i<r;i++) ax+=abs(a-s[i]);
            
            a=s[(r-1)/2+1];
            dist=0;            
            for(int i=0;i<r;i++) dist+=abs(a-s[i]);
            
            dist=max(dist,ax);        
        }else{
            a=s[(r-1)/2];
            dist=0;        
            for(int i=0;i<r;i++) dist+=abs(a-s[i]);
        }
        printf("%d\n",dist);
    }

    return 0;
}
