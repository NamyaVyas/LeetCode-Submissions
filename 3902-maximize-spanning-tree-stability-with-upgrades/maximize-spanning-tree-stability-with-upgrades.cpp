class DSU {
public:
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.resize(n,0);
        for(int i=0;i<n;i++) p[i]=i;
    }

    int find(int x){
        if(p[x]!=x) p[x]=find(p[x]);
        return p[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;

        if(r[a]<r[b]) swap(a,b);
        p[b]=a;

        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, int x){

        DSU dsu(n);
        int used=0, upgrades=0;

        vector<pair<int,int>> normal;
        vector<pair<int,int>> needUpgrade;

        for(auto &e: edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must){
                if(s < x) return false;

                if(!dsu.unite(u,v))
                    return false;

                used++;
            }
            else{
                if(s >= x)
                    normal.push_back({u,v});
                else if(2LL*s >= x)
                    needUpgrade.push_back({u,v});
            }
        }

        // use normal edges first
        for(auto &e: normal){
            if(dsu.unite(e.first,e.second)){
                used++;
                if(used==n-1) return true;
            }
        }

        // then upgraded edges
        for(auto &e: needUpgrade){
            if(upgrades==k) break;

            if(dsu.unite(e.first,e.second)){
                upgrades++;
                used++;
                if(used==n-1) return true;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=0, hi=200000, ans=-1;

        while(lo<=hi){

            int mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans;
    }
};