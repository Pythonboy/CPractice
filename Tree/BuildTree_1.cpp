/*
根据前序和中序遍历来构造二叉树
前序遍历的顺序是：根节点->左子树->右子树，中序遍历的顺序时：左子树->根节点->右子树。

在前序遍历中第一个节点为根节点，然后去中序遍历中找到根节点，则其左边为左子树，右边为右子树

例如前序遍历ABC，中序遍历BAC,在前序遍历中找到根节点A，在中序遍历中A的左边B为左子树，右边C为右子树。

然后一次递归下去，就可以把整棵数构造出来了。
*/

typedef vector<int>::iterator vi;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()||inorder.empty()) return (TreeNode*)NULL;
    vi preStart = preorder.begin();
    vi preEnd = preorder.end()-1;
    vi inStart = inorder.begin();
    vi inEnd = inorder.end()-1;
    return constructTree(preStart,preEnd,inStart,inEnd);
}
TreeNode* constructTree(vi preStart,vi preEnd,vi inStart,vi inEnd)
{
    if(preStart>preEnd||inStart>inEnd) return NULL;
    //前序遍历的第一个节点为根节点
    TreeNode* root = new TreeNode(*preStart);
    if(preStart==preEnd||inStart==inEnd) return root;
    vi rootIn = inStart;
    while(rootIn!=inEnd){//在中序遍历中找到根节点
        if(*rootIn==*preStart) break;
        else ++rootIn;
    }
    root->left = constructTree(preStart+1,preStart+(rootIn-inStart),inStart,rootIn-1);//递归构造左子树
    root->right = constructTree(preStart+(rootIn-inStart)+1,preEnd,rootIn+1,inEnd);//递归构造右子树
    return root;
} 
