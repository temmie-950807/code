# 這是python的一行解，主要是透過()約束優先級，不過會有遞迴過深的問題，在zj上不可用
print(eval("(" + input().replace("(", "([(").replace(")", ")])").replace(",", "),(").replace("*", ")*(") + ")", {"f": (lambda l : max(l)-min(l))}))