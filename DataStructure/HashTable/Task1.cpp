#include <iostream>
#include <vector>
#include <map>
using namespace std;

// set node and tree

struct Node{
    int key;
    Node *left, *right;
};

struct Node* newNode(int key)
{
    struct Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
};

/**
 * Theo quy ước, gốc của cây là root
 * Gọi Horizon Distance của một node là HD
 * Nếu Node ở cánh trái của 1 node phía trước, HD = HD - 1
 * Tương tự, nếu bên phải Node sẽ là HD = HD + 1
 */

void getVerticalOrder(Node *root,int hd, map<int, vector<int>> &m)  //int sẽ là phần bucket, còn vector là phần nội dụng các số cùng bucket
{
    //Kiểm tra root
    if(root == NULL)
        return;
    //Nếu root có giá trị sẽ đẩy vào map vs bucket hd
    m[hd].push_back(root->key);

    getVerticalOrder(root->left,hd - 1,m);
    
    getVerticalOrder(root->right,hd + 1,m);
}

void printVerticalOrder(Node *root)
{
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root,hd,m);

    map<int, vector<int>> :: iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        for(int i = 0; i < it->second.size(); i++)
            cout << it->second[i] << "  ";
        cout << endl;
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n" << endl;
    printVerticalOrder(root);
    return 0;
}
