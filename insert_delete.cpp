#include<iostream>

using namespace std;

class node{
  
  public:
   int data;
   node* left;
   node* right;

   node(int ele){
    this->data=ele;
    this->left=right=NULL;

   }
};

//delete en element......
node* deletion(node* root,int ele){

    if(root==NULL) return NULL;

    if(root->data>ele) root->left=deletion(root->left,ele);

    else if(root->data<ele) root->right=deletion(root->right,ele);
    
    else{

       if(!root->left and !root->right){
          delete(root);
          return NULL;
       }

        /*
           node
           /  \
       node    node
        /
     root
        \
        node

        */
      else if(!root->left){

       node* temp=root->right;
        delete(root);
        return temp;
      }

        /*
           node
           /  \
       node    node
        /
     root
     /
  node

        */

      else if(!root->right){
        node* temp=root->left;
        delete(root);
      //  cout<<"ok\n";
        return temp;
      }

// left and right not NULL......
        else{
            node* par=root;
            node* child=root;

            child=child->left;

            while(child->right!=NULL){
              par=child;
              child=child->right;
            }

            if(root==par){
               child->right=root->right;
               delete(root);
               return child;
      
            }
            else{
               
               par->right=child->left;
               child->left=root->left;
               child->right=root->right;
               delete(root);
               return child;
            }
        }

  }

return root;
}
// insert an element......
node* insert_ele(node* root,int ele){

  if(root==NULL){
    node* newnode=new node(ele);

    return newnode;
  }
  
  if(root->data>ele){
    root->left=insert_ele(root->left,ele);

  }
  else root->right=insert_ele(root->right,ele);


  return root;
}

void inorder(node* root){

    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    
    int n;

    cin>>n;

    node* root=NULL;

    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        root=insert_ele(root,ele);

    }

    inorder(root);
    cout<<endl;

    int ele;
   cout<<"Delete ";
    cin>>ele;

    root=deletion(root,ele);

    inorder(root);
}