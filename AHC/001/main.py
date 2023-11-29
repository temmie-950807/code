import time
from random import randint

class Square():
    #長方形
    def __init__(self, y, x, h, w, r) -> None:
        # 左上の頂点座標
        self.y = y
        self.x = x
        # 高さと幅
        self.h = h
        self.w = w
        # 右下の頂点座標
        self.v = y + h
        self.u = x + w
        #要求された点
        self.p = y + 0.5
        self.q = x + 0.5
        #要求された面積
        self.r = r
    
    def is_ok(self):#要求された点が範囲内にあるか、広告が指定の範囲内にあるか
        return 0 <= self.y and self.v <= 9999 and 0 <= self.x and self.u <= 9999 and self.y < self.p < self.v and self.x < self.q < self.u
    
    def score(self):#満足度
        s = self.w * self.h
        return 1 - (1 - min(self.r, s) / max(self.r, s)) ** 2
    
    def add_up(self):#上に1マス大きくする
        self.y -= 1
        self.h += 1
    
    def remove_up(self):#上1マス削る
        self.y += 1
        self.h -= 1
    
    def add_down(self):#下に1マス大きくする
        self.h += 1
        self.v += 1
    
    def remove_down(self):#下1マス削る
        self.h -= 1
        self.v -= 1
    
    def add_left(self):#左に1マス大きくする
        self.x -= 1
        self.w += 1
    
    def remove_left(self):#左1マス削る
        self.x += 1
        self.w -= 1
    
    def add_right(self):#右に1マス大きくする
        self.w += 1
        self.u += 1
    
    def remove_right(self):#右1マス削る
        self.w -= 1
        self.u -= 1
    
    def move_up(self):#上に1マス移動
        self.y -= 1
        self.v -= 1
    def move_down(self):#下に1マス移動
        self.y += 1
        self.v += 1
    def move_left(self):#左に1マス移動
        self.x -= 1
        self.u -= 1
    def move_right(self):#右に1マス移動
        self.x += 1
        self.v += 1
    
    def print_points(self):#左上と右下の頂点を出力
        print("{} {} {} {}".format(self.x, self.y, self.u, self.v))

def overlap(a : Square, b : Square) -> bool:
    #2つの長方形が重なるか判定
    return not (max(a.x, b.x) <= min(a.u, b.u) and max(a.y, b.y) <= min(a.v, b.v))

def is_ok(i : int) -> bool:
    #i番目の長方形と他の長方形が重複していないかを見る
    for j in range(N):
        if i == j:
            continue
        if not overlap(ad[i], ad[j]):
            return False
    return True


t1 = time.time()
N = int(input())
ad: list[Square] = []
for _ in range(N):
    x, y, r = map(int, input().split())
    ad.append(Square(y, x, 1, 1, r))
t2 = time.time()
count = 0
while t2 - t1 < 4.9:
    count += 1
    i = randint(0, N - 1)
    j = randint(0, 8)
    tmp_score = ad[i].score()
    if j == 0:
        ad[i].add_up()
        if not ad[i].is_ok() or tmp_score > ad[i].score() or not is_ok(i):
            ad[i].remove_up()
    elif j == 1:
        ad[i].add_down()
        if not ad[i].is_ok() or tmp_score > ad[i].score() or not is_ok(i):
            ad[i].remove_down()
    elif j == 2:
        ad[i].add_left()
        if not ad[i].is_ok() or tmp_score > ad[i].score() or not is_ok(i):
            ad[i].remove_left()
    elif j == 3:
        ad[i].add_right()
        if not ad[i].is_ok() or tmp_score > ad[i].score() or not is_ok(i):
            ad[i].remove_right()
    elif j == 4:
        ad[i].move_up()
        if not ad[i].is_ok() or not is_ok(i):
            ad[i].move_down()
    elif j == 5:
        ad[i].move_down()
        if not ad[i].is_ok() or not is_ok(i):
            ad[i].move_up()
    elif j == 5:
        ad[i].move_left()
        if not ad[i].is_ok() or not is_ok(i):
            ad[i].move_right()
    elif j == 5:
        ad[i].move_right()
        if not ad[i].is_ok() or not is_ok(i):
            ad[i].move_left()
    t2 = time.time()
for s in ad:
    s.print_points()