本文介绍如何使用STL里的heap（堆）算法。第一次接触heap这种数据结构是在大学的数据结构教材上，它是一棵完全二叉树。在STL中，heap是算法的形式提供给我们使用的。包括下面几个函数：

make_heap: 根据指定的迭代器区间以及一个可选的比较函数，来创建一个heap. O(N)

push_heap: 把指定区间的最后一个元素插入到heap中. O(logN)

pop_heap: 弹出heap顶元素, 将其放置于区间末尾. O(logN)

sort_heap：堆排序算法，通常通过反复调用pop_heap来实现. N*O(logN)

C++11加入了两个新成员：

is_heap: 判断给定区间是否是一个heap. O(N)

is_heap_until: 找出区间中第一个不满足heap条件的位置. O(N)

因为heap以算法的形式提供，所以要使用这几个api需要包含 #include <algorithm>

heap相关算法的使用
make_heap
STL中的通过make_heap创建的堆，默认是大顶堆(max heap)，即每个非叶子节点元素的值均不”小于”(默认使用<作为比较准则)其左右孩子节点。要改变堆的建立准则，可以自己制定一个比较函数，如下第二个版本的make_heap声明:

// 1
template< class RandomIt >
void make_heap( RandomIt first, RandomIt last );

// 2
template< class RandomIt, class Compare >
void make_heap( RandomIt first, RandomIt last, Compare comp );
示例代码：

默认的make_heap
vector<int> vi{6, 1, 2, 5, 3, 4};
printContainer(vi, "vi: ");             // vi: 6 1 2 5 3 4

make_heap(vi.begin(), vi.end());
printContainer(vi, "vi: ");             // vi: 6 5 4 1 3 2
需要注意的是，make_heap需使用随机迭代器来创建heap。

自己指定比较函数的make_heap
vector<int> v2{6, 1, 2, 5, 3, 4};
printContainer(v2, "v2 before make_heap: ");
make_heap(v2.begin(), v2.end(), greater<int>());
printContainer(v2, "v2 after make_heap: ");
输出：

v2 before make_heap: 6 1 2 5 3 4
v2 after make_heap: 1 3 2 5 6 4
这里使用了greater<int>()来代替默认的less<int>()来创建int类型的heap。可以按层次遍历的顺序把这个heap画出来，可以看到它跟默认情况刚好相反，会是一个小顶堆。

push_heap
// 1
template< class RandomIt >
void push_heap( RandomIt first, RandomIt last );

// 2
template< class RandomIt, class Compare >
void push_heap( RandomIt first, RandomIt last, Compare comp );
与make_heap类似，push_heap也有两个版本，其中有一个版本可以指定堆的比较函数，并且也是以一对迭代器指定的区间来进行操作。

示例代码：

vector<int> v1{6, 1, 2, 5, 3, 4};
make_heap(v1.begin(), v1.end());

v1.push_back(200);
printContainer(v1, "before push_heap: ");        // before push_heap: 6 5 4 1 3 2 200
push_heap(v1.begin(), v1.end());
printContainer(v1, "after push_heap: ");         // after push_heap: 200 5 6 1 3 2 4
先用make_heap来构造一个堆，然后在容器末尾追加元素之后，把新的迭代器区间传给push_heap，这样新尾部元素也被添加到堆中。

注意：使用push_heap(f, l)的话，调用者需要确保[f, l-1)已经是一个堆. push_heap(f, l)仅仅会把*(l-1)插入到[f, l-1)这个区间形成的堆中，时间复杂度是O(logN).

即, STL书中所述：the caller has to ensure, on entry, the elements in the range [begin, end) are a heap(according to the same sorting criterion).

如果一开始不用make_heap处理，直接push_heap会怎样？

vector<int> v2{6, 1, 2, 5, 3, 4};
v2.push_back(200);
printContainer(v2, "v2 before push_heap: ");
push_heap(v2.begin(), v2.end());
printContainer(v2, "v2 after push_heap: ");
输出：

