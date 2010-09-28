#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

struct punto{
    int x,y,z;
    
    punto(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }
};

double dist(punto &A, punto &B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z));
}

int main(){
    vector<punto> v;
    vector<punto> u;
    
    int x,y,z;
    
    for(int i=0;i<16;i++){
        scanf("%d %d %d",&x,&y,&z);
        v.push_back(punto(x,y,z));
    }
    
    while(1){
        scanf("%d %d %d",&x,&y,&z);        
        if(x==-1 && y==-1 && z==-1) break;
        
        u.push_back(punto(x,y,z));
    }
    
    double min,aux;
    int ind;
    
    for(int i=0;i<u.size();i++){
        min=1e10;
        
        for(int j=0;j<v.size();j++){
            aux=dist(u[i],v[j]);
            if(aux<min){
                min=aux;
                ind=j;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",u[i].x,u[i].y,u[i].z,v[ind].x,v[ind].y,v[ind].z);
    }
    
    return 0;
}
