#include <bits/stdc++.h>
using namespace std;

long long int getdist2(pair<int, int> p1, pair<int,int> p2) {
    /*long long dist2 = pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2);*/ // dont use pow for squaring integers, some floating point and double bs
    long long dx = p1.first - p2.first;
    long long dy = p1.second - p2.second;
    return dx*dx + dy*dy;
}
bool comparebysecond(pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
}
long long int solve(vector<pair<int,int>>& points, int l, int h) {
    long long dL2;
    long long dR2;
    int m=(l+h)/2;
    if(h-l==1) {
        return getdist2(points[l],points[h]); 
    }
    else if(h-l==2) {
        return min(getdist2(points[l],points[l+1]),min(getdist2(points[l],points[h]),getdist2(points[l+1],points[h])));
    }
    dL2=solve(points,l,m);
    dR2=solve(points,m+1,h);
    long long d2 = min(dL2,dR2);
    //now checking if there exists a point in left and a point in right region such that the dist bw them is less than d
    vector<pair<int,int>> p;
    for(int i=m;i>=l;i--) {
        if((points[m].first - points[i].first) > sqrt(d2)) {
            break;
        }
        p.push_back(points[i]);
    }
    for(int i=m+1;i<=h;i++) {
        if((points[i].first - points[m].first) > sqrt(d2)) {
            break;
        }
        p.push_back(points[i]);
    }
    sort(p.begin(),p.end(),comparebysecond); //to sort by y
    for(auto i=0;i<p.size();i++) {
        for(auto j=i+1;j<p.size();j++) {
            long long dy=p[j].second - p[i].second;
            if(dy*dy > d2) break;
            d2=min(d2,getdist2(p[i],p[j]));
        }
    }
    return d2;
}
int main() {
    int n; cin >> n;
    vector<pair<int, int>> points;
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    sort(points.begin(),points.end());
    long long d = solve(points, 0, n-1);
    cout << d << endl;
}
