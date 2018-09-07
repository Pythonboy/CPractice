//C++中<string.h>中的常用函数

void *memcpy(void *p1, const void *p2 size_t n)
功能： 存储器拷贝，将p2所指向的共n个字节拷贝到p1所指向的存储区中  （可以实现将一个数组的值copy给另一个数组）
返回值：目的存储区的起始地址 （实现任意数据类型之间的拷贝）
例子：
char *s="Golden Global View";
char d[20];
memcpy(d,s,strlen(s));


void *memset(void *p int v, size_t n)
功能： 将v的值作为p所指向的区域的 值，n是p所指向区域的大小
返回值：该区域的起始地址


char *strcpy(char *p1, const char *p2)
功能：将p2所指向的字符串拷贝到p1所指向的存储区中 （貌似只能狗实现字符串的copy）
返回值：目的存储区的起始地址


char *strcat(char *p1, const char *p2)
功能：将p2所指向的字符串连接到p1所指向的字符串后面
返回值：目的存储区的起始地址


int strcmp(const char *p1, const char *p2)
功能：比较p1,p2所指向的两个 字符串的大小
返回值：两个字符串相同，返回0；若p1所指向的字符串小于p2所指的字符串，返回负值；否则，返回正值


int strlen(const char *p)
功能：求p所指向的字符串的长度
返回值：字符串所包含的字符个数 （不包括字符串结束标志’\n’）


char *strncpy(char *p1, const char *p2, size_t n)
功能：将p2所指向的字符串（至多n个字符）拷贝到p1所指向的存储区中
返回值：目的存储区的起始地址 (与strcpy()类似)


char *strncat(char *p1, const char *p2, size_t n)
功能：将p2所指向的字符串（至多n个字符）连接到p1所指向的字符串的后面
返回值：目的存储区的起始地址 (与strcpy()类似)


char *strncmp(const char *p1, const char *p2, size_t n)
功能：比较p1,p2所指向的两个字符串的大小，至多比较n个字符
返回值：两个字符串相同，返回0；若p1所指向的字符串小于p2所指的字符串，返回负值；否则，返回正值(与strcpy()类似)


char *strstr(const char *p1, const char *p2)
功能：判断p2所指向的字符串是否是p1所指向的字符串的子串
返回值：若是子串，返回开始位置的地址；否则返回0。




