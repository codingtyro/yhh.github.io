#include<stdio.h>

//定义结点
struct BTNode{
    int data;//节点的值
    BTNode* left;//左子树
    BTNode* right;//右子树

    //结构体的构造函数
    BTNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

//根节点
BTNode* root;

//根结点
BTNode* createTree(){
        BTNode* p;
        int data;
        printf("输入当前结点的值\n");
        scanf("%d",&data);
        if(data == -1){
            p = NULL;
        }else{
            p = new BTNode(data);
            p->left = createTree();
            p->right = createTree();
        }
        return p;
    }

    //前序遍历
    void preOrderTraverse(BTNode* root){
        if(!root)return ;
        printf("%d ",root->data);
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }

    //中序遍历
    void inOrderTraverse(BTNode* root){
        if(!root)return ;
        inOrderTraverse(root->left);
        printf("%d ",root->data);
        inOrderTraverse(root->right);
    }

    //后序遍历
    void lastOrderTraverse(BTNode* root){
        if(!root)return ;
        lastOrderTraverse(root->left);
        lastOrderTraverse(root->right);
        printf("%d ",root->data);
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



void Init(){
        printf("在二叉树初始化的时候，输入-1,则代表,当前这个节点为空结点。\n" );
        root = createTree();
        printf("一颗二叉树创建成功\n");
    }

int main(){
    Init();
    printf("前序遍历为：\n");
    preOrderTraverse(root);
    printf("\n");
    printf("中序遍历为：\n");
    inOrderTraverse(root);
    printf("\n");
    printf("后序遍历为：\n");
    lastOrderTraverse(root);
    printf("\n");
    return 0;
}