/*前序遍历（递归）*/
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ret;
    dfsPreOrder(root,ret);
    return ret;
}
void dfsPreOrder(TreeNode* root,vector<int> &ret){
    if(root==NULL) return;
    ret.push_back(root->val);//存储根节点
    if(root->left!=NULL) dfsPreOrder(root->left,ret);//访问左子树
    if(root->right!=NULL) dfsPreOrder(root->right,ret);//访问右子树
}


/*前序遍历（非递归）
非递归版本需要利用辅助栈来实现
1.首先把根节点压入栈中
2.此时栈顶元素即为当前根节点，弹出并访问即可
3.把当前根节点的右子树和左子树分别入栈，考虑到栈是先进后出，所以必须右子树先入栈，左子树后入栈
4.重复2,3步骤，直到栈为空为止
*/
vector<int> preorderTraversal(TreeNode* root){
    vector<int> ret;
    dfsPreOrder(root,ret);
    return ret;
}
void dfsPreOrder(TreeNode* root,vector<int> &ret){
    if(root==NULL) return;
    ret.push_back(root->val);//存储根节点
    if(root->left!=NULL) dfsPreOrder(root->left,ret);//访问左子树
    if(root->right!=NULL) dfsPreOrder(root->right,ret);//访问右子树
}


/*中序遍历（递归）*/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    inorder(root,ret);
    return ret;
}
void inorder(TreeNode* p,vector<int>& ret)
{
    if(p==NULL) return;
    inorder(p->left,ret);//访问左子树
    ret.push_back(p->val);//访问根节点
    inorder(p->right,ret);//访问右子树
}


/*中序遍历（非递归）
中序遍历的非递归版本比前序稍微复杂一点，除了用到辅助栈之外，还需要一个指针p指向下一个待访问的节点
如果p非空，则将p入栈，p指向p的左子树
如果p为空，说明此时左子树已经访问到尽头了，弹出当前栈顶元素，进行访问，并把p设置成p的右子树的左子树，即下一个待访问的节点
*/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode* p = root;
    stack<TreeNode*> st;
    while(!st.empty()||p!=NULL){
        if(p){//p非空，代表还有左子树，继续
            st.push(p);
            p=p->left;
        }
        else{//如果为空，代表左子树已经走到尽头了
            p = st.top();
            st.pop();
            ret.push_back(p->val);//访问栈顶元素
            if(p->right) {
                st.push(p->right);//如果存在右子树，将右子树入栈
                p = p->right->left;//p始终为下一个待访问的节点
            }
            else p=NULL;
        }
    }
    return ret;
}


/*后序遍历（递归）*/
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    inorder(root,ret);
    return ret;
 }
void inorder(TreeNode* p,vector<int>& ret)
{
    if(p==NULL) return;
    inorder(p->left,ret);//访问左子树
    inorder(p->right,ret);//访问右子树
    ret.push_back(p->val);//访问根节点
}

/*后序遍历（非递归）（一）
采用一个辅助栈和两个指针p和r，p代表下一个需要访问的节点，r代表上一次需要访问的节点
1、如果p非空，则将p入栈，p指向p的左子树
2、如果p为空，代表左子树到了尽头，此时判断栈顶元素
如果栈顶元素存在右子树且没有被访问过(等于r代表被访问过)，则右子树入栈，p指向右子树的左子树
如果栈顶元素不存在或者已经被访问过，则弹出栈顶元素，访问，然后p置为null，r记录上一次访问的节点p
*/
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode* p = root;
    stack<TreeNode*> st;
    TreeNode* r = NULL;
    while(p||!st.empty())
    {
        if(p)
        {
            st.push(p);
            p = p -> left;
        }
        else
        {
            p = st.top();
            if(p->right&&p->right!=r)
            {
                p = p->right;
                st.push(p);
                p = p->left;
            }
            else 
            {
                p = st.top();
                st.pop();
                ret.push_back(p->val);
                r= p;
                p = NULL;
            }
        }
    }
    return ret;
}

/*
后序遍历（非递归）（二）
将前序遍历的非递归算法中左子树和右子树的压栈顺序换一下即可
*/
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    if(root==NULL) return ret;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty())
    {
       TreeNode* tmp = st.top();
       ret.push_back(tmp->val);//先访问根节点
       st.pop();
       if(tmp->left!=NULL) st.push(tmp->left);//再访问左子树
       if(tmp->right!=NULL) st.push(tmp->right);//最后访问右子树
    }
    reverse(ret.begin(),ret.end());//将结果反序输出
    return ret;
}


/*
层序遍历（队列实现）
层序遍历，即按层序从左到右输出二叉树的每个节点。如例子中的A(第一层)BC(第二层)DE(第三层)FG(第四层)HI(第五层)
层序遍历需要借助队列queue来完成，因为要满足先进先去的访问顺序。
*/
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if(root==NULL) return ret;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        vector<int> temp;
        queue<TreeNode*> tmpQue;//存储下一层需要访问的节点
        while(!que.empty())//从左到右依次访问本层
        {
            TreeNode* tempNode = que.front();
            que.pop();
            temp.push_back(tempNode->val);
            if(tempNode->left!=NULL) tmpQue.push(tempNode->left);//左子树压入队列
            if(tempNode->right!=NULL) tmpQue.push(tempNode->right);//右子树压入队列
        }
        ret.push_back(temp);
        que=tmpQue;//访问下一层
    }
    return ret;
}
