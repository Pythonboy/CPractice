//倒序层次遍历
    public ArrayList<ArrayList<Integer>> levelOrderBottom(TreeNode root) {
        // write your code here
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(root!=null)
            q.offer(root);
        while(!q.isEmpty()){
            ArrayList<TreeNode> list = new ArrayList<TreeNode>();
            ArrayList<Integer> result = new ArrayList<Integer>();
            
            while(!q.isEmpty()){
                list.add(q.poll());    
            }
            for(int i=0;i<list.size();i++){    
                result.add(list.get(i).val);
                if(list.get(i).left!=null){
                    q.offer(list.get(i).left);
                }
                if(list.get(i).right!=null){
                    q.offer(list.get(i).right);
                }
            }
            arr.add(0,result);
        }    
        return arr;
    }
