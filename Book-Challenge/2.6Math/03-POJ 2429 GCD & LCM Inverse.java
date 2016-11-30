//created by sfailsthy 2016/11/26 19:09
/*
设最大公约数、最小公倍数分别是a，b，c=b/a。设所求的两个数分别是m、n(m<=n)。m=a*i,n=b/i;
则m/n=a*i^2/b<=1，所以i<=sqrt(b/a)
另外m+n=a*i+b/i在[1,sqrt(b/a)]内是单调递减的，因此从大开始枚举，找到满足条件的就输出。
(m,n)=(a*i,b/i)=(a*i,a*c/i)=a*(i,c/i)=a。所以条件是c%i==0&&gcd(i,c/i)==1
纯暴力法，java多么和谐23333
*/
import java.util.Scanner;

public class Main{
    static long gcd(long a,long b){
        long temp;
        while(b!=0){
            a=a%b;
            temp=a;
            a=b;
            b=temp;
        }
        return a;
    }
    public static void main(String args[]) {
        // TODO Auto-generated method stub
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
            long a=cin.nextLong();
            long b=cin.nextLong();
            long c=b/a;
            for(long i=(long)Math.sqrt(c);i>=1;i--){
                if(c%i==0&&gcd(i,c/i)==1){
                    System.out.println((a*i)+" "+(b/i));
                    break;
                }
            }
        }
        cin.close();
    }

}
