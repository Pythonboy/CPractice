//锯齿形层次遍历（先从左往右，下一层再从右往左，层与层之间交替进行）
    public ArrayList<ArrayList<Integer>> zigzagLevelOrder(TreeNode root) {
        // write your code here
         ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        boolean direction = true;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        if(root!=null)
            stack.push(root);
        while(!stack.isEmpty()){
            ArrayList<Integer> result = new ArrayList<Integer>();
            List<TreeNode> list = new ArrayList<TreeNode>();
            while(!stack.isEmpty()){
                list.add(stack.pop());
            }
            for(int i=0;i<list.size();i++){
                result.add(list.get(i).val);
                if(direction){
                    if(list.get(i).left!=null)
                        stack.push(list.get(i).left);
                    if(list.get(i).right!=null)
                        stack.push(list.get(i).right);
                }
                else{
                    if(list.get(i).right!=null)
                        stack.push(list.get(i).right);
                    if(list.get(i).left!=null)
                        stack.push(list.get(i).left);
                }
            }
            if(direction)
                direction = false;
            else
                direction = true;
            arr.add(result);
        }
        return arr;
    }
