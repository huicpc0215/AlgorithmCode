#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
class Solution {
    public:
        int lengthOfLastWord(string s) {
            int res=0;
            int length = s.length();
            for(int i=0;i<length;i++){
                if(s[i]!=' '){
		    res=0;
                    while(s[i]!='\0' && s[i]!=' '){
                        res++;
                        i++;
                    }
                }
            }
            return res;
        }
};

int main(){
    Solution s;
    string t;
    t="Hello world";
    cout<<s.lengthOfLastWord(t)<<endl;
    return 0;
}
