#include<iostream>
#include<vector>

using namespace std;

struct punto{
    int x;
    int y;
    
    punto(int a, int b){
        x=a;
        y=b;
    }
};

int dist2(punto a, punto &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int area(punto &a, punto &b, punto &c){
    return a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int Ox,Oy,x,y,N,mx,cont1,cont2,S;
    double r;
    
    vector<punto> v;
    vector<double> m;
    
    while(1){
        cin>>Ox>>Oy>>r;
        if(r<0) break;
        
        cin>>N;
        punto O=punto(Ox,Oy);
        
        v.clear();
        for(int i=0;i<N;i++){
            cin>>x>>y;            
            if(dist2(punto(x,y),O)<=r*r) v.push_back(punto(x,y));
        }
        
        mx=0;
        
        for(int i=0;i<v.size();i++){
            cont1=cont2=0;
            
            for(int j=0;j<v.size();j++){
                S=area(O,v[j],v[i]);
                if(S==0){
                    cont1++;
                    cont2++;
                }else if(S>0) cont1++;
                else cont2++;                
            }            
            mx=max(mx,max(cont1,cont2));
        }
        
        cout<<mx<<endl;
    }

    return 0;
}
