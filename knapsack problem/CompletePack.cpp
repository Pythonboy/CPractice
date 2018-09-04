题目：
有N种物品和一个容量为V的背包，每种物品都有无限件可用。第i种物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和
不超过背包容量，且价值总和最大。


二维数组：
f[i][v]=max{f[i-1][v-k*c[i]]+k*w[i]|0<=k*c[i]<=v}

一维数组：
for i=1..N
    for v=0..V
        f[v]=max{f[v],f[v-cost]+weight}
伪代码：
procedure CompletePack(cost,weight)
    for v=cost..V
        f[v]=max{f[v],f[v-c[i]]+w[i]}
