#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
class Solution{
public:
    map<string,int> mp;
    map<string,int>::iterator it;
    char tmpstr[1024];
    vector<string> anagrams(vector<string>& strs){
        vector<string> ans;
        int sz = strs.size(),len;
        for(int i=0;i<sz;i++){
            len = strs[i].length();
            strcpy( tmpstr,strs[i].c_str() );
            sort(tmpstr,tmpstr+len);
            string t(tmpstr);
            if(mp[t]==0) mp[t]=i+1;
            else if( mp[t] > 0 ){
                mp[t] = -mp[t];
                ans.push_back(strs[i]);
            }
            else ans.push_back( strs[i] );
        }
        for(it = mp.begin(); it != mp.end(); it++ ){
            if( (it->second) < 0 )
                ans.push_back( strs[ -(it->second) -1 ] );
        }
        return ans;
    }
};

int main(){
    vector<string> ip;
    string s("tea");
    ip.push_back(s);
    s=string("and");
    ip.push_back(s);
    s=string("ate");
    ip.push_back(s);
    s=string("eat");
    ip.push_back(s);
    s=string("den");
    ip.push_back(s);
    Solution x;
    vector<string> ans = x.anagrams(ip);
    int len = ans.size();
    for(int i=0;i<len;i++){
        printf("%s\n",ans[i].c_str());
    }
    return 0;
}
