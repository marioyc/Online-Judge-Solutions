package aprendiendojava;

import java.util.Scanner;
import java.math.BigInteger;

public class tju1179 {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);

        BigInteger dp[] = new BigInteger[101];
        dp[0] = BigInteger.ONE;

        for(int i=1;i<=100;++i){
            dp[i] = BigInteger.ZERO;
            for(int j=0;j<i;++j) dp[i] = dp[i].add(dp[j].multiply(dp[i-1-j]));
        }

        while(true){
            int n = in.nextInt();
            if(n==-1) break;
            System.out.println(dp[n]);
        }
    }
}
