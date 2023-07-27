struct segment_tree{
    struct node{
        int add_tag=0;
        int set_tag=0;
        int sum=0;
        int ma=0;
    };
 
    vector<node> arr;
 
    void init(int n){
        arr.resize(n<<2);
    }
 
    node pull(node A, node B){
        node C;
        C.sum=A.sum+B.sum;
        C.ma=max(A.ma, B.ma);
        return C;
    }
 
    void push(int idx, int ll, int rr){
        if (arr[idx].set_tag>0){
            // set 優先實作
            arr[idx].sum=(rr-ll)*arr[idx].set_tag;
            arr[idx].ma=arr[idx].set_tag;
 
            if (rr-ll>1){
                arr[idx*2+1].add_tag=0;
                arr[idx*2+1].set_tag=arr[idx].set_tag;
                arr[idx*2+2].add_tag=0;
                arr[idx*2+2].set_tag=arr[idx].set_tag;
            }
 
            arr[idx].set_tag=0;
        }
        if (arr[idx].add_tag>0){
            // add 次要實作
            arr[idx].sum+=(rr-ll)*arr[idx].add_tag;
            arr[idx].ma+=arr[idx].add_tag;
 
            if (rr-ll>1){
                arr[idx*2+1].add_tag+=arr[idx].add_tag;
                arr[idx*2+2].add_tag+=arr[idx].add_tag;
            }
 
            arr[idx].add_tag=0;
        }
    }
 
    void build(vector<int> &v, int idx=0, int ll=0, int rr=n){
        if (rr-ll==1){
            arr[idx].sum=v[ll];
            arr[idx].ma=v[ll];
        }else{
            int mid=(ll+rr)/2;
            build(v, idx*2+1, ll, mid);
            build(v, idx*2+2, mid, rr);
            arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
        }
    }
 
    void add(int ql, int qr, int val, int idx=0, int ll=0, int rr=n){
        push(idx, ll, rr);
        if (rr<=ql || qr<=ll) return;
        if (ql<=ll && rr<=qr){
            arr[idx].add_tag+=val;
            push(idx, ll, rr);
            return;
        }
        int mid=(ll+rr)/2;
        add(ql, qr, val, idx*2+1, ll, mid);
        add(ql, qr, val, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }
 
    void set(int ql, int qr, int val, int idx=0, int ll=0, int rr=n){
        push(idx, ll, rr);
        if (rr<=ql || qr<=ll) return;
        if (ql<=ll && rr<=qr){
            arr[idx].add_tag=0;
            arr[idx].set_tag=val;
            push(idx, ll, rr);
            return;
        }
        int mid=(ll+rr)/2;
        set(ql, qr, val, idx*2+1, ll, mid);
        set(ql, qr, val, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
    }
 
    node query(int ql, int qr, int idx=0, int ll=0, int rr=n){
        push(idx, ll, rr);
        if (rr<=ql || qr<=ll) return node();
        if (ql<=ll && rr<=qr) return arr[idx];
 
        int mid=(ll+rr)/2;
        return pull(query(ql, qr, idx*2+1, ll, mid), query(ql, qr, idx*2+2, mid, rr));
    }
} ST;