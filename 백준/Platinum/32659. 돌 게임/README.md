# [Platinum I] 돌 게임 - 32659 

[문제 링크](https://www.acmicpc.net/problem/32659) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

게임 이론, 스프라그–그런디 정리

### 제출 일자

2024년 11월 13일 19:37:14

### 문제 설명

<p>크기가 $1 \times N$인 게임판 위의 짝수 개의 칸에 흑돌과 백돌이 같은 개수로 번갈아서 배치되어 있다.</p>

<p>이 게임판을 이용해 게임을 하는데 규칙은 다음과 같다.</p>

<ul>
	<li>선공과 후공이 한 턴씩 번갈아가면서 게임을 진행한다. 선공은 흑, 후공은 백으로 게임을 진행한다.</li>
	<li>두 플레이어는 자신의 턴에 자신의 색깔의 돌을 하나 선택하여 좌우로 원하는 만큼 움직일 수 있다. 돌을 움직이지 않을 수는 없으며, 다른 돌을 뛰어넘거나 이미 돌이 있는 칸으로 움직이는 것은 불가능하다.</li>
	<li>자신의 턴에 돌을 움직일 수 없는 플레이어가 게임에서 패배한다.</li>
</ul>

<p>두 플레이어가 최선의 전략으로 게임을 할 때 누가 이길지 알아보자. 만약 $10^{100}$ 턴이 지나도 승부가 결정되지 않으면 무승부로 판정한다.</p>

### 입력 

 <p>첫 번째 줄에 게임판의 상태를 나타내는 문자열 $S$가 주어진다. $(2 \le \vert S\vert \le 5\,000)$</p>

<p>$S$ 는 <span style="color:#e74c3c;"><code>B</code></span>, <span style="color:#e74c3c;"><code>W</code></span>, <span style="color:#e74c3c;"><code>.</code></span>으로만 구성되어 있으며, <span style="color:#e74c3c;"><code>B</code></span>는 흑돌, <span style="color:#e74c3c;"><code>W</code></span>는 백돌, <span style="color:#e74c3c;"><code>.</code></span>은 빈칸을 의미한다. 흑돌과 백돌은 적어도 하나 이상 있음이 보장된다.</p>

### 출력 

 <p>첫 번째 줄에 선공이 이긴다면 <span style="color:#e74c3c;"><code>Win</code></span>, 선공이 진다면 <span style="color:#e74c3c;"><code>Lose</code></span>를 출력한다. 만약 $10^{100}$ 턴이 지나도 승부가 결정되지 않으면 <span style="color:#e74c3c;"><code>Draw</code></span>를 출력한다.</p>

