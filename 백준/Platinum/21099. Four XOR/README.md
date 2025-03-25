# [Platinum IV] Four XOR - 21099 

[문제 링크](https://www.acmicpc.net/problem/21099) 

### 성능 요약

메모리: 2396 KB, 시간: 0 ms

### 분류

수학, 비둘기집 원리

### 제출 일자

2024년 11월 10일 17:28:06

### 문제 설명

<p>Given a sequence $A_{1...n}$ of distinct integers, you need to answer whether there exist four indices $x, y, z, w$ such that $1 \le x < y < z < w \le n$ and $A_x \oplus A_y \oplus A_z \oplus A_w = 0$.</p>

<p>Recall that $x \oplus y$ means the bitwise exclusive-or between $x$ and $y$, sometimes expressed as $x \mathrm{xor} y$.</p>

### 입력 

 <p>The first line contains a single integer $n$ ($4 \le n \le 10^5$).</p>

<p>The second line contains $n$ integers $A_{1...n}$ ($0 \le A_i \le 10^5$). It is guaranteed that all $A_i$ are distinct.</p>

### 출력 

 <p>Output "<code>Yes</code>" if there are four indices satisfying the conditions, or "<code>No</code>" otherwise.</p>

