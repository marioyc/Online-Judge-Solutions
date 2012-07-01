#include <cstdio>
#include <cmath>

using namespace std;

double eps = 1e-7;

struct XYZ{
    double x,y,z;
    
    XYZ(){}
    XYZ(double _x, double _y, double _z) :
        x(_x), y(_y), z(_z){}
    
    XYZ operator -(XYZ p){
        return XYZ(x - p.x,y - p.y,z - p.z);
    }
    
    void normalize(){
        double r = sqrt(x * x + y * y + z * z);
        x /= r; y /= r; z /= r;
    }
    
    XYZ cross(XYZ p){
        return XYZ(y * p.z - z * p.y,z * p.x - x * p.z,x * p.y - y * p.x);
    }
    
    double dot(XYZ p){
        return x * p.x + y * p.y + z * p.z;
    }
};

struct Matrix{
    double M[4][4];
    
    void init(){
        for(int i = 0;i < 4;++i)
            for(int j = 0;j < 4;++j)
                M[i][j] = (i == j? 1 : 0);
    }
    
    Matrix operator * (Matrix X){
        Matrix ret;
        
        for(int i = 0;i < 4;++i){
            for(int j = 0;j < 4;++j){
                ret.M[i][j] = 0;
                
                for(int k = 0;k < 4;++k)
                    ret.M[i][j] += M[i][k] * X.M[k][j];
            }
        }
        
        return ret;
    }
}T,aux;

int main(){
    int N,M,Q;
    
    scanf("%d %d %d",&N,&M,&Q);
    
    XYZ P[N];
    double a[M],b[M],c[M],d[M];
    char op[10];
    double arg[3];
    int theta;
    double convf = M_PI / 180;
    
    for(int i = 0;i < N;++i)
        scanf("%lf %lf %lf",&P[i].x,&P[i].y,&P[i].z);
    
    for(int i = 0;i < M;++i)
        scanf("%lf %lf %lf %lf",&a[i],&b[i],&c[i],&d[i]);
    
    T.init();
    
    for(int i = 0;i < Q;++i){
        scanf("%s %lf %lf %lf",op,&arg[0],&arg[1],&arg[2]);
        
        aux.init();
        
        if(op[0] == 'T'){
            for(int j = 0;j < 3;++j)
                aux.M[j][3] = arg[j];
        }else if(op[0] == 'S'){
            for(int j = 0;j < 3;++j)
                aux.M[j][j] = arg[j];
        }else{
            scanf("%d",&theta);
            
            XYZ r(arg[0],arg[1],arg[2]);
            r.normalize();
            
            double costheta = cos(theta * convf),sintheta = sin(theta * convf);
            
            aux.M[0][0] = (costheta + (1 - costheta) * r.x * r.x);
            aux.M[0][1] = ((1 - costheta) * r.x * r.y - r.z * sintheta);
            aux.M[0][2] = ((1 - costheta) * r.x * r.z + r.y * sintheta);
            
            aux.M[1][0] = ((1 - costheta) * r.x * r.y + r.z * sintheta);
            aux.M[1][1] = (costheta + (1 - costheta) * r.y * r.y);
            aux.M[1][2] = ((1 - costheta) * r.y * r.z - r.x * sintheta);
            
            aux.M[2][0] = ((1 - costheta) * r.x * r.z - r.y * sintheta);
            aux.M[2][1] = ((1 - costheta) * r.y * r.z + r.x * sintheta);
            aux.M[2][2] = (costheta + (1 - costheta) * r.z * r.z);
        }
        
        T = aux * T;
    }
    
    for(int i = 0;i < N;++i){
        double x = T.M[0][0] * P[i].x + T.M[0][1] * P[i].y + T.M[0][2] * P[i].z + T.M[0][3];
        double y = T.M[1][0] * P[i].x + T.M[1][1] * P[i].y + T.M[1][2] * P[i].z + T.M[1][3];
        double z = T.M[2][0] * P[i].x + T.M[2][1] * P[i].y + T.M[2][2] * P[i].z + T.M[2][3];
        
        printf("%.2f %.2f %.2f\n",x,y,z);
    }
    
    XYZ P2[3];
    
    for(int i = 0;i < M;++i){
        d[i] = -d[i];
        
        if(fabs(a[i]) > eps){
            P2[0] = XYZ(d[i] / a[i],0,0);
            P2[1] = XYZ((d[i] - b[i]) / a[i],1,0);
            P2[2] = XYZ((d[i] - c[i]) / a[i],0,1);
        }else if(fabs(b[i]) > eps){
            P2[0] = XYZ(0,d[i] / b[i],0);
            P2[1] = XYZ(1,(d[i] - a[i]) / b[i],0);
            P2[2] = XYZ(0,(d[i] - c[i]) / b[i],1);
        }else{
            P2[0] = XYZ(0,0,d[i] / c[i]);
            P2[1] = XYZ(1,0,(d[i] - a[i]) / c[i]);
            P2[2] = XYZ(0,1,(d[i] - b[i]) / c[i]);
        }
        
        for(int k = 0;k < 3;++k){
            double x = T.M[0][0] * P2[k].x + T.M[0][1] * P2[k].y + T.M[0][2] * P2[k].z + T.M[0][3];
            double y = T.M[1][0] * P2[k].x + T.M[1][1] * P2[k].y + T.M[1][2] * P2[k].z + T.M[1][3];
            double z = T.M[2][0] * P2[k].x + T.M[2][1] * P2[k].y + T.M[2][2] * P2[k].z + T.M[2][3];
            P2[k] = XYZ(x,y,z);
        }
        
        XYZ dir = (P2[2] - P2[0]).cross(P2[1] - P2[0]);
        
        double A = dir.x,B = dir.y,C = dir.z,D = -dir.dot(P2[0]);
        double r = sqrt(A * A + B * B + C * C);
        
        A /= r; B /= r; C /= r; D /= r;
        
        printf("%.2f %.2f %.2f %.2f\n",A,B,C,D);
    }
    
    return 0;
}
