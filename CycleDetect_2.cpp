//从某点出判断无向图是否有回路（图用邻接矩阵表示）。假如有N个点，需要调用N次该函数。因为考虑到孤立点的因素，需要从每个点都开始一次。
    bool isHuiLu(int begin, int temp[][MAXLEN])
    {
        bool flag[MAXLEN];
        int i, j;
        stack <int>stk;
        queue <int> vexQueue;
        for (i = 0; i<vexnum; i++)
            flag[i] = false;
        //从a或b点出发，广度遍历所有点
        //如果该点和之前已访问过的点（除了它父亲）有边，
        //说明有回路
        vexqueue.push(begin);
        flag[begin] = true;
        int father;
        while (vexqueue.empty() == false) {
            father = vexQueue.front();
            vexQueue.pop();
            for (int i = 0; i < vexnum; ++i) {
                if (temp[father][i] != MAX && flag[i] == false) {
                    vexQueue.push(i);
                    flag[i] = true;
                    //看看当前点和其他已访问点是否有边
                    for (int j = 0; j < vexnum; ++j) {
                        if (temp[i][j] != MAX && j != father && flag[j] == true) {
                            return true;//如果有边，说明有回路
                        }
                    }

                }

            }
        }
        return false;    
    }
