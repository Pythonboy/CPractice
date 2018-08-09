bool isBalanced(TreeNode* root) {
    return dfsTree(root)!=-1;
}
int dfsTree(TreeNode* root)
{
    if(root==NULL) return 0;
    int left = dfsTree(root->left);//求左子树的深度
    if(left == -1) return -1;//返回-1代表左子树不平衡
    int right = dfsTree(root->right);//求右子树的深度
    if(right== -1) return -1;//返回-1代表右子树不平衡
    if(abs(left-right)>1) return -1;//如果左右子树均平衡，则判断它们是否相差小于等于1
    return max(left,right)+1;//返回该根节点树的深度
}
