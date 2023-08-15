#include <bits/stdc++.h>

#define 使用 using
#define 名字空格 namespace
#define 虛空 void
#define 主要 main
#define 回傳 return

#define 常數 const
#define 整數 int
#define 布林 bool
#define 浮點數 double

#define 輸入 cin
#define 輸出 cout
#define 蛤 if
#define 三小 else
#define 給 for
#define 當 while
#define 向量 vector
#define 推背 push_back
#define 清空 clear
#define 大小 size
#define 出口 exit

#define 或 ||
#define 且 &&
#define 設為 =
#define 無言 ==
#define 小於  左 
#define 大於等於 >=
#define 加一 ++
#define 減一 --
#define 乘 *
#define 加 +
#define 減 -
#define 右 >
#define 右右 >>
#define 左 <
#define 左左 <<
#define 分號 ;
#define 驚訝 !
#define 左圓圓 (
#define 右圓圓 )
#define 左尖尖 {
#define 右尖尖 }
#define 左方方 [
#define 右方方 ]

#define 空格 " "
#define 換行 endl

使用 名字空格 std;

虛空 解法一(){

    整數 長度 設為 0;
    整數 甲 設為 0, 乙 設為 0;

    輸入 >> 長度;
    給 (整數 子 設為 0 ; 子 左 長度 ; 子++){
        整數 元素;
        輸入 >> 元素;

        蛤 (元素%2==0){
            甲++;
        }三小 {
            乙++;
        }
    }

    蛤 (乙%2==0){
        輸出 << "YES\n";
    }else{
        輸出 << "NO\n";
    }

    回傳;
}

整數 主要(){

    整數 測試資料=0;
    輸入 >> 測試資料;

    當 (測試資料--){
        解法一();
    }

    回傳 0;
}