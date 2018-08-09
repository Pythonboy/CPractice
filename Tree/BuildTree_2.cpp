TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty()||postorder.empty()) return NULL;
    return constructTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
}
TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int inStart,int inEnd,int postStart,int postEnd)
{
    if(postStart>postEnd||inStart>inEnd) return NULL;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    if(postStart==postEnd||inStart==inEnd) return root;
    int i ;
    for(i = inStart ;i<inEnd;i++)//在中序遍历中找到根节点
    {
        if(inorder[i]==postorder[postEnd]) break;
    }
    root->left = constructTree(inorder,postorder,inStart,i-1,postStart,postStart+i-inStart-1);//递归构造左子树
    root->right = constructTree(inorder,postorder,i+1,inEnd,postStart+i-inStart,postEnd-1);//递归构造右子树
    return root;
}
