package 数据结构.二叉树;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;



public class Main {
    public static void main(String[] args) {
        BinaryTree t = new BinaryTree();
        t.init();
        t.close();

        System.out.println("前序遍历为：");
        t.preOrderTraverse(t.root);
        System.out.println();
        System.out.println("中序遍历为：");
        t.inOrderTraverse(t.root);
        System.out.println();
        System.out.println("后序遍历为：");
        t.lastOrderTraverse(t.root);
        System.out.println();
        System.out.println("层次遍历为：");
        t.levelOrderTraverse(t.root);
        System.out.println();
    }
}

class TreeNode{
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode(){

    }
     public TreeNode(int data){
        this.val = data;
        this.left = null;
        this.right = null;
    }
}


class BinaryTree{
    public TreeNode root;
    
    Scanner input = new Scanner(System.in);
    public void init(){
        System.out.println("输入-1时,则代表当前结点初始化为null");
        root = creatNode();
        System.out.println("一颗二叉树创建成功");
    }

    //创建一颗树
    public TreeNode creatNode(){
        TreeNode p;
        System.out.println("输入当前结点的值");
        int data = input.nextInt();
        if(data == -1){
            p = null;
        }else{
            p = new TreeNode(data);
            p.left = creatNode();
            p.right = creatNode();
        }
        return p;
    }
    //先序遍历
    public void preOrderTraverse(TreeNode root){
        if(root == null)return ;
        System.out.print(root.val + " ");
        preOrderTraverse(root.left);
        preOrderTraverse(root.right);
    }
    //中序遍历
    public void inOrderTraverse(TreeNode root){
        if(root == null)return ;
        inOrderTraverse(root.left);
        System.out.print(root.val + " ");
        inOrderTraverse(root.right);
    }
    //后序遍历
    public void lastOrderTraverse(TreeNode root){
        if(root == null)return ;
        lastOrderTraverse(root.left);
        lastOrderTraverse(root.right);
        System.out.print(root.val + " ");
    }
    //层次遍历
    public void levelOrderTraverse(TreeNode root){
        Queue<TreeNode>queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            int size = queue.size();
            for(int i = 0;i < size;i++){
                TreeNode node = queue.poll();
                System.out.print(node.val + " ");
                if(node.left != null)queue.add(node.left);
                if(node.right != null)queue.add(node.right);
            }
        }
    }
    //叶子结点的个数
    public int leftNum(TreeNode root){
        if(root == null){
            return 0;
        }else if(root.left == null && root.right == null){
            return 1;
        }else{
            return leftNum(root.left) + leftNum(root.right);
        }
    }
    //树的高度
    public int TreeDepth(TreeNode root){
        if(root == null)return 0;
        int left = TreeDepth(root.left);
        int right = TreeDepth(root.right);
        return left > right ? left + 1 : right + 1;
    }
    //树的结点个数
    public int TreeNodeNum(TreeNode root){
        if(root == null)return 0;
        return TreeNodeNum(root.left) + TreeNodeNum(root.right) + 1;
    }
    public void close(){
        input.close();
    }
}
