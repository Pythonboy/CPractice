//重点：
（一）
typedef struct tagStudentInfo  
{  
      int      nID;  
      string   strName;  
      bool operator < (tagStudentInfo const& _A) const  
      {  
             //这个函数指定排序策略，按nID排序，如果nID相等的话，按strName排序  
             if(nID < _A.nID)  return true;  
             if(nID == _A.nID) return strName.compare(_A.strName) < 0;  
             return false;  
      }  
}StudentInfo, *PStudentInfo;  //学生信息  


（二）
class sort  
{  
  public:  
  bool operator() (StudentInfo const &_A, StudentInfo const &_B) const  
  {  
     if(_A.nID < _B.nID) return true;  
     if(_A.nID == _B.nID) return _A.strName.compare(_B.strName) < 0;  
     return false;  
  }  
};  


STL中默认是采用小于号来排序的，以上代码在排序上是不存在任何问题的，因为上面的关键字是int型，它本身支持小于号运算，在一些特殊情况，
比如关键字是一个结构体，涉及到排序就会出现问题，因为它没有小于号操作，insert等函数在编译的时候过不去，下面给出两个方法解决这个问题

第一种：小于号重载，程序举例
#include <map>  
#include <string>  
#include <iostream>  
using namespace std;  
typedef struct tagStudentInfo  
{  
      int      nID;  
      string   strName;  
}StudentInfo, *PStudentInfo;  //学生信息  
int main()  
{  
  //用学生信息映射分数  
  map<StudentInfo, int> mapStudent;  
  map<StudentInfo, int>::iterator  iter;  
  StudentInfo studentInfo;  
  studentInfo.nID = 1;  
  studentInfo.strName = "student_one";  
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));  
  studentInfo.nID = 2;  
  studentInfo.strName = "student_two”";  
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));  
  studentInfo.nID = 3;  
  studentInfo.strName = "student_three";  
  mapStudent.insert(pair<StudentInfo, int>(studentInfo, 70));  
     for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)  
     {  
          cout<<iter->first.nID<<endl<<iter->first.strName<<endl<<iter->second<<endl;  
     }  
     return 0;  
}  
以上程序是无法编译通过的，只要重载小于号，就OK了，如下：  
typedef struct tagStudentInfo  
{  
      int      nID;  
      string   strName;  
      bool operator < (tagStudentInfo const& _A) const  
      {  
             //这个函数指定排序策略，按nID排序，如果nID相等的话，按strName排序  
             if(nID < _A.nID)  return true;  
             if(nID == _A.nID) return strName.compare(_A.strName) < 0;  
             return false;  
      }  
}StudentInfo, *PStudentInfo;  //学生信息  


第二种：仿函数的应用，这个时候结构体中没有直接的小于号重载，程序说明
#include <map>  
#include <string>  
#include <iostream>  
using namespace std;  
typedef struct tagStudentInfo  
{  
      int      nID;  
      string   strName;  
}StudentInfo, *PStudentInfo;  //学生信息  
class sort  
{  
  public:  
  bool operator() (StudentInfo const &_A, StudentInfo const &_B) const  
  {  
     if(_A.nID < _B.nID) return true;  
     if(_A.nID == _B.nID) return _A.strName.compare(_B.strName) < 0;  
     return false;  
  }  
};  
int main()  
{  
      //用学生信息映射分数  
      map<StudentInfo, int, sort> mapStudent;  
      map<StudentInfo, int>::iterator  iter;  
      StudentInfo studentInfo;  
      studentInfo.nID = 1;  
      studentInfo.strName = "student_one";  
      mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));  
      studentInfo.nID = 2;  
      studentInfo.strName = "student_two”";  
        mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));  
        studentInfo.nID = 3;  
      studentInfo.strName = "student_three";  
        mapStudent.insert(pair<StudentInfo, int>(studentInfo, 70));  
       for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)  
       {  
               cout<<iter->first.nID<<endl<<iter->first.strName<<endl<<iter->second<<endl;  
       }  
          return 0;  
}  












