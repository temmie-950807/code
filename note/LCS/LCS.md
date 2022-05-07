# Longest Common Subsequence (最長共同子序列)
連續的文字必須順序相同, 但是不一定要是連續的
`abcabcba`, `cbabcabcc`的最長共同子序列為`abcabc`

用DP處理, 透過分割字串來解決

 | X   | X   | A      | B   | C      |
 | --- | --- | ------ | --- | ------ |
 | X   | 0   | 0      | 0   | 0      |
 | A   | 0   | ==1↖== | 1←  | 1←     |
 | D   | 0   | 1↑     | 1↑  | 1↑     |
 | C   | 0   | 1↑     | 1↑  | ==2↖== |
選擇朝左上前進的字串: 可知LCS為`AC`

# Longest Common Substring (最長共同子字串)
連續的文字必須相連
`abcaa`, `aabca`, `aaabc`的最長共同子字串為`abc`

