1、先序遍历
先序遍历按照根结点->左孩子->右孩子的顺序进行访问。
1.递归遍历
void preOrder1(BiTree *root)
{
    if(root != NULL)
    {
        cout<<root->key<<" ";
        preOrder1(root->left);
        preOrder1(root->right);
    }
}
2.非递归遍历
根据前序遍历访问的顺序，优先访问根结点，然后再分别访问左孩子和右孩子。即对于任一结点，其可看做是根结点，因此可以直接访问，访问完之后，若其左孩子不为空，按相同规则访问它的左子树；当访问完其左子树时，再访问它的右子树。因此其处理过程如下：

对于任一结点P：
1)访问结点P，并将结点P入栈;
2)判断结点P的左孩子是否为空，若为空，则取栈顶结点并进行出栈操作，并将栈
顶结点的右孩子置为当前的结点P，循环至1);若不为空，则将P的左孩子置为当
前的结点P;
3)直到P为NULL并且栈为空，则遍历结束。
代码：
void preOrder2(BiTree *root)
{
    stack<BiTree*> s;
    BiTree *p=root;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            cout<<p->key<<" ";//(1)先访问根节点
            s.push(p);
            p=p->left;//(2)左孩子作为根节点，直至为空
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->right;//(3)右孩子作为根节点
        }
    }
}




2、中序遍历
中序遍历按照左孩子-根结点-右孩子的顺序进行访问。
1.递归遍历
void inOrder1(BiTree *root)
{
    if(root != NULL)
    {
        inOrder1(root->left);
        cout<<root->key<<" ";
        inOrder1(root->right);
    }
}
2.非递归遍历
对于任一结点P，
1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前结点P
再进行相同的处理；
2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当
前的P置为栈顶结点的右孩子；
3)直到P为NULL并且栈为空则遍历结束
代码：

void inOrder2(BiTree *root)
{
    stack<BiTree*> s;
    BiTree *p=root;
    while(p != NULL || !s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p=p->left;//(1)左
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->key<<" ";//(2)中。跟preOrder2的区别是该处换了地方
            s.pop();
            p=p->right;//(3)右
        }
    }
}



3、后序遍历
后序遍历按照左孩子-右孩子-根结点的顺序进行访问。
1.递归遍历
void postOrder1(BiTree *root)
{
    if(root != NULL)
    {
        postOrder1(root->left);
        postOrder1(root->right);
        cout<<root->key<<" ";
    }
}
2.非递归遍历
要保证根结点在左孩子和右孩子访问之后才能访问，因此：
1）对于任一结点P，先将其入栈。
2）如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩
子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
3）若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取
栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被
访问。
代码：

void postOrder2(BiTree *root)
{
    stack<BiTree*> s;
    BiTree *p=root;//当前结点 
    BiTree *pre=NULL;//前一次访问的结点 !!!
    s.push(p);
    while(!s.empty())
    {
        p=s.top();
        if((p->left==NULL && p->right==NULL) ||
           pre != NULL &&(pre==p->left || pre==p->right))
        {//如果当前结点没有孩子结点或者孩子节点都已被访问过 
            cout<<p->key<<" ";
            s.pop();
            pre=p;
        }
        else
        {//否则，右孩子，左孩子，依次入栈
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
        }
    }
}



4、层次遍历
分层遍历该二叉树，即从上到下按层次访问该二叉树(每一层可单独输出一行)，每一层要求访问的顺序为从左到右。
利用图的广度优先搜索，外加一个queue实现。

1.方法一
遍历时直接一行输出，不分行打印

void layerOrder1(BiTree *root)
{
    if(root==NULL) return;

    queue<BiTree*> q;
    BiTree *p=root;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        cout<<p->key<<" ";
        q.pop();
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
    }
}


2.方法二
遍历时按二叉树的层次分行输出 
我们可以在遍历当前层的时候，保存下一层的节点数，只需要每次插入一个节点的时候childNum++即可，这样我们就知道下一层有几个节点了，
然后将childNum赋值给parentNum，开始新的一层遍历，从队列中取出parentNum个节点以后，也就知道这一层遍历完了。
由于这是二叉树，所以一开始的时候parentNum = 1, childNum = 0。

