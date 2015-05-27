#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

class Solution{
public:
    int pos[50000];
    int cnt[50000];
    int tmpcnt[50000];
    vector<int> findSubstring(string s,vector<string>& words){
        vector<int> ret;
        unsigned long long appear;
        int len=s.length();
        int wdsz=words.size();
        if( wdsz==0 ) {
            for(int i=0;i<len;i++){
                ret.push_back(i);
            }
            return ret;
        }
        int esz = words[0].length();
        for(int i=0;i<len;i++){
            pos[i]=-1;
            for(int j=0;j<wdsz;j++){
                if(0== strncmp( (s.c_str()+i),words[j].c_str(),esz) ){
                    pos[i]=j;
                    break;
                }
            }
        }
        for(int i=0;i<wdsz;i++){
            cnt[i]=1;
            for(int j=0;j<i;j++){
                if( strcmp( words[i].c_str(),words[j].c_str() )==0 ){
                    cnt[j]++;
                }
            }
        }
        for(int i=0;i<len;i++){
            int remain = wdsz;
            for(int j=0;j<wdsz;j++){
                tmpcnt[j]=cnt[j];
            }
            for(int j=0;j<wdsz;j++){
                if( i+j*esz>=len || pos[ i+j*esz ]==-1 || tmpcnt[ pos[i+j*esz] ]==0 )
                    break;
                else {
                    remain -- ;
                    tmpcnt[ pos[i+j*esz] ]--;
                }
            }
            if( remain == 0 ) ret.push_back(i);
        }
        return ret;
    }
};
int main(){
    Solution s;
    string STR("barfoothefoobarman");
    string s1("foo");
    string s2("bar");
    if( s1<s2 )printf("s1<s2");
    else if(s1>s2) printf("s1>s2");
    vector<string> wd;
    wd.push_back(s1);
    wd.push_back(s2);
    printf("ok\n");
    vector<int> ans=s.findSubstring(STR,wd);
    for(int i=0;i<ans.size();i++){
        printf("i=%d\n",ans[i]);
    }
    return 0;
}
