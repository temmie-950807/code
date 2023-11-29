// [ll, rr), based-0
// 使用前記得 init, build
struct Segment_Tree{
    struct node{
        int sum;
    };

    vector<node> arr;

    void init(int sz){
        arr.resize(sz<<2);
    }

    node pull(node A, node B){
        node C;
        C.sum=A.sum+B.sum;
        return C;
    }

    void build(vector<int> &v, int idx, int ll, int rr){
        if (rr-ll==1){
            arr[idx].sum=v[ll];
            return;
        }

        int mid=(ll+rr)/2;
        build(v, idx*2+1, ll, mid);
        build(v, idx*2+2, mid, rr);
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
        return;
    }

    void update(int pos, int val, int idx, int ll, int rr){
        if (rr-ll==1){
            arr[idx].sum=val;
            return;
        }

        int mid=(ll+rr)/2;
        if (pos<mid){
            update(pos, val, idx*2+1, ll, mid);
        }else{
            update(pos, val, idx*2+2, mid, rr);
        }
        arr[idx]=pull(arr[idx*2+1], arr[idx*2+2]);
        return;
    }

    node query(int ql, int qr, int idx, int ll, int rr){
        if (rr<=ql || qr<=ll) return node();
        if (ql<=ll && rr<=qr) return arr[idx];

        int mid=(ll+rr)/2;
        return pull(query(ql, qr, idx*2+1, ll, mid), query(ql, qr, idx*2+2, mid, rr));
    }
    
} ST;