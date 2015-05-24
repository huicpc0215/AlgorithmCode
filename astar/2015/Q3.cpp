#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
int T,cnt=1,m,n;
unsigned int a,b,c,d,tmp;
set<unsigned int > st;
set<unsigned int >::iterator it;
int main(){
    scanf("%d",&T);
    while(T--){
        st.clear();
        printf("Case #%d:\n",cnt++);
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%u.%u.%u.%u",&a,&b,&c,&d);
            tmp=(a<<24)+(b<<16)+(c<<8)+(d);
            st.insert(tmp);
            getchar();
        }
        for(int i=0;i<m;i++){
            set<unsigned int> ans;
            scanf("%u.%u.%u.%u",&a,&b,&c,&d);
            tmp=(a<<24)+(b<<16)+(c<<8)+(d);
            for(it=st.begin();it!=st.end();it++){
                ans.insert( tmp&(*it) );
            }
            printf("%d\n",ans.size());
        }
    }



    return 0;
}
