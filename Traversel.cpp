1.前序遍历
（1）递归版本
public void preOrderTraverse1(TreeNode root) {  
        if (root != null) {  
            System.out.print(root.val+"  ");  
            preOrderTraverse1(root.left);  
            preOrderTraverse1(root.right);  
        }  
    }  
    
（2）非递归版本
public void preOrderTraverse2(TreeNode root) {  
        LinkedList<TreeNode> stack = new LinkedList<>();  
        TreeNode pNode = root;  
        while (pNode != null || !stack.isEmpty()) {  
            if (pNode != null) {  
                System.out.print(pNode.val+"  ");  
                stack.push(pNode);  
                pNode = pNode.left;  
            } else { //pNode == null && !stack.isEmpty()  
                TreeNode node = stack.pop();  
                pNode = node.right;  
            }  
        }  
    }  


2.中序遍历
（1）递归版本
public void inOrderTraverse1(TreeNode root) {  
        if (root != null) {  
            inOrderTraverse1(root.left);  
            System.out.print(root.val+"  ");  
            inOrderTraverse1(root.right);  
        }  
    }  
    
（2）非递归版本
public void inOrderTraverse2(TreeNode root) {  
        LinkedList<TreeNode> stack = new LinkedList<>();  
        TreeNode pNode = root;  
        while (pNode != null || !stack.isEmpty()) {  
            if (pNode != null) {  
                stack.push(pNode);  
                pNode = pNode.left;  
            } else { //pNode == null && !stack.isEmpty()  
                TreeNode node = stack.pop();  
                System.out.print(node.val+"  ");  
                pNode = node.right;  
            }  
        }  
    } 


3.后序遍历
（1）递归版本
public void postOrderTraverse1(TreeNode root) {  
        if (root != null) {  
            postOrderTraverse1(root.left);  
            postOrderTraverse1(root.right);  
            System.out.print(root.val+"  ");  
        }  
    }
  
（2）非递归版本
思路一：
void postOrder2(BinTree *root)    //非递归后序遍历
{
    stack<BTNode*> s;
    BinTree *p=root;
    BTNode *temp;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)              //沿左子树一直往下搜索。直至出现没有左子树的结点 
        {
            BTNode *btn=(BTNode *)malloc(sizeof(BTNode));
            btn->btnode=p;
            btn->isFirst=true;
            s.push(btn);
            p=p->lchild;
        }
        if(!s.empty())
        {
            temp=s.top();
            s.pop();
            if(temp->isFirst==true)     //表示是第一次出如今栈顶 
             {
                temp->isFirst=false;
                s.push(temp);
                p=temp->btnode->rchild;    
            }
            else                        //第二次出如今栈顶 
             {
                cout<<temp->btnode->data<<" ";
                p=NULL;
            }
        }
    }    
} 

思路二：
void postOrder3(BinTree *root)     //非递归后序遍历
{
    stack<BinTree*> s;
    BinTree *cur;                      //当前结点 
    BinTree *pre=NULL;                 //前一次訪问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<" ";  //假设当前结点没有孩子结点或者孩子节点都已被訪问过 
              s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }    
}

4.层次遍历
public void levelTraverse(TreeNode root) {  
        if (root == null) {  
            return;  
        }  
        LinkedList<TreeNode> queue = new LinkedList<>();  
        queue.offer(root);  
        while (!queue.isEmpty()) {  
            TreeNode node = queue.poll();  
            System.out.print(node.val+"  ");  
            if (node.left != null) {  
                queue.offer(node.left);  
            }  
            if (node.right != null) {  
                queue.offer(node.right);  
            }  
        }  
    }  
    
5.深度优先遍历
public void depthOrderTraverse(TreeNode root) {  
        if (root == null) {  
            return;  
        }  
        LinkedList<TreeNode> stack = new LinkedList<>();  
        stack.push(root);  
        while (!stack.isEmpty()) {  
            TreeNode node = stack.pop();  
            System.out.print(node.val+"  ");  
            if (node.right != null) {  
                stack.push(node.right);  
            }  
            if (node.left != null) {  
                stack.push(node.left);  
            }  
        }  
    }  



