void layerOrder2(BiTree *root)
{
    if(root==NULL) return;
    int parentNum=1, childNum=0;//在根节点时parent只有一个,child为0
    queue<BiTree*> q;
    BiTree *p=root;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        cout<<p->key<<" ";
        q.pop();
        if(p->left)
        {
            q.push(p->left);
            childNum++;
        }
        if(p->right)
        {
            q.push(p->right);
            childNum++;
        }
        parentNum--;
        if(parentNum==0)
        {
            parentNum=childNum;//更新下一层parent数
            childNum=0;//更新下一层child数
            cout<<endl;//换行
        }
    }
}


6、二叉树的其他一些应用
1.求二叉树的深度
若一棵二叉树为空，则它的深度为0，否则它的深度等于左子树和右子树中的最大深度加1. 设nLeft为左子树的深度，nRight为右子树的深度，

则二叉树的深度为：max(nLeft , nRight)+1.

//树的深度
int TreeDepth(BTree* root) 
{ 
     int nLeft, nRight; 
     if(root == NULL)//必不可少的条件,递归的出口 
         return 0;   
     nLeft = TreeDepth(root->lchild); 
     nRight = TreeDepth(root->rchild); 
     return (nLeft > nRight) ? (nLeft + 1):(nRight + 1); 
} 


2.从二叉树中查找值为x的结点
若存在，则由x带回完整值并返回真，否则返回假。
该算法类似于前序遍历，若树为空则返回false结束递归，若树根结点的值就等于x的值，则把结点值赋给x后返回true结束递归，否则先向左子树查找，若找到则返回true结束递归，否则再向右子树查找，若找到则返回true结束递归，若左，右子树均未找到则返回false结束递归。

bool FindBTree(BTreeNode *BT , ElemType &x)
{
    if(BT == NULL)     //树为空返回假
        return false;
    if(BT->data == x)  //树根结点的值等于x则由x带回结点值并返回真
    {
        x = BT->data;
        return true;
    }
    else
    {
        //向左子树查找，若成功则继续返回真
        if(FindBTree(BT->left , x))
            return true;
        //向右子树查找，若成功则继续返回真
        if(FindBTree(BT->right , x))
            return true;
        //左，右子树查找均失败则返回假
        return false;
    }
}


3.统计出二叉树中等于给定值x的结点个数，结果由函数返回。
此算法也是一个递归过程，若树为空则返回0结束递归，若树根结点的值等于x的值则返回左、右两棵子树中等于x结点的个数加1，否则只应返回左、右两棵子树中等于x结点的个数。

int CountX(BTreeNode *BT , ElemType &x)
{
    if(BT == NULL)   //空树返回0
        return 0;
    if(BT->data == x)
        return CountX(BT->left , x)+CountX(BT->right , x) + 1;   
        //返回1加上两子树中的x结点数
    else
        return CountX(BT->left , x)+CountX(BT->right , x); 
        //返回两子树中的x结点数
}


4.返回x结点所处的层号，若不存在值为x的结点则返回0
int NodeLevel(BTreeNode *BT , ElemType &x)
{
    //空树的层号为0
    if(BT == NULL)
        return 0;
    //根结点的层号为1
    if(BT->data == x)
        return 1;
    else
    {
        //求出x在左子树中的层号，返回该层号加1
        int c1 = NodeLevel(BT->left , x);
        if(c1 >= 1)
            return c1+1;
        //求出x在右子树中的层号，返回该层号加1
        int c2 = NodeLevel(BT->right , x);
        if(c2 >= 1)
            return c2+1;
        //在左、右子树中都不存在x结点则返回0
        else
            return 0;
    }
}


5.从二叉树中找出所有结点的最大值并返回，若为空树则返回0
ElemType MaxValue(BTreeNode *BT)
{
    if(BT == NULL)
        return 0;  //空树返回0

    ElemType k1 , k2;
    k1 = MaxValue(BT->left);  //求出左子树中的最大值
    k2 = MaxValue(BT->right);  //求出右子树中的最大值
    if(k1 < k2)
        k1 = k2;   //两子树的最大值赋给k1
    if(k1 > BT->data)
        return k1;
    else
        return BT->data;
}


6.求二叉树中所有结点数
int BTreeCount(BTreeNode *BT)
{
    if(BT == NULL)
        return 0;
    else
        return BTreeCount(BT->left) + BTreeCount(BT->right) + 1;
}


7.求二叉树中所有叶子结点数
int BTreeLeafCount(BTreeNode *BT)
{
    if(BT == NULL)
        return 0;

    if(BT->left == NULL && BT->right == NULL)
        return 1;
    else
        return BTreeLeafCount(BT->left) + BTreeLeafCount(BT->right);
}
