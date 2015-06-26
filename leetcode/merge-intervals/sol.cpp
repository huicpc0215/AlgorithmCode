#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    int cmp(const void *a,const void *b){
        return ( (*(Interval*)a).start - (*(Interval*)b).start );
    }
    struct my_inter{
        int start;
        int end;
        my_inter(int s,int e):start(s),end(e){}
        bool operator<(const my_inter &a)const { return start < a.start; }
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res ;
        int sz = intervals.size();
        if( sz == 0 ) return res;
        vector<my_inter> tmp;
        for(int i=0;i<sz;i++)
            tmp.push_back( my_inter(intervals[i].start,intervals[i].end) );
        sort(tmp.begin(),tmp.end());
        int last = tmp[0].end , begin = tmp[0].start;
        for(int i=0;i<sz;i++){
            if( tmp[i].start <= last ){
                last = max( last , tmp[i].end );
            }
            else {
                 res.push_back( Interval(begin , last) );
                 begin = tmp[i].start;
                 last = tmp[i].end;
            }
        }
        res.push_back(Interval(begin,last));
        return res;
    }
};


