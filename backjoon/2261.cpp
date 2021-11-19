////////////////////(1)
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
    int x,y;
    point(){}
    point(int x,int y) : x(x), y(y){}
};
bool cmp(const point &u, const point &v){
    return u.x < v.x;
}
bool cmp2(const point &u, const point &v){
    return u.y < v.y;
}
int dist(point &p1, point &p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main(){
    int n;
    cin >> n;
    vector<point> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(),a.end(),cmp);
    vector<point> candidate = {a[0],a[1]};
    int ans = dist(a[0],a[1]);
    for(int i=2;i<n;i++){
        point now = a[i];
        for(auto it = candidate.begin();it!=candidate.end();){
            auto p = *it;
            int x = now.x - p.x;
            if(x*x > ans){
                it= candidate.erase(it);
            }
            else{
                it++;
            }
        }
        sort(candidate.begin(),candidate.end(),cmp2);
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = point(-100000, now.y-d);
        auto upper_point = point(100000, now.y+d);
        auto lower = lower_bound(candidate.begin(),candidate.end(),lower_point, cmp2);
        auto upper = upper_bound(candidate.begin(),candidate.end(),upper_point, cmp2);
        for(auto it = lower; it!=upper; it++){
            int d = dist(now, *it);
            if(d < ans){
                ans = d;
            }
        }
        candidate.push_back(now);
    }
    cout << ans << '\n';
    return 0;
}
*/
////////////////(2)
/*
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
struct point{
    int x,y;
    point(){}
    point(int x, int y):x(x),y(y){}
    bool operator < (const point &v) const {
        if(y==v.y) return x < v.x;
        else return y < v.y;
    }
};
bool cmp(const point &u, const point &v){
    return u.x < v.x;
}
int dist(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main(){
    int n;
    cin >> n;
    vector<point> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(),a.end(),cmp);
    set<point> candidate = {a[0],a[1]};
    int ans = dist(a[0],a[1]);
    for(int i=2;i<n;i++){
        point now = a[i];
        for(auto it = candidate.begin();it!=candidate.end();){
            auto p = *it;
            int x = now.x - p.x;
            if(x*x>ans){
                it = candidate.erase(it);
            }
            else{
                it++;
            }
        }
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = point(-100000,now.y-d);
        auto upper_point = point(100000,now.y+d);
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for(auto it = lower; it!=upper;it++){
            int d = dist(now, *it);
            if(d < ans){
                ans = d;
            }
        }
        candidate.insert(now);
    }
    cout << ans << '\n';
    return 0;
}
*/
/////////////////////(3)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
struct point{
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    bool operator < (const point &v) const {
        if(y == v.y) return x < v.x;
        else return y < v.y;
    }
};
bool cmp(const point &u, const point &v){
    return u.x < v.x;
}
int dist(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<point> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a.begin(), a.end(), cmp);
    set<point> candidate = {a[0], a[1]};
    int ans = dist(a[0], a[1]);
    int start = 0;
    for(int i=2; i<n; i++){
        point now = a[i];
        while(start < i) {
            auto p = a[start];
            int x = now.x - p.x;
            if(x*x > ans){
                candidate.erase(p);
                start += 1;
            }
            else
                break;
        }
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = point(-100000, now.y-d);
        auto upper_point = point(100000, now.y+d);
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for(auto it = lower; it != upper; it++){
            int d = dist(now, *it);
            if(d < ans)
                ans = d;
        }
        candidate.insert(now);
    }
    cout << ans << '\n';
    return 0;
}