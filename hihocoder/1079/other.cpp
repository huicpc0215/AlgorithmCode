#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAX_N=1e5+10;
vector<int> num;
map<int,int> num_index;
int n,l,m;//m相当于新的'n'，表示新区间长度
int left1[MAX_N];
int right1[MAX_N];
set<int> ans;//能看见的海报编号，防止编号重复，所以用set
typedef struct node
{
    int l;
    int r;
    int lazytag;//懒惰标记，表示第i张海报贴在了[l,r]区间，初始值为-1
};
node tree[8*MAX_N];//节点最多2N，所以线段树节点最多2N*4
//数据输入及预处理
void pre_init()
{
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&left1[i],&right1[i]);
        num.push_back(left1[i]);
        num.push_back(right1[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());//排序并去除重复元素
    m=num.size();
    for(int i=0;i<m;i++)
        num_index.insert(make_pair(num[i],i+1));//构造map
    for(int i=0;i<n;i++)
    {
        left1[i]=num_index[left1[i]];//转换为新的等价区间
        right1[i]=num_index[right1[i]];
    }
}
//构造线段树
void build(int l, int r, int pos)
{
    if(tree[pos/2].r-tree[pos/2].l==1)//父亲已经是叶子节点了，不要继续构造
        return;
    tree[pos].l=l;
    tree[pos].r=r;
    tree[pos].lazytag=-1;//初始值为-1
    int mid=(l+r)/2;
    build(l,mid,pos*2);
    build(mid,r,pos*2+1);
}
//懒惰标签下移
void release(int pos)
{
    if(tree[pos].r-tree[pos].l>1)//非叶子节点
    {
        if(tree[pos].lazytag!=-1)
        {
            tree[pos*2].lazytag=tree[pos*2+1].lazytag=tree[pos].lazytag;//懒惰标签下移
            tree[pos].lazytag=-1;
        }
    }
}
//更新懒惰标签
void update(int l,int r,int tag,int pos)
{
    if(tree[pos].l==l&&tree[pos].r==r)
        tree[pos].lazytag=tag;
    else
    {
        release(pos);
        int mid=(tree[pos].l+tree[pos].r)/2;
        if(r<=mid)
            update(l,r,tag,pos*2);
        else if(l>=mid)
            update(l,r,tag,pos*2+1);
        else
        {
            update(l,mid,tag,pos*2);
            update(mid,r,tag,pos*2+1);
        }
    }
}
//遍历线段树求能看到的海报数
void read_tree(int pos)
{
    if(tree[pos/2].r-tree[pos/2].l==1)//父亲已经是叶子节点了，不要继续访问
        return;
    if(tree[pos].lazytag!=-1)
        ans.insert(tree[pos].lazytag);//如果这个区间能看到海报，则无需继续访问子节点
    else
    {
        read_tree(pos*2);
        read_tree(pos*2+1);
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    pre_init();
    build(1,m,1);
    for(int i=0;i<n;i++)
        update(left1[i],right1[i],i,1);
    read_tree(1);
    printf("%d\n",ans.size());
    return 0;
}
