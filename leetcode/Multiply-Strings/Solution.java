/*=============================================================================
#     FileName: sol.java
#         Desc: program solution for leetcode Multiply Strings
#       Author: WenShi(huicpc0215)
#        Email: huicpc0215@gmail.com
#     HomePage: https://github.com/huicpc0215
#      Version: 0.0.1
#   LastChange: 2014-12-05 23:13:49
#      History:
=============================================================================*/

import java.util.*;
import java.math.*;
public class Solution{
    public static String multiply(String num1,String num2){
        BigInteger a=new BigInteger(num1);
        BigInteger b=new BigInteger(num2);
        return (a.multiply(b).toString());
    }
    public static void main(String args[]){
        Scanner cin=new Scanner(System.in);
        String a=new String();
        String b=new String();
        while(cin.hasNext()){
            a=cin.next();
            b=cin.next();
            System.out.println("a="+a+" b="+b+" ans="+(multiply(a,b)));
        }
        return ;
    }
}
