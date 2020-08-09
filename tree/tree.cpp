#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
}

void preOrder(TreeNode* root){
    stack<TreeNode> stk;
    while(1){
        while(root){
            cout<<root->data;
            stk.push(root);
            root=root->left;
        }

        if(stk.empty()){
            return;
        }

        root = stk.top();
        stk.pop();

        root = root->right;
    }
}

void inOrder(TreeNode* root){
    stack<TreeNode*> stk;
    while(1){
        
        while(root){
            stk.push(root);
            root=root->left;
        }

        if(stk.empty()){
            break;
        }

        root = stk.top();
        stk.pop();

        cout<<root->data;

        root = root->right;
    }
}

void postOrder(TreeNode* root){
    stack<TreeNode*> stk;
    TreeNode* prev = NULL;
    do{
        //Traverse left subtree
        while(root){
            stk.push(root);
            root=root->left;
        }

        //Check if root's right is NULL or prev then print else traverse right
        while(root==NULL && !stk.empty()){
            root = stk.top();
            if(root->right == NULL || root->right == prev){
                cout<<root->data;
                stk.pop();
                prev=root;
                root=NULL;
            } else {
                root=root->right;
            }
        }
    } while(!stk.empty());
}

void levelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        cout<<temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
};

int main(){
    return 0;
} 