# homework
# SM3算法
### 一、SM3算法基本介绍
SM3算法是杂凑值算法（或称为哈希算法）的一种，其通过对数据的填充、分组、扩张压缩等方式计算成特定长度的数值，SM3算法分组长度为512bit，最终计算长度为256bit。该算法常用于商业密码应用中的数字签名和验证，其安全性和SHA-256相当。<br>
算法的实现一共需要四步，即消息填充、迭代、消息扩展、消息压缩。
### 二、SM3算法原理解析
#### （一）消息填充
SM3的消息扩展步骤是以512位的数据分组作为输入的。因此，我们需要在一开始就把数据长度填充至512位的倍数。首先将比特“1“ 添加到消息的末尾，再添加k个"0"， k是满足l + 1 + k ≡ 448mod512 的最小的正整数。然后再添加一个64位比特串，使得填充后的消息的长度为512比特的倍数。<br>
实现代码如下：<br>
![8140d39a7fd9776f036211937c131ba](https://user-images.githubusercontent.com/110144909/181444624-10d61877-4aed-4bce-8315-3e5af12edbbd.png)
算法的初始值共256bit，由如下8个32bit串联构成：<br>
![7e5567b31eeddd20ba468f7b55821e5](https://user-images.githubusercontent.com/110144909/181445232-6495bb28-0868-484d-8d7a-d54606eff4dd.png)

#### （二）迭代
消息分组和初始值进入MD结构进行迭代压缩，即H(i+1)=CF(H(i),B(i))，其中B为每个分块，CF为压缩函数，H为连接变量哈希函数，i=1,2……n。<br>
伪代码实现如下：<br>
for i = 0 to n-1<br>
H(i+1)=CF(H(i),B(i))<br>
endfor<br>
实现代码如下：<br>
![5e7b8a76ac46b573ecb41af1d2355ce](https://user-images.githubusercontent.com/110144909/181444825-65594718-f99c-405c-84ce-6d8ba80bd48a.png)
#### （三）消息扩展
当消息填充完成后，将消息块B(i)分为16个32比特字W0, W1, … ,W15。<br>
伪代码实现如下：<br>
for i = 16 to 67<br>
Wj ← P1(Wj-16⊕Wj- 9⊕(Wj-3<<< 15))⊕(Wj-18<<< 7)⊕Wj-6<br>
endfor<br>
for i = 0 tO 63<br>
W’j ← Wj⊕Wj+4<br>
endfor<br>
实现代码如下：<br>
![a385df82510119b75d32dad69464d63](https://user-images.githubusercontent.com/110144909/181444481-759b1663-37b5-4707-a9d3-a996b7b6e379.png)
#### （四）消息压缩
将消息长度压缩为256bit。<br>
伪代码实现如下：<br>
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
代码实现如下：<br>
![617c3fa0e01d2263a0cf7c60a637427](https://user-images.githubusercontent.com/110144909/181444413-0520dff9-eee4-41f7-8833-40f8eafa8884.png)
### 三、运行过程


