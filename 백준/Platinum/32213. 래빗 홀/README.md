# [Platinum II] 래빗 홀 - 32213 

[문제 링크](https://www.acmicpc.net/problem/32213) 

### 성능 요약

메모리: 2020 KB, 시간: 16 ms

### 분류

게임 이론, 스프라그–그런디 정리

### 제출 일자

2024년 10월 31일 20:25:55

### 문제 설명

<p>옛날 옛적, 평화로운 마을에 기이한 일이 벌어졌다. 하늘에서 토끼가 떨어졌다. 놀란 토끼들은 재빨리 지하의 래빗 홀로 숨어들었고 마을은 순식간에 혼란에 빠졌다. 이 소동을 지켜보던 두 마법소녀, 화학소녀와 문학소녀가 있었다. 두 마법소녀는 마을의 평화를 되찾기 위해 토끼와의 전쟁을 선포했다. 하지만 이는 단순한 토끼 사냥이 아닌 마법소녀의 지혜와 재능을 겨루는 승부이기도 했다.</p>

<p>마법소녀들은 먼저 상황을 파악했다. 마을 곳곳에는 $N$개의 래빗 홀이 있었고 $i$번째 래빗 홀에는 토끼가 $K_i$마리 살고 있었다. 두 마법소녀의 공통된 목표는 단 하나, 모든 토끼를 하늘로 올려보내고 빈 래빗 홀 하나만 남기는 것이었다. 두 마법소녀는 번갈아 가며 능력을 사용했다. 손가락을 한 번 튕기면 각 마법소녀의 두 능력 중 정확히 하나의 능력이 발동한다.</p>

<ol>
	<li>토끼가 한 마리 이상 있는 래빗 홀 하나를 골라 원하는 만큼의 토끼를 하늘로 보낸다. 단, 적어도 한 마리는 하늘로 올려보내야 한다.</li>
	<li>서로 다른 래빗 홀 두 개를 고른다. 토끼가 $0$마리 들어있는 래빗 홀도 고를 수 있다. 두 개의 래빗홀에 들어있던 토끼가 각각 $A$마리와 $B$마리라고 하면 두 수를 bitwise XOR한 $A \oplus B$마리의 토끼가 담긴 새로운 래빗 홀을 만든다. 그 후 선택한 두 래빗 홀을 없애고 안에 있던 토끼를 모두 하늘로 보낸다.</li>
</ol>

<p>두 명이 협력하면 빨리 전쟁을 끝낼 수 있지만 이것은 화학과 문학의 자존심 대결. 화학소녀부터 시작해서 화학소녀와 문학소녀는 번갈아 가며 손가락을 한 번씩 튕겨 능력을 발동한다. 두 마법소녀가 모두 최선을 다한다고 했을 때, 마지막으로 손가락을 튕겨서 마지막에 빈 래빗 홀 하나만 남기는 영광을 차지해 전쟁과 승부 모두에서 승리하는 것은 누구일까?</p>

### 입력 

 <p>입력에는 여러 개의 테스트케이스로 구성되어 있다.</p>

<p>첫째 줄에 테스트케이스의 개수를 나타내는 자연수 $T$가 주어지고, 이후 차례로 $T$개의 테스트 케이스가 주어진다. $(1 \le T \le 50\,000)$</p>

<p>각 테스트케이스의 첫 줄에는 래빗 홀의 개수 $N$이 주어진다. $(2 \le N \le 100\,000)$</p>

<p>다음 줄에 $N$개의 정수가 공백으로 구분되어 주어진다. $i$번째 정수는 $i$번 래빗 홀에 들어있는 토끼의 수 $K_i$이다. $(1 \le K_i \le 10^9)$</p>

<p>한 입력에 해당하는 테스트케이스에서 주어지는 $N$의 총합은 $100\,000$을 넘지 않는다.</p>

### 출력 

 <p>각 테스트케이스마다 한 줄에 하나씩, 먼저 차례를 가지는 화학소녀가 승리하면 <span style="color:#e74c3c;"><code>eerste</code></span>, 나중에 차례를 가지는 문학소녀가 승리하면 <span style="color:#e74c3c;"><code>tweede</code></span>를 출력하여라.</p>

