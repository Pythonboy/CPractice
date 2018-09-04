状态转移方程：
二维数组情况下：
f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}

一维数组情况下：
for i=1..N
    for v=V..0
        f[v]=max{f[v],f[v-c[i]]+w[i]};
即：
for i=1..N
    ZeroOnePack(c[i],w[i]);
procedure ZeroOnePack(cost,weight)
    for v=V..cost
        f[v]=max{f[v],f[v-cost]+weight}
