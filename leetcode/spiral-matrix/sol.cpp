#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    bool visit[110][110];
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        int dir[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
        memset(visit,false,sizeof visit);
        int n = matrix.size();
        if(n==0) return res;
        int m = matrix[0].size();
        int cnt = 0 , nx = 0 , ny = -1 , nd=0;
        int newx,newy;
        while( cnt < n * m ){
            newx = nx + dir[nd][0];
            newy = ny + dir[nd][1];
            if( newx >= 0 && newx < n && newy >= 0 && newy < m && !visit[newx][newy]){
                cnt++;
                nx = newx;
                ny = newy;
                visit[nx][ny]=true;
                res.push_back(matrix[nx][ny]);
            }
            else nd = (nd + 1 )%4;
        }
        return res;
    }
};
int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    vector< vector<int> > m;
    m.push_back(a);
    a.clear();
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);

    m.push_back(a);
    a.clear();
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    m.push_back(a);
    Solution x;
    a=x.spiralOrder(m);
    for(int i=0;i<a.size();i++)
        printf("%d ",a[i]);

    return 0;

}
