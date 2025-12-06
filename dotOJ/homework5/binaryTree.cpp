//
// Created by 34021 on 2025/10/19.
//
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int id;//节点编号
    int R_sum;//右子树节点数量
    int L_sum;//左子树节点数量
    TreeNode *father;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int id) : id(id), R_sum(0),L_sum(0),father(nullptr),left(nullptr), right(nullptr){};
};


// 递归计算子树大小
int calculateSubtreeSize(TreeNode *node) {
    if (!node) return 0;

    // 递归计算左右子树大小
    node->L_sum = calculateSubtreeSize(node->left);
    node->R_sum = calculateSubtreeSize(node->right);

    // 返回当前子树的总大小（左子树 + 右子树 + 自身）
    return node->L_sum + node->R_sum + 1;
}

TreeNode *buildTree(int n, vector<vector<int> > &children) {
    vector<TreeNode *> nodes(n + 1, nullptr);
    vector<bool> hasParent(n + 1, false);

    //书的构建
    for (int i = 1;i <=n;i++) {
        nodes[i] = new TreeNode(i);
    }
    for (int i = 1; i <= n; i++) {
        if (children[i][0] != 0) {
            nodes[i]->left = nodes[children[i][0]];
            nodes[children[i][0]]->father = nodes[i];
            hasParent[children[i][0]] = true;
        }
        if (children[i][1] != 0) {
            nodes[i]->right = nodes[children[i][1]];
            nodes[children[i][1]]->father = nodes[i];
            hasParent[children[i][1]] = true;
        }
    }
    //找到根节点
    TreeNode *root = nullptr;
    for (int i = 1; i <= n; i++) {
        if (!hasParent[i]) {
            root = nodes[i];
            break;
        }
    }
    // 第三步：递归计算所有节点的子树大小
    if (root) {
        calculateSubtreeSize(root);
    }
    return root;
}

