struct Segment_Tree {
    struct Node {
        int tag, sum;
        void update(int val, int l, int r) {sum += val * (r - l + 1), tag += val;}
    } seg[4 * MAX_SIZE];

    void pull(int id) {
        seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
    }
    void push(int id, int l, int r) {
        if (id * 2 >= 4 * MAX_SIZE) return;
        int tag = seg[id].tag;
        int mid = (l + r) / 2;
        seg[id * 2].update(tag, l, mid);
        seg[id * 2 + 1].update(tag, mid + 1, r);
        seg[id].tag = 0;
    }
    void build(int id, int l, int r) {
        if (l == r) {
            seg[id].sum = seg[id].tag = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        pull(id);
        seg[id].sum = seg[id].tag = 0;
    }

    void update(int id, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            seg[id].update(val, l, r);
            return;
        }
        if (ql > r || qr < l) return;
        else {
            int mid = (l + r) / 2;
            push(id, l, r);
            update(id * 2, l, mid, ql, qr, val);
            update(id * 2 + 1, mid + 1, r, ql, qr, val);
            pull(id);
        }
    }

    int query(int id, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr)
            return seg[id].sum;
        int mid = (l + r) / 2;
        push(id, l, r);
        return query(id * 2, l, mid, ql, qr) + query(id * 2 + 1, mid + 1, r, ql, qr);
    }

    pair<int, int> maxposquery(int id, int l, int r, int ql, int qr) {
        int mid = (l + r) / 2;
        if (ql > r || qr < l) return {0, 0};
        push(id, l, r);

        if (seg[id].sum == 0)
            return {0, 0};
        if (ql <= l && r <= qr) {
            if (seg[id].sum && l == r)
                return {l, seg[id].sum};
            if (seg[id].sum) {
                if (seg[id * 2 + 1].sum)
                    return maxposquery(id * 2 + 1, mid + 1, r, ql, qr);
                else
                    return maxposquery(id * 2, l, mid, ql, qr);
            }
            else
                return {0, seg[id].sum};
        }

        if (query(id * 2 + 1, mid + 1, r, ql, qr))
            return maxposquery(id * 2 + 1, mid + 1, r, ql, qr);
        else
            return maxposquery(id * 2, l, mid, ql, qr);
    }

    pair<int, int> minposquery(int id, int l, int r, int ql, int qr) {
        int mid = (l + r) / 2;
        if (ql > r || qr < l) return {INF, 0};
        push(id, l, r);
        if (seg[id].sum == 0)
            return {INF, 0};
        if (ql <= l && r <= qr) {
            if (l == r)
                return {l, seg[id].sum};
            if (seg[id].sum) {
                if (seg[id * 2].sum)
                    return minposquery(id * 2, l, mid, ql, qr);
                else
                    return minposquery(id * 2 + 1, mid + 1, r, ql, qr);
            }
            else
                return {INF, seg[id].sum};
        }

        if (query(id * 2, l, mid, ql, qr))
            return minposquery(id * 2, l, mid, ql, qr);
        else 
            return minposquery(id * 2 + 1, mid + 1, r, ql, qr);
    }
} ST;