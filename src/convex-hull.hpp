#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using pt = ii;

ll orientation(pt a, pt b, pt c)
{
    ll v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if(v<0) return -1; // clockwise
    if(v>0) return +1; // counter-clockwise
    return 0;
}

// doesn't include collinear
vector<pt> convex_hull(vector<pt>& a)
{
    ll n=a.size(),mn=0;
    for(ll i=1;i<n;i++)
        if(a[i].x<a[mn].x||(a[i].x==a[mn].x&&a[i].y<a[mn].y))
            mn = i;
    pt p0 = a[mn];
    sort(a.begin(),a.end(),[&p0](const pt& a, const pt& b){
        ll o = orientation(p0,a,b);
        if(o==0)
        {
            ll da = (a.x-p0.x)*(a.x-p0.x)+(a.y-p0.y)*(a.y-p0.y);
            ll db = (b.x-p0.x)*(b.x-p0.x)+(b.y-p0.y)*(b.y-p0.y);
            return da<db;
        }
        return o==1;
    });
    vector<pt> res;
    for(ll i=0;i<n;i++)
    {
        while(res.size()>0&&res.back()==a[i])
            res.pop_back();
        while((res.size()>1)&&(orientation(res[res.size()-2],res.back(),a[i])!=1))
            res.pop_back();
        res.push_back(a[i]);
    }
    return res;
}