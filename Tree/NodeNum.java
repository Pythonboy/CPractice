public int CountNode(TreeNode root)    
    {    
        if(root == null)    
            return 0;    
        return 1+CountNode(root.left)+CountNode(root.right);    
    }
