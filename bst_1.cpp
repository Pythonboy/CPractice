
<pre name="code" class="cpp">TreeNode* buildTree(vector<int> &nums,int start,int last)
{
	int mid = (start + last) / 2;
	TreeNode *root = new TreeNode(nums[mid]);
	if(start == last)
	{
		return root;
	}
	if(start <= mid - 1)
	{
		root->left = buildTree(nums,start,mid-1);
	}
	if(mid+1 <=  last)
	{
		root->right = buildTree(nums,mid+1,last);
	}
	return root;
}
 
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if(nums.empty())
		return NULL;
	return buildTree(nums,0,nums.size()-1);
}
