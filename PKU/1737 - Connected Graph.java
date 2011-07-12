import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;

public class poj1737{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        
        BigInteger comb[][] = new BigInteger[50][51];
        
        for(int i = 0;i < 50;++i){
            comb[i][0] = BigInteger.ONE;
            comb[i][i+1] = BigInteger.ZERO;
            
            for(int j = 1;j <= i;++j)
                comb[i][j] = comb[i-1][j].add(comb[i-1][j-1]);
        }
        
        BigInteger two = new BigInteger("2");
        BigInteger g[] = new BigInteger[51];
        BigInteger f[] = new BigInteger[51];
        
        for(int i = 1;i <= 50;++i){
            g[i] = two.pow(i * (i-1) / 2);
            f[i] = g[i];
            
            for(int j = 1;j < i;++j)
                f[i] = f[i].subtract(f[j].multiply(g[i-j]).multiply(comb[i-1][j-1]));
        }
        
        while(true){
            int N = Integer.parseInt(in.readLine());
            if(N == 0) break;
            
            System.out.println(f[N]);
        }
    }
}