void clearTree(TreeNode *root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int query(int x,int y) {
    cout << "? " << x << ' ' << y <<endl;
    int ans;
    cin >> ans;
    return ans;
}
// 查找树的重心
TreeNode* findCentroid(TreeNode* node, int total_size, TreeNode* parent = nullptr) {
    if (!node) return nullptr;

    // 检查当前节点是否是重心
    bool isCentroid = true;

    // 检查左子树
    if (node->left && node->L_sum > total_size / 2) {
        isCentroid = false;
        TreeNode* candidate = findCentroid(node->left, total_size, node);
        if (candidate) return candidate;
    }

    // 检查右子树
    if (node->right && node->R_sum > total_size / 2) {
        isCentroid = false;
        TreeNode* candidate = findCentroid(node->right, total_size, node);
        if (candidate) return candidate;
    }

    // 检查父节点方向（需要考虑整棵树的大小）
    if (parent) {
        int parent_direction_size = total_size - (node->L_sum + node->R_sum + 1);
        if (parent_direction_size > total_size / 2) {
            isCentroid = false;
        }
    }

    return isCentroid ? node : nullptr;
}
//特殊情况不排除重心
TreeNode* createNewSubtree2(TreeNode* root, TreeNode* centroid) {
    if (!root || root == centroid ->left||root == centroid ->right) return nullptr;

    TreeNode* new_node = new TreeNode(root->id);

    TreeNode* left_child = createNewSubtree2(root->left, centroid);
    new_node->left = left_child;
    if (left_child != nullptr) {
        left_child->father = new_node;
    }
    TreeNode* right_child = createNewSubtree2(root->right, centroid);
    new_node->right = right_child;
    if (right_child != nullptr) {
        right_child->father = new_node;
    }
    calculateSubtreeSize(new_node);
    return new_node;
}
// 创建新的子树（排除重心及其子树）
TreeNode* createNewSubtree(TreeNode* root, TreeNode* centroid) {
    if (!root || root == centroid) return nullptr;

    TreeNode* new_node = new TreeNode(root->id);

    TreeNode* left_child = createNewSubtree(root->left, centroid);
    new_node->left = left_child;
    if (left_child != nullptr) {
        left_child->father = new_node;
    }
    TreeNode* right_child = createNewSubtree(root->right, centroid);
    new_node->right = right_child;
    if (right_child != nullptr) {
        right_child->father = new_node;
    }
    calculateSubtreeSize(new_node);
    return new_node;
}

int calculateNewSize2(TreeNode* root, TreeNode* centroid) {
    if (!root || root == centroid ->left||root == centroid ->right) return 0;
    return 1 + calculateNewSize2(root->left, centroid) + calculateNewSize2(root->right, centroid);
}
// 计算新子树的大小
int calculateNewSize(TreeNode* root, TreeNode* centroid) {
    if (!root || root == centroid) return 0;
    return 1 + calculateNewSize(root->left, centroid) + calculateNewSize(root->right, centroid);
}

// 重心分解搜索
void BinarySearch(TreeNode* root, int total_size) {
    if (!root) return;

    // 如果当前子树只有一个节点，直接输出
    if (total_size == 1) {
        cout << "! " << root->id << endl;
        return;
    }

    // 找到重心
    TreeNode* centroid = findCentroid(root, total_size);

    if (!centroid) {
        centroid = root;
    }

    // 如果重心是叶子节点，直接输出
    if (centroid->L_sum == 0 && centroid->R_sum == 0) {
        cout << "! " << centroid->id << endl;
        return;
    }

    // 选择两个候选节点进行询问
    TreeNode* candidate1 = nullptr;
    TreeNode* candidate2 = nullptr;

    if (centroid->left && centroid->right) {
        candidate1 = centroid->left;
        candidate2 = centroid->right;
    } else if (centroid->left && centroid ->father) {
        candidate1 = centroid->left;
        candidate2 = centroid -> father;
    } else if (centroid->right && centroid -> father) {
        candidate1 = centroid -> father;
        candidate2 = centroid->right;
    } else {
        TreeNode* candidate3 = nullptr;
        if (centroid -> father) {
            candidate3 = centroid ->father;
        }
        if (centroid -> left) {
            candidate3 = centroid -> left;
        }
        if (centroid -> right) {
            candidate3 = centroid ->right;
        }
        int result = query(centroid -> id,candidate3 ->id);
        if (result == 0) {
            cout << "! " << centroid ->id << endl;
            return;
        }
        else {
            cout << "! " << candidate3 -> id <<endl;
            return;
        }
    }

    // 进行询问
    int result = query(candidate1->id, candidate2->id);

    if (result == 0) {
        if (candidate1 == centroid->left) {
            // 进入左子树
            TreeNode *new_root = createNewSubtree(centroid -> left, centroid);
            if (new_root) {
                int new_size = calculateNewSize(new_root, centroid);
                BinarySearch(new_root, new_size);
                clearTree(new_root);
            } else {
                cout << "! " << centroid->father->id << endl;
            }

        } else {
            TreeNode *new_root = createNewSubtree(root, centroid);
            if (new_root) {
                int new_size = calculateNewSize(new_root, centroid);
                BinarySearch(new_root, new_size);
                clearTree(new_root);
            } else {
                cout << "! " << centroid->father->id << endl;
            }
        }
    } else if (result == 2) {
        if (candidate2 == centroid->right) {
            // 进入右子树
            TreeNode *new_root = createNewSubtree(centroid ->right, centroid);
            if (new_root) {
                int new_size = calculateNewSize(new_root, centroid);
                BinarySearch(new_root, new_size);
                clearTree(new_root);
            } else {
                cout << "! " << centroid->father->id << endl;
            }
        } else {
                // 父节点更近，递归到父节点方向
                TreeNode* new_root = createNewSubtree(root, centroid);
                if (new_root) {
                    int new_size = calculateNewSize(new_root, centroid);
                    BinarySearch(new_root, new_size);
                    clearTree(new_root);
                } else {
                    cout << "! " << centroid->father->id << endl;
                }

        }
    } else {
        if (candidate1 == centroid ->father || candidate2 == centroid ->father) {
            cout << "! " << centroid ->id<<endl;
            return;
        }
        else {
            TreeNode* new_root = createNewSubtree2(root, centroid);
            if (new_root) {
                int new_size = calculateNewSize2(new_root, centroid);
                BinarySearch(new_root, new_size);
                clearTree(new_root);
            }else {
                cout << "! " << centroid->father->id << endl;
            }
        }
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> children(n + 1,vector<int>(2));
        for (int i = 1;i <= n;i++){
            cin >> children[i][0] >> children[i][1];
        }
        TreeNode *root = buildTree(n,children);

        //寻找重心
        BinarySearch(root,n);

        clearTree(root);
    }

    return 0;
}