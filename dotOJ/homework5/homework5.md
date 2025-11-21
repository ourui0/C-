# 快速选择与树

## 树的构建

**节点构建**
```c++
//二叉树节点构建
struct Treenode{
  int val;
  TreeNode *left;
  TreeNode *right;
  Treenode(int x): val(x),left(nullptr),right(nullptr){}
}

//不使用指针
struct node {
    int idx = 0;
    int left = 0;
    int right = 0;
    int parent = 0;
};
```
**树的构建**
```c++
//二叉树
auto root = make_shared<SafeTreeNode>(1);
root->left = make_shared<SafeTreeNode>(2);
root->right = make_shared<SafeTreeNode>(3);

//多叉树
vector<int> nums(maxN);
nums[1].val = 1;
nums[1].left = 2;
nums[1].left = 0;//表示没有
```

**多叉树**
```c++
class MultiTreeNode {
public:
    int data;
    vector<MultiTreeNode*> children;
    
    MultiTreeNode(int value) : data(value) {}
    
    // 添加子节点
    void addChild(MultiTreeNode* child) {
        children.push_back(child);
    }
    
    // 添加子节点（通过值）
    void addChild(int value) {
        children.push_back(new MultiTreeNode(value));
    }
    
    // 安全删除（递归删除所有子节点）
    ~MultiTreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};
```

## 树的遍历（以二叉树为例）
### 递归遍历

**前序遍历**

根 -> 左子树 -> 右子树
```c++
vector<int> preorderRecursive(TreeNode* root) {
     vector<int> result;
     preorderHelper(root, result);
     return result;
}
void preorderHelper(TreeNode* node, vector<int>& result) {
     if (!node) return;
     result.push_back(node->val);      // 访问根节点
     preorderHelper(node->left, result);  // 遍历左子树
     preorderHelper(node->right, result); // 遍历右子树
}
```

**中序遍历**

左子树 -> 根 -> 右子树
```c++
vector<int> inorderRecursive(TreeNode *root){
     vector<int> result;
     inorderHelper(root, result);
     return result;
}
void inorderHelper(TreeNode *node,vector<int>& result){
     if(!node)return;
     inorderHelper(root -> left,result);//遍历左子树
     result.push_back(node ->val);//访问根节点
     inorderHelper(root -> right,result);//便利右节点
}
```

**后序遍历**

左子树 -> 右子树 -> 根
```c++
vector<int> postorderRecursive(TreeNode *root){
     vector<int> result;
     postorderHelper(root,result);
     return result;
} 
void postorderHelper(TreeNode *node,vector<int>& result){
     if (!node)return;
     postorderHelper(root -> left,result);
     postorderHelper(root -> right,result);
     result.push_back(node -> val);
}
```

### 迭代遍历

```c++
class IterativeTraversal {
public:
    // 迭代前序遍历
    vector<int> preorderIterative(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            
            result.push_back(node->val);
            
            // 先右后左，保证左子树先被访问
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }
    
    // 迭代中序遍历
    vector<int> inorderIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        while (current || !st.empty()) {
            // 遍历到最左边的节点
            while (current) {
                st.push(current);
                current = current->left;
            }
            
            current = st.top();
            st.pop();
            result.push_back(current->val);
            
            // 转向右子树
            current = current->right;
        }
        return result;
    }
    
    // 迭代后序遍历（使用两个栈）
    vector<int> postorderIterative(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st1, st2;
        st1.push(root);
        
        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            
            if (node->left) st1.push(node->left);
            if (node->right) st1.push(node->right);
        }
        
        while (!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }
        return result;
    }
    
    // 迭代后序遍历（使用一个栈）
    vector<int> postorderIterativeSingleStack(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;
        
        while (current || !st.empty()) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode* peekNode = st.top();
                // 如果右子树存在且未被访问
                if (peekNode->right && peekNode->right != lastVisited) {
                    current = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }
        return result;
    }
};
```
### 层序遍历
使用队列进行迭代遍历
```c++
vector<vector<int>>  levelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(root == nullptr)return result;
    queue<TreeNode *> que;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int> temp;
        for (int i = 0; i < size;i++){
            TreeNode *node = que.front();
            que.pop();
            temp.push_back(node -> val);
            if (node -> left)temp.push(node -> left);
            if (node -> right)temp.push(node -> right);
        }
        result.push_back(temp);
    }
    return result;
}
```