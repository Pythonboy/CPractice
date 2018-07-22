一、map
1.1 map中数据的插入
//数据的插入--第一种：用insert函数插入pair数据  
    map<int, string> mapStudent;  
    mapStudent.insert(pair<int, string>(1, "student_one"));    
    mapStudent.insert(pair<int, string>(2, "student_two"));   
    mapStudent.insert(pair<int, string>(3, "student_three"));  
    map<int, string>::iterator iter;    
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)  
       cout<<iter->first<<' '<<iter->second<<endl; 

//第二种：用insert函数插入value_type数据，下面举例说明 
    map<int, string> mapStudent;  
    mapStudent.insert(map<int, string>::value_type (1, "student_one"));    
    mapStudent.insert(map<int, string>::value_type (2, "student_two"));    
    mapStudent.insert(map<int, string>::value_type (3, "student_three"));    
    map<int, string>::iterator iter;   
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)  
    cout<<iter->first<<' '<<iter->second<<endl; 
       
    pair<map<int, string>::iterator, bool> Insert_Pair;  
    //pair的第二个变量来知道是否插入成功，它的第一个变量返回的是一个map的迭代器，如果插入成功的话Insert_Pair.second应该是true的，否则为false
    Insert_Pair = mapStudent.insert(map<int, string>::value_type (1, "student_one"));

//第三种：用数组方式插入数据，下面举例说明
    map<int, string> mapStudent;    
    mapStudent[1] = "student_one";   
    mapStudent[2] = "student_two";  
    mapStudent[3] = "student_three";  
    map<int, string>::iterator iter;    
    for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)    
    cout<<iter->first<<' '<<iter->second<<endl;  

/*
注：
第一种和第二种在效果上是完成一样的，用insert函数插入数据，在数据的 插入上涉及到集合的唯一性这个概念，
即当map中有这个关键字时，insert操作是插入数据不了的，但是用数组方式就不同了，它可以覆盖以前该关键字对应的值
*/


1.2 map的大小
Int nSize = mapStudent.size();


1.3 map的遍历
（1）应用前向迭代器
for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
（2）应用反向迭代器
for(iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++) 
（3）用数组的形式
（注：以关键字直接取出）


1.4 查找并获取map中的元素（包括判定这个关键字是否在map中出现）
第一种：用count函数来判定关键字是否出现，其缺点是无法定位数据出现位置,由于map的特性，一对一的映射关系，就决定了count函数的返回值只有两个，
要么是0，要么是1，出现的情况，当然是返回1了

第二种：用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭
代器等于end函数返回的迭代器。
    iter = mapStudent.find(1);    
    if(iter != mapStudent.end())  
       cout<<"Find, the value is "<<iter->second<<endl;   
    else    
       cout<<"Do not Find"<<endl;  

第三种：Equal_range函数返回一个pair，pair里面第一个变量是Lower_bound返回的迭代器，pair里面第二个迭代器是Upper_bound返回的迭代器，如果这两个
迭代器相等的话，则说明map中不出现这个关键字，
注：
lower_bound函数用法，这个函数用来返回要查找关键字的下界(是一个迭代器)
upper_bound函数用法，这个函数用来返回要查找关键字的上界(是一个迭代器)

    pair<map<int, string>::iterator, map<int, string>::iterator> mappair;    
    mappair = mapStudent.equal_range(2);    
    if(mappair.first == mappair.second)    
        cout<<"Do not Find"<<endl;   
    else    
        cout<<"Find"<<endl;  


1.5 从map中删除元素

iterator erase（iterator it);//通过一个条目对象删除

iterator erase（iterator first，iterator last）//删除一个范围

size_type erase(const Key&key);//通过关键字删除

clear()就相当于enumMap.erase(enumMap.begin(),enumMap.end());


     map<int, string>::iterator iter;  
     iter = mapStudent.find(1);    
     mapStudent.erase(iter);    
     //如果要删除1，用关键字删除  
     int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0   
     //用迭代器，成片的删除    
     //一下代码把整个map清空  
     mapStudent.erase( mapStudent.begin(), mapStudent.end() );  
     //成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合  


1.6 map中swap的用法

swap( m1, m3 );
m1.swap( m2 );
//注：map中的swap不是一个容器中的元素交换，而是两个容器所有元素的交换。


1.7 map中key的排序
（一）小于号重载
#include <iostream>  
#include <string>  
#include <map>  
using namespace std;    
typedef struct tagStudentinfo    
{    
       int      niD;    
       string   strName;   
       bool operator < (tagStudentinfo const& _A) const    
       {     //这个函数指定排序策略，按niD排序，如果niD相等的话，按strName排序   
            if(niD < _A.niD) return true;  
            if(niD == _A.niD)  
                return strName.compare(_A.strName) < 0;   
        return false;  
       }    
}Studentinfo, *PStudentinfo; //学生信息    
int main()    
{    
    int nSize;   //用学生信息映射分数    
    map<Studentinfo, int>mapStudent;    
    map<Studentinfo, int>::iterator iter;    
    Studentinfo studentinfo;   
    studentinfo.niD = 1;    
    studentinfo.strName = "student_one";    
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));    
    studentinfo.niD = 2;    
    studentinfo.strName = "student_two";    
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));   
    for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)   
        cout<<iter->first.niD<<' '<<iter->first.strName<<' '<<iter->second<<endl;    
    return 0;  
}  

（二）仿函数的应用，这个时候结构体中没有直接的小于号重载，程序说明  
  
#include <iostream>    
#include <map>    
#include <string>   
using namespace std;    
typedef struct tagStudentinfo    
{    
       int      niD;   
       string   strName;   
}Studentinfo, *PStudentinfo; //学生信息   
class sort   
{   
public:    
    bool operator() (Studentinfo const &_A, Studentinfo const &_B) const    
    {   
        if(_A.niD < _B.niD)    
            return true;   
        if(_A.niD == _B.niD)   
            return _A.strName.compare(_B.strName) < 0;   
    return false;    
    }  
};    
int main()    
{   //用学生信息映射分数   
    map<Studentinfo, int, sort>mapStudent;   
    map<Studentinfo, int>::iterator iter;   
    Studentinfo studentinfo;  
    studentinfo.niD = 1;   
    studentinfo.strName = "student_one";   
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));   
    studentinfo.niD = 2;    
    studentinfo.strName = "student_two";   
    mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));    
    for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)    
        cout<<iter->first.niD<<' '<<iter->first.strName<<' '<<iter->second<<endl;  
}  


1.8 map的基本操作函数

     begin()         返回指向map头部的迭代器

     clear(）        删除所有元素

     count()         返回指定元素出现的次数

     empty()         如果map为空则返回true

     end()           返回指向map末尾的迭代器

     equal_range()   返回特殊条目的迭代器对

     erase()         删除一个元素

     find()          查找一个元素

     get_allocator() 返回map的配置器

     insert()        插入元素

     key_comp()      返回比较元素key的函数

     lower_bound()   返回键值>=给定元素的第一个位置

     max_size()      返回可以容纳的最大元素个数

     rbegin()        返回一个指向map尾部的逆向迭代器

     rend()          返回一个指向map头部的逆向迭代器

     size()          返回map中元素的个数

     swap()           交换两个map

     upper_bound()    返回键值>给定元素的第一个位置

     value_comp()     返回比较元素value的函数






















































