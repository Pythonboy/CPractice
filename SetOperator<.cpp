struct A
{
  int x;
  int y;
  int z;
/*
  bool operator < (const A & other)const
  {
    return (x == other.x) ? y > other.y : x > other.x;
  }
*/
};              // end of struct A
  bool operator < (const A& i1, const A& i2)
  {
    return (i1.x == i2.x) ? i1.y > i2.y : i1.x > i2.x;
  }
 
bool myfunction(int i, int j){return i > j;}
int main()
{
    A a1;
    a1.x = 0;
    a1.y = 1;
    a1.z = 2;
    A a2;
    a2.x = 0;
    a2.y = 1;
    a2.z = 2;
    set<A> sa;
    sa.insert(a1);
    sa.insert(a2);
 
    return 0;
}
