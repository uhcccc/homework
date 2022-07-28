# homework
# SM3算法
### 一、SM3算法基本介绍
SM3算法是杂凑值算法（或称为哈希算法）的一种，其通过对数据的填充、分组、扩张压缩等方式计算成特定长度的数值，从而对数据进行加密，SM3算法分组长度为512bit，最终计算长度为256bit。
### 二、SM算法原理解析
#### （一）消息填充
首先将比特“1“ 添加到消息的末尾，再添加k个"0"， k是满足l + 1 + k ≡ 448mod512 的最小的非负整数。然后再添加一个64位比特串，使得填充后的消息的长度为512比特的倍数。
#### （二）迭代
消息分组和初始值进入MD结构进行迭代压缩，即H(i+1)=CF(H(i),B(i))，其中B为每个分块，CF为压缩函数，H为连接变量哈希函数，i=1,2……n。伪代码实现如下：<br>
for i = 0 to n-1<br>
H(i+1)=CF(H(i),B(i))<br>
endfor
#### （三）消息编排
当消息填充完成后，将消息块B(i)分为16个32比特字W0, W1, … ,W15。伪代码实现如下：<br>
for i = 16 to 67<br>
Wj ← P1(Wj-16⊕Wj- 9⊕(Wj-3<<< 15))⊕(Wj-18<<< 7)⊕Wj-6<br>
endfor<br>
for i = 0 tO 63<br>
W’j ← Wj⊕Wj+4<br>
endfor
#### （四）压缩函数
将消息长度压缩为256bit。实现代码如下：<br>
for i = 0 to 63<br>
SS1 ← ((A <<< 12) + E + (Tj <<< (j mod 32))) <<< 7<br>
SS2 ← SS1⊕(A<<<12)<br>
TT1 ← FFj(A,B,C)+ D + SS2 + W’j<br>
TT2 ← GGj(E,F,G)+H +SS1 + Wj<br>
D←C<br>
C←B<<< 9<br>
B←A<br>
A←TT1<br>
H←G<br>
G←F<<<19<br>
F←E<br>
E←P0(TT2)<br>
endfor<br>
H(i+1) = ABCDEFGH⊕H(i)<br>
