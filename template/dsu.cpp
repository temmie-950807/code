struct Disjoint_Set{
    vector<int> arr, sz;

    void init(int n){ // 使用前，要傳入陣列大小初始化
        arr.resize(n+10);
        sz.resize(n+10);
        for (int i=0 ; i<n ; i++){
            arr[i]=i;
            sz[i]=1;
        }
    }

    int find(int a){ // 回傳 a 節點的 leader
        if (arr[a]==a) return a;
        else return arr[a]=find(arr[a]); // 路徑壓縮優化
    }

    void unite(int a, int b){ // 將兩個節點合併
        a=find(a);
        b=find(b);

        if (a!=b){
            if (sz[a]<sz[b]) swap(a, b); // 啟發式合併優化
            arr[b]=a;
            sz[a]+=sz[b];
        }
    }
} dsu;