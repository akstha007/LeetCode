/* Preorder traversal in binary tree
 * Tree node:
 *  struct TreeNode{
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode(int x): val(x), left(NULL), right(NULL){}
 *  };
 *
 */

#include"iostream"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;

        if(root==NULL)
            return result;

        nodeStack.push(root);

        while(!nodeStack.empty()){
            TreeNode* node = nodeStack.top();
            result.push_back(node->val);
            nodeStack.pop();

            if(node->right!=NULL)
                nodeStack.push(node->right);

            if(node->left!=NULL)
                nodeStack.push(node->left);
        } 
        
        return result;      
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;

        if(root==NULL)
            return result;

        TreeNode* curr = root;

        while(curr!=NULL || !nodeStack.empty()){
        
            while(curr!=NULL){
                nodeStack.push(curr);
                curr = curr->left;
            }
            
            curr = nodeStack.top();
            result.push_back(curr->val);
            nodeStack.pop();

            curr = curr->right;
        } 
        
        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stackNode;
        vector<int> result;
        stack<int> stackResult;
        
        if(root==NULL)
            return result;

        stackNode.push(root);
        while(!stackNode.empty()){
            TreeNode* curr = stackNode.top();
            stackNode.pop();
            stackResult.push(curr->val);

            if(curr->left!=NULL)
                stackNode.push(curr->left);

            if(curr->right!=NULL)
                stackNode.push(curr->right);
        }

        while(!stackResult.empty()){
            result.push_back(stackResult.top());
            stackResult.pop();
        }
        
        return result;
    }

    //post order traversal using one stack
    vector<int> postorderTraversalOneStack(TreeNode* root) {
        stack<TreeNode*> stackNode;
        vector<int> result;
        
        if(root==NULL)
            return result;

        TreeNode* curr = root;
        while(curr!=NULL || !stackNode.empty()){
            if(curr!=NULL){
                stackNode.push(curr);
                curr = curr->left;
            }else{
                TreeNode* temp = stackNode.top()->right;
                if(temp!=NULL){
                    curr = temp;
                }else{
                    temp = stackNode.top();
                    stackNode.pop();
                    result.push_back(temp->val);
                    while(!stackNode.empty() && temp==stackNode.top()->right){
                        temp = stackNode.top();
                        stackNode.pop();
                        result.push_back(temp->val);
                    }
                }
            }


        }
        
        return result;
    }
};

