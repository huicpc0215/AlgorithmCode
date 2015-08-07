#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int dir[4][2];
    vector<vector<int> > res;
    bool dfs(int x,int y,int n,int d,int nowp){
        if( res[x][y] != 0 ) return false;
        res[x][y]=nowp;
        for(int i=0;i<4;i++){
            int newx = x + dir[(d+i)%4][0];
            int newy = y + dir[(d+i)%4][1];
            if( newx >=0 && newx < n && newy >=0 && newy < n ){
                if( dfs( newx , newy , n , d+i ,nowp+1) )  return true;
            }
        }
        return true;
    }
    vector<vector<int> > generateMatrix(int n) {
        res.clear();
        if( n == 0 ) return res;
        vector< int > tmp_vector;
        dir[0][0]=0;dir[0][1]=1;
        dir[1][0]=1;dir[1][1]=0;
        dir[2][0]=0;dir[2][1]=-1;
        dir[3][0]=-1;dir[3][1]=0;
        for(int i=0;i<n;i++)
            tmp_vector.push_back(0);
        for(int i=0;i<n;i++)
            res.push_back(tmp_vector);
        dfs(0,0,n,0,1);
        return res;
    }
};
int main(){
    Solution s;
    vector<vector<int> > res = s.generateMatrix(3);
    int n = res.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d%c",res[i][j],j==n-1?'\n':' ');
        }
    }


    return 0;
}
