struct segment_tree{
    // [ll, rr)
    struct node{
        int sum;
    } seg[4*MAX_SIZE];

    node combine(node a, node b){
        node c;
        c.sum=a.sum+b.sum;
        
        return c;
    }

    void build(vector<int> *a, int idx, int ll, int rr){
        if (rr-ll==1){
            seg[idx].sum=(*a)[ll];
            return;
        }
        int mid=(ll+rr)/2;

        build(a, idx*2+1, ll, mid);
        build(a, idx*2+2, mid, rr);
        seg[idx].sum=combine(seg[2*idx+1].sum, seg[2*idx+2].sum);

    }

    void update(int pos, int idx, int ll, int rr, int val){
        if (rr-ll==1){
            seg[idx].sum=val;
            return;
        }
        int mid=(ll+rr)/2;
        if (pos<mid) update(pos, 2*idx+1, ll, mid, val);
        else update(pos, 2*idx+2, mid, rr, val);
        seg[idx].sum=combine(seg[2*idx+1].sum, seg[2*idx+2].sum);
        
    }

    int query(int idx, int ll, int rr, int ql, int qr){
        if (rr<=ql || qr<=ll) return 0;
        else if (ql<=ll && rr<=qr) return seg[idx].sum;
        else{
            int mid=ll+(rr-ll)/2;
            return combine(query(2*idx+1, ll, mid, ql, qr), query(2*idx+2, mid, rr, ql, qr));
        }
    }

} ST;