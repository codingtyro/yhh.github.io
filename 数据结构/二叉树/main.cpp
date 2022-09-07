#include<iostream>
#include<queue>
using namespace std;

//定义结点
class BTNode{
public:
    int data;//节点的值
    BTNode* left;//左子树
    BTNode* right;//右子树

    //结构体的构造函数
    BTNode(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    BTNode(){

    }
};

class BinaryTree{
public:
    BTNode* root;

    void Init(){
        cout << "在二叉树初始化的时候，输入-1,则代表,当前这个节点为空结点。" << endl;
        root = createTree();
        cout << "一颗二叉树创建成功" << endl;
    }

    //创建一颗树
    BTNode* createTree(){
        BTNode* p;
        int data;
        cout << "输入当前结点的值" <<endl;
        cin >> data;
        if(data == -1){
            p = nullptr;
        }else{
            p = new BTNode(data);
            p->left = createTree();
            p->right = createTree();
        }
        return p;
    }
    //先序遍历
    void preOrderTraverse(BTNode* root){
        if(!root)return ;
        cout << root->data << " ";
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }

    //中序遍历
    void inOrderTraverse(BTNode* root){
        if(!root)return ;
        inOrderTraverse(root->left);
        cout << root->data << " ";
        inOrderTraverse(root->right);
    }

    //后序遍历
    void lastOrderTraverse(BTNode* root){
        if(!root)return ;
        lastOrderTraverse(root->left);
        lastOrderTraverse(root->right);
        cout << root->data << " ";
    }

    // 层次遍历

    void levelOrderTraverse(BTNode* root){
        //层次遍历要借助一个队列
        queue<BTNode*>que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i < size;i++){
                BTNode* node = que.front();
                que.pop();
                cout << node->data << " ";
                if(node->left != nullptr)que.push(node->left);
                if(node->right != nullptr)que.push(node->right);
            }
        }
    }

    //求叶子结点的个数
    int leftNum(BTNode* root){
        if(root == nullptr)return 0;
        else if(root->left == nullptr && root->right == nullptr){
            return 1;
        }else{
            return leftNum(root->left) + leftNum(root->right);
        }
    }

    //求树的结点个数
    int BTNodeNum(BTNode* root){
        if(root == nullptr)return 0;
        return BTNodeNum(root->left) + BTNodeNum(root->right);
    }

    //树的高度
    int TreeDepth(BTNode* root){
        if(root == nullptr)return 0;
        int left = TreeDepth(root->left);
        int right = TreeDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};

int main(){
    BinaryTree t;
    t.Init();
    cout << "前序遍历为：" << endl;
    t.preOrderTraverse(t.root);
    cout << endl;
    cout << "中序遍历为: " << endl;
    t.inOrderTraverse(t.root);
    cout <<endl;
    cout << "后序遍历为：" << endl;
    t.lastOrderTraverse(t.root);
    cout << endl;
    cout << "层次遍历为：" << endl;
    t.levelOrderTraverse(t.root);
    cout <<endl;
    return 0;
}