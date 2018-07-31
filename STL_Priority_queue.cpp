1.优先队列的两种声明方式
std::priority_queue<T> pq;
std::priority_queue<T, std::vector<T>, cmp> pq;

2.重载小于号
int cost[MAX_V][MAX_V];
int d[MAX_V], V, s;
//自定义优先队列less比较函数
struct cmp
{
    bool operator()(int &a, int &b) const
    {
        //因为优先出列判定为!cmp，所以反向定义实现最小值优先
        return d[a] > d[b];
    }
};
void Dijkstra()
{
    std::priority_queue<int, std::vector<int>, cmp> pq;
    pq.push(s);
    d[s] = 0;
    while (!pq.empty())
    {
        int tmp = pq.top();pq.pop();
        for (int i = 0;i < V;++i)
        {
            if (d[i] > d[tmp] + cost[tmp][i])
            {
                d[i] = d[tmp] + cost[tmp][i];
                pq.push(i);
            }
        }
    }
}

3.基本操作
void push(value_type&& _Val)
        {    // insert element at beginning
        c.push_back(_STD move(_Val));
        push_heap(c.begin(), c.end(), comp);
        }

    template<class... _Valty>
        void emplace(_Valty&&... _Val)
        {    // insert element at beginning
        c.emplace_back(_STD forward<_Valty>(_Val)...);
        push_heap(c.begin(), c.end(), comp);
        }


    bool empty() const
        {    // test if queue is empty
        return (c.empty());
        }

    size_type size() const
        {    // return length of queue
        return (c.size());
        }

    const_reference top() const
        {    // return highest-priority element
        return (c.front());
        }

    void push(const value_type& _Val)
        {    // insert value in priority order
        c.push_back(_Val);
        push_heap(c.begin(), c.end(), comp);
        }

    void pop()
        {    // erase highest-priority element
        pop_heap(c.begin(), c.end(), comp);
        c.pop_back();
        }