v2 before push_heap: 6 1 2 5 3 4 200
v2 after push_heap: 200 1 6 5 3 4 2
可以看出直接调用push_heap的结果并不是一个heap. 下面要提到的pop_heap也有同样的要求。

pop_heap
// 1	
template< class RandomIt >
void pop_heap( RandomIt first, RandomIt last );

// 2
template< class RandomIt, class Compare >
void pop_heap( RandomIt first, RandomIt last, Compare comp );

Swaps the value in the position first and the value in the position last-1 and makes the subrange [first, last-1) into a max heap. This has the effect of removing the first (largest) element from the heap defined by the range [first, last).
它的作用是：交换*first和*(last-1)， 然后把[first, last-1)建成一个max heap. 也就是说把堆顶的最大元素交换到区间尾，然后把除了尾部的元素的剩余区间重新调整成堆。

需要注意的是，调用者要保证，在调用pop_heap时[first, last)已经是一个堆(使用相同的排序准则)。

vector<int> v1{6, 1, 2, 5, 3, 4};
make_heap(v1.begin(), v1.end());
printContainer(v1, "after make_heap: ");

pop_heap(v1.begin(), v1.end());
printContainer(v1, "after pop_heap: ");
auto largest = v1.back();
psln(largest);
v1.pop_back();
printContainer(v1, "delete largest: ");
输出：

after make_heap: 6 5 4 1 3 2
after pop_heap: 5 3 4 1 2 6
largest = 6
delete largest: 5 3 4 1 2
sort_heap
// 1
template< class RandomIt >
void sort_heap( RandomIt first, RandomIt last );

// 2
template< class RandomIt, class Compare >
void sort_heap( RandomIt first, RandomIt last, Compare comp );
sort_heap即经典的堆排序算法，通过每次弹出堆顶直到堆为空，依次被弹出的元素就组成了有序的序列了。STL中的priority_queue即使用heap的这个特性来实现。

使用sort_heap(f, l)处理过的区间因为已经有序，就不再是一个heap了。

vector<int> v1{6, 1, 2, 5, 3, 4};
printContainer(v1, "before sort_heap: ");       

make_heap(v1.begin(), v1.end());

sort_heap(v1.begin(), v1.end());
printContainer(v1, "after sort_heap: ");
输出：

before sort_heap: 6 1 2 5 3 4
after sort_heap: 1 2 3 4 5 6
注意：调用者仍需确保区间已经是一个堆。

is_heap
// (1)	(since C++11)
template< class RandomIt >
bool is_heap( RandomIt first, RandomIt last );

// (2)	(since C++11)
template< class RandomIt, class Compare >
bool is_heap( RandomIt first, RandomIt last, Compare comp );
示例：

vector<int> v1{6, 1, 2, 5, 3, 4};
psln(is_heap(v1.begin(), v1.end()));

pln("after make_heap");

make_heap(v1.begin(), v1.end());
psln(is_heap(v1.begin(), v1.end()));
输出：

is_heap(v1.begin(), v1.end()) = 0
after make_heap
is_heap(v1.begin(), v1.end()) = 1
is_heap_until
原型:

// (1)	(since C++11)
template< class RandomIt >
RandomIt is_heap_until( RandomIt first, RandomIt last );

// (2)	(since C++11)
template< class RandomIt, class Compare >
RandomIt is_heap_until( RandomIt first, RandomIt last, Compare comp );
示例：

vector<int> v1{6, 1, 2, 5, 3, 4};
auto iter = is_heap_until(v1.begin(), v1.end());
psln(*iter);        // *iter = 5    5 是第一个不满足heap条件的位置。

make_heap(v1.begin(), v1.end());
iter = is_heap_until(v1.begin(), v1.end());
ASSERT_TRUE(iter == v1.end());
总结
建堆，make_heap

堆操作：增加元素(push_heap)，删除元素(pop_heap), 排序(sort_heap), 均要求区间已经是一个heap，并且是与当前操作使用相同的排序准则

is_heap, is_heap_until当做辅助判断函数来用

所有的heap算法操作的区间都需要是随机迭代器组成
