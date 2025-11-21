//
// Created by 34021 on 2025/10/17.
//
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    long long val;//权值
    long long id;//节点编号
    TreeNode *left;
    TreeNode *right;
    TreeNode(long long id, long long weight) : id(id), val(weight), left(nullptr), right(nullptr){};
};
class BinaryTreeBuilder {
private:
    // 存储所有节点的映射表，key为节点编号
    unordered_map<long long, TreeNode*> nodeMap;

public:
    // 构建二叉树
    TreeNode* buildTree(long long n, vector<vector<long long>>& children, vector<long long>& weights) {
        nodeMap.clear();

        // 第一步：创建所有节点
        for (long long i = 1; i <= n; i++) {
            nodeMap[i] = new TreeNode(i, weights[i-1]);
        }

        // 第二步：建立父子关系
        TreeNode* root = nullptr;
        vector<bool> hasParent(n + 1, false);

        for (long long i = 1; i <= n; i++) {
            long long leftChild = children[i-1][0];  // 左儿子编号
            long long rightChild = children[i-1][1]; // 右儿子编号

            if (leftChild != 0) {
                nodeMap[i]->left = nodeMap[leftChild];
                hasParent[leftChild] = true;
            }
            if (rightChild != 0) {
                nodeMap[i]->right = nodeMap[rightChild];
                hasParent[rightChild] = true;
            }
        }
        for (long long i = 1; i <= n; i++) {
            if (!hasParent[i]) {
                root = nodeMap[i];
                break;
            }
        }
        return root;//根节点不一定是第一个节点
    }

    // 清理内存
    void clearTree(TreeNode* root) {
        if (!root) return;
        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }
};
class TreePartition {
private:
    long long count = 0;

public:
    long long dfs(TreeNode* node, long long k) {
        if (!node) return 0;

        long long leftSum = dfs(node->left, k);

        long long rightSum = dfs(node->right, k);


        long long currentSum = leftSum + rightSum + node->val;
        // 调试输出
        if (currentSum == k) {
            count++;
            return 0;
        }
        return currentSum;
    }

    // 判断是否可以成功分割
    bool canPartition(TreeNode* root, long long k, long long totalWeight) {
        if (totalWeight % k != 0) {
            return false;
        }

        count = 0;

        long long remain = dfs(root, k);

        return remain == 0 && count == totalWeight / k;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long T;
    cin >> T;

    BinaryTreeBuilder builder;
    TreePartition partition{};

    while (T--) {
        long long n,k;
        cin >>n >>k;
        vector<vector<long long>> children(n,vector<long long> (2));//储存左右节点
        for (long long i = 0;i < n;i++) {
            cin >> children[i][0] >> children[i][1];
        }

        long long totalWeight = 0;
        vector<long long> weights(n);//储存每个节点的权重
        for (long long i = 0;i < n;i++) {
            cin >> weights[i];
            totalWeight += weights[i];
        }
        TreeNode* root = builder.buildTree(n, children, weights);

        // 判断是否可以分割
        if (partition.canPartition(root, k, totalWeight)) {
            cout << "YES" << '\n'; // 可以分割
        } else {
            cout << "NO" << '\n'; // 不能分割
        }

        builder.clearTree(root);
    }
}