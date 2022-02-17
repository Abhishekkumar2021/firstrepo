#include <iostream>

using namespace std;

class node{

    public:
    int value;
    node *right,*left,*par;
    node(int d){
    value=d;
    right=NULL;
    left=NULL;
    }

};
void insertelement(int p,node* &top){
    node* n=new node(p);
    node* temp;
    temp= top;
    if(top==NULL){
        top=n;
        return;
    }
    while(1){
            if(temp->value>p){
                    if(temp->left!=NULL)
                    temp=temp->left;
            else{
                temp->left=n;
                n->par=temp;
                return;
                }
            }
            else{
               if(temp->right!=NULL)
                     temp=temp->right;
               else{
                    temp->right=n;
                    n->par=temp;
                    return;
                   }
    }
    }
}

node* minimum(node* top){
    node* temp=top;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* maximum(node* top){
     node* temp=top;
     while(temp->right!=NULL){
        temp=temp->right;
     }
     return temp;
}

node* successor(node* p){
     node* temp=p;
     node* parent;
     if(temp->right!=NULL){
        temp=temp->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
     }
     else{
            parent=temp->par;
            while(parent->right==temp){
                temp=parent;
                parent=parent->par;
            }
            temp=parent;
     }
     return temp;
}


node* predessor(node* p){
     node* temp=p;
     node* parent;
     if(temp->left!=NULL){
        temp=temp->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
     }
     else{
        parent=temp->par;
        while(parent->left==temp){
            temp=parent;
            parent=parent->par;
        }
        temp=parent;
     }
     return temp;
}

void print(node* top){
    node* temp=minimum(top);
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=successor(temp);
    }
    return;
}

void printpr(node* top){
    node* temp=maximum(top);
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp=predessor(temp);
    }
    return;
}

int main()
{
    node* top=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        insertelement(element,top);
    }
    print(top);
    return 0;
}
