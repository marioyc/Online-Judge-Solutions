#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

struct team{
    string name;
    vector<int> p;
    int geo;
    int cont;
    int sum;
    
    team(string a, vector<int> v, int x, int y){
        name=a;
        p=v;
        geo=x;
        cont=y;
        sum=0;
        for(int i=0;i<7;i++) sum+=v[i];
    }
    
    bool operator <(team X)const{
        int n1=0,n2=0,sum1=0,sum2=0;
        
        for(int i=0;i<7;i++){
            if(p[i]==0) n1++;
            if(X.p[i]==0) n2++;
            sum1+=p[i];
            sum2+=X.p[i];
        }
        
        if(n1!=n2) return n1<n2;
        if(sum1!=sum2) return sum1<sum2;
        if(geo!=X.geo) return geo<X.geo;
        return name<X.name;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int c,geo,n,cont,caso=1;
    string s;
    vector<int> v(7);
    double aux;
    vector<team> ranking;
    
    while(1){
        cin>>c;
        if(c==0) break;
        
        ranking.clear();
        
        for(int i=0;i<c;i++){
            cin>>s;
            aux=0;
            n=0;
            for(int j=0;j<7;j++){
                cin>>v[j];
                if(v[j]!=0){
                    aux+=log(v[j]);
                    n++;
                }
            }
            
            if(n!=0) aux=exp(aux/n);
            geo=aux+0.5;
            
            ranking.push_back(team(s,v,geo,n));
        }
        
        cont=1;
        
        sort(ranking.begin(),ranking.end());
        
        cout<<"CONTEST "<<caso<<endl;
        caso++;
        
        if(cont<10) cout<<0;
        cout<<cont<<" ";
        cout<<ranking[0].name;
        for(int i=ranking[0].name.size();i<10;i++) cout<<' ';        
        cout<<" "<<ranking[0].cont;
        cout<<" "<<setiosflags(ios::right)<<setw(4)<<ranking[0].sum;
        cout<<" "<<setiosflags(ios::right)<<setw(3)<<ranking[0].geo;
        for(int j=0;j<7;j++) cout<<" "<<setiosflags(ios::right)<<setw(3)<<ranking[0].p[j];
        cout<<endl;
        
        for(int i=1;i<ranking.size();i++){
            if(!(ranking[i].sum==ranking[i-1].sum && ranking[i].geo==ranking[i-1].geo)) cont=i+1;
            
            if(cont<10) cout<<0;
            cout<<cont<<" ";
            cout<<ranking[i].name;
            for(int j=ranking[i].name.size();j<10;j++) cout<<' ';
            cout<<" "<<ranking[i].cont;
            cout<<" "<<setiosflags(ios::right)<<setw(4)<<ranking[i].sum;
            cout<<" "<<setiosflags(ios::right)<<setw(3)<<ranking[i].geo;
            for(int j=0;j<7;j++) cout<<" "<<setiosflags(ios::right)<<setw(3)<<ranking[i].p[j];
            cout<<endl;
        }
    }


    return 0;
}
