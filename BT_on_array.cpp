
#include<cstdio>
#include<vector>
using namespace std;
vector<int> v(1000,-1);
int n;
void preorder(int index){
    if(index>=n)
        return ;
    printf("%d ",v[index]);
    preorder(index*2+1);
    preorder(index*2+2);
}
void inorder(int index){
    if(index>=n)
        return ;
    inorder(index*2+1);
    printf("%d ",v[index]);
    inorder(index*2+2);
}
void postorder(int index){
    if(index>=n)
        return ;
    postorder(index*2+1);
    postorder(index*2+2);
    printf("%d ",v[index]);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    return 0;
