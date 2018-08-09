int maxDepth(TreeNode* root) {
    return DfsTree(root);
}
int DfsTree(TreeNode* root){
    if(root==NULL) return 0;
    int left = DfsTree(root->left);//左子树的深度
    int right = DfsTree(root->right);//右子树的深度
    return left>right?left+1:right+1;//比较左右子树的深度，取最大值
}
