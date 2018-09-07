1.find()
给定一个vector容器：vector<int> nums={8,7,5,4,2,9,6,1,3,0};
find：find(nums.begin(),nums.end(),4)； 
find the number 4 ，return the iterator of the number。 
返回第一次出现4的位置的迭代器（可以理解为指针，但不同。） 
想要得到4所在位置的下标，可以写作 
find(nums.begin(),nums.end(),4)-nums.begin(); 
注：若未找到则返回nums.end()

2.swap()
swap：swap(nums[0],nums[2]); 
交换nums中下标为0和下标为2的元素


3.sort()
sort：sort(nums.begin(),nums.end(),[](int n1,int n2){return n1<n2;}); 
对nums进行从小到大排序 
排序规则参照第三个参数，使其nums中所有元素满足函数return true； 
即里面任意两个元素n1，n2且n1下标小于n2，满足n1
sort(nums.begin(),nums.end(),[](int n1,int n2){return n1>n2;});
1
注：前两个参数为需要排序的范围。排序法为快速排序。如需要稳定排序则可以使用stable_sort代替即可。


4.for_each()
for_each：for_each(nums.begin(),nums.end(),[](int n){cout<<n<<" ";}); 
此函数可以对参数1到参数2范围内的元素执行参数3函数内容。 
以上语句可以把nums内所有元素执行cout并输出一个空格。



