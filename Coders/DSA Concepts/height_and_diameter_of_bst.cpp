#include<iostream>
using namespace std;
struct node{
    int data;
    //int data;
    struct node*left;
    struct node*right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;

    }
};
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    return max(lheight, rheight)+1;
}
int dm(node* root){
    if(root==NULL){
        return 0;
    }
    int lheight =dm(root->left);
    int rheight=dm(root->right);
    int currd=lheight+rheight+1;
    int ld= dm(root->left);
    int rd=dm(root->right);
    return max(currd, max(ld,rd));

}
int main(){
    struct node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    cout<<height(root)<<endl;
    cout<<dm(root)<<endl;
    return 0;
   
}