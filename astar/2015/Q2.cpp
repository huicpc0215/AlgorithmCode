#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 100010
int T,pwd,len,cnt=1,inc;
char str[MAXN];
int main(){
    cin>>T;
    while(T--){
        printf("Case #%d:\n",cnt++);
        //gets(str);
        getchar();
        cin.getline(str,sizeof(str));
        cin>>pwd;
        len = strlen(str);
        if( pwd >= len || pwd == 1){
            printf("%s\n",str);
            continue;
        }
        inc=len/pwd;
        if(len%pwd!=0)inc++;
        int outlen=0;
        for(int i=0;i<inc;i++){
            int j=i;
            bool NoBlock=false;
            while(j<len&&outlen<len){
                printf("%c",str[j]);
                if(j/inc==len%pwd)NoBlock=true;
                j+=inc-NoBlock;
                outlen++;
            }
        }
        printf("\n");
    }

    return 0;
}
