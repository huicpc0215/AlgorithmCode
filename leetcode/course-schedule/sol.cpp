#include<vector>
#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;

class Solution {
public:
    int cnt[2010];
    vector<int> e[2010];
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int n = numCourses;
        for(int i=0;i<n;i++){
            e[i].clear();
            cnt[i]=0;
        }
        queue<int> q;
        int m = prerequisites.size();
        for(int i=0;i<m;i++){
            e[ prerequisites[i].second ].push_back( prerequisites[i].first );
            cnt[ prerequisites[i].first ]++;
        }

        for(int i=0;i<n;i++)
            if( cnt[i]==0 )q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            int sz = e[u].size();
            for(int i=0;i<sz;i++){
                cnt[ e[u][i] ]--;
                if( cnt[e[u][i]] ==0 )q.push( e[u][i] );
            }
        }
        for(int i=0;i<n;i++)if( cnt[i] ) return false;
        return true;
    }
};
int main(){
    vector< pair<int,int> > pr;
    pr.push_back( make_pair(0,1) );
    pr.push_back( make_pair(0,2) );
    pr.push_back( make_pair(1,2) );
    Solution s;
    printf("%s\n",s.canFinish(3,pr)?"True":"False");
}
