//
// Created by 34021 on 2025/9/29.
//
#include "B.h"
#include <algorithm>
// TrieNode 默认构造函数的实现
TrieNode::TrieNode() : val('\0'), isend(false), prefix_count(0) {

}

// TrieNode 带字符参数的构造函数的实现
TrieNode::TrieNode(char v) : val(v), isend(false), prefix_count(0) {

}

// TrieNode 析构函数的实现
// 负责输出信息，但不负责删除子节点，子节点的内存释放由Trie类的析构函数负责
TrieNode::~TrieNode() {
    std::cout << "~TrieNode!" << std::endl;
}

// Trie 类构造函数的实现
Trie::Trie() {
    root = new TrieNode(); // 创建根节点
}

// Trie 类析构函数的实现
// 负责释放所有动态内存
Trie::~Trie() {
    destroy(root);
}

// 辅助函数，用于递归释放所有节点
void Trie::destroy(TrieNode* node) {
    for (auto &i : node->child) {
        destroy(i);
    }
    delete node;
}

// 插入一个单词
void Trie::Insert(std::string st) {
    TrieNode *p = root;
    for (char c : st) {
        bool found = false;
        for (auto &child : p->child) {
            if (child->val == c) {
                p = child;
                found = true;
                break;
            }
        }
        if (!found) {
            TrieNode *newNode = new TrieNode(c);
            p->child.push_back(newNode);
            p = newNode;
        }
        p->prefix_count++;
    }
    p->isend = true;
}

// 查询一个单词是否存在
bool Trie::Lookup(std::string st) {
    TrieNode *p = root;
    for (char c : st) {
        bool found = false;
        for (auto &child : p->child) {
            if (child->val == c) {
                p = child;
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return p->isend;
}

// 查询前缀的单词数量
int Trie::Prefix(std::string st) {
    TrieNode *p = root;
    for (char c : st) {
        bool found = false;
        for (auto &child : p->child) {
            if (child->val == c) {
                p = child;
                found = true;
                break;
            }
        }
        if (!found) {
            return 0;
        }
    }
    return p->prefix_count;
}
int main() {
    Trie* trie = new Trie;
    trie->Insert("appl");
    trie->Insert("appl");
    trie->Insert("appllllllllllllllll");
    trie->Insert("april");
    trie->Insert("banana");
    trie->Insert("band");
    std::cout << trie->Prefix("appl") << std::endl;
    std::cout << trie->Prefix("a") << std::endl;    // 输出 3 (["apple", "app", "april"])
    std::cout << trie->Prefix("ap") << std::endl;   // 输出 3 (["apple", "app", "april"])
    std::cout << trie->Prefix("app") << std::endl;  // 输出 2 (["apple", "app"])
    std::cout << trie->Prefix("appl") << std::endl; // 输出 1 (["apple"])
    std::cout << trie->Prefix("ban") << std::endl;  // 输出 2 (["banana", "band"])
    std::cout << trie->Prefix("bana") << std::endl; // 输出 1 (["banana"])
    std::cout << trie->Prefix("candit") << std::endl; // 输出 0: 没有任何以 "bandit" 开头的单词
    delete trie;
    return 0;
}