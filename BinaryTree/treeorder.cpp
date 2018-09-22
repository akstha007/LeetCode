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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> row;
        queue<TreeNode*> q;
        
        if(root==NULL)
            return result;
        
        q.push(root);
        int count = 1;
        while(!q.empty()){
            root = q.front();
            row.push_back(root->val);
            q.pop();

            if(root->left!=NULL)
                q.push(root->left);

            if(root->right!=NULL)
                q.push(root->right);

            count--;
            if(count==0){
                count = q.size();
                result.push_back(row);
                row.clear();
            }
        }  

        return result;   
    }

    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        
        return max(left_depth, right_depth) + 1;
            
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* leftRoot, TreeNode* rightRoot){
        if(!leftRoot and !rightRoot)
            return true;
        
        if(leftRoot && rightRoot && (leftRoot->val == rightRoot->val))
            return (isSymmetric(leftRoot->left, rightRoot->right) && isSymmetric(leftRoot->right, rightRoot->left));
        
        return false;
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;

        sum = sum - root->val;
        bool result = false;

        if(sum==0 && !root->left && !root->right)
            return true;
        
        if(root->left)
            result = result || hasPathSum(root->left, sum);

        if(root->right)
            result = result || hasPathSum(root->right, sum);
        
        return result;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
    }
};

