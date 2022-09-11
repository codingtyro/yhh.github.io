package 数据结构.红黑树;



class Node{
    public int data;
    public int color;
    public Node left;
    public Node right;
    public Node parent;
    public Node(){

    }
    public Node(int data){
        this.data = data;
        //初始化结点颜色都设为红色
        this.color = 0;
    }
    @Override
    public String toString(){
        return "Node{data=" + data + ", color=" + (color == 0 ? "red" : "black") + '}';
    }
}

class RedBlackTree{
    /**
     * 红色
     */
    private final int R = 0;

    /**
     * 黑色
     */
    private final int B = 1;

    /**
     * 根结点
     */
    public Node root;

    /**
     * 插入值
     * @param data
     */
    public void insert(int data){
        Node node = new Node(data);

        //插入根结点
        if(root == null){
            node.color = B;
            root = node;
            return ;
        }
        Node parent = root;
        Node son;

        if(data < parent.data){
            son = parent.left;
        }else{
            son = parent.right;
        }
        //递归
        while(son != null){
            parent = son;
            if(data < parent.data){
                son = parent.left;
            }else{
                son = parent.right;
            }
        }

        if(data < parent.data){
            parent.left = node;

        }else{
            parent.right = node;
        }

        node.parent = parent;
        //颜色变换
        colorConvert(node);
    }

    /**
     * 颜色变换，让整体符合红黑树规则
     * @param node
     */
    public void colorConvert(Node node){
        Node parent;
        Node grandpa;

        //当父结点不为空且颜色为红色
        while((parent = node.parent) != null && parent.color == R){
            grandpa = parent.parent;
            //如果父亲是爷爷的左子树

            
            if(grandpa.left == parent){
                //叔叔结点不为空且颜色为红色

                Node uncle = grandpa.right;
                if(uncle != null && uncle.color == R){
                    parent.color = B;
                    uncle.color = B;
                    grandpa.color = R;
                    continue;
                }

                if(node == parent.right){
                    //左旋
                    leftRotate(parent);
                    //左旋后父子关系互换
                    Node temp = node;
                    node = parent;
                    parent = temp;
                }
                parent.color = B;
                grandpa.color = R;

                //右旋
                rightRotate(grandpa);
            }else{
                //如果父亲是爷爷的右子树
                Node uncle = grandpa.left;

                if(uncle != null && uncle.color == R){
                    parent.color = B;
                    uncle.color = B;
                    grandpa.color = R;
                    node = grandpa;
                    continue;
                }

                if(node != parent.left){
                    //右旋
                    rightRotate(parent);
                    //右旋后父子身份互换
                    Node temp = node;
                    node = parent;
                    parent = temp;
                }
                parent.color = B;
                grandpa.color = R;
                //左旋
                leftRotate(grandpa);
            }
        }
        root.color = B;
    }

    /**
     * 左旋
     * @param node
     */
    public void leftRotate(Node node){
        Node right = node.right;
        Node parent = node.parent;

        if(parent == null){
            root = right;
            right.parent = null;
        }else{
            if(parent.left != null && parent.left == node){
                parent.left = right;
            }else{
                parent.right = right;
            }
            right.parent = parent;
        }
        node.parent = right;
        node.right = right.left;
        if(right.left != null){
            right.left.parent = node;
        }
        right.left = node;
    }

    /**
     * 右旋
     * @param node
     */
    public void rightRotate(Node node){
        Node left = node.left;
        Node parent = node.parent;

        if(parent == null){
            root = left;
            left.parent = null;
        }else{
            if(parent.left != null && parent.left == node){
                parent.left = left;
            }else{
                parent.right = left;
            }
            left.parent = parent;
        }
        node.parent = left;
        node.left = left.right;
        if(left.right != null){
            left.right.parent = node;
        }
        left.right = node;
    }

    /**
     * 前序遍历
     * @param root
     */
     public void beforeTraversal(Node root){
        if(root == null)return ;
        System.out.println(root.toString());
        beforeTraversal(root.left);
        beforeTraversal(root.right);
     }

     /**
      * 中序遍历
      * @param root
      */
     public void inTraversal(Node root){
        if(root == null)return ;
        inTraversal(root.left);
        System.out.println(root.toString());
        inTraversal(root.right);
     }

     public void afterTraversal(Node root){
        if(root == null)return ;
        afterTraversal(root.left);
        afterTraversal(root.right);
        System.out.println(root.toString());
     }
}

public class Main{
    public static void main(String[] args) {
        int[] nums = {10,8,12,5,9,1,6,7,6};
        RedBlackTree tree = new RedBlackTree();
        for(int num:nums){
            tree.insert(num);
        }
        System.out.println("前序遍历");
        tree.beforeTraversal(tree.root);
        System.out.println();
        System.out.println("中序遍历");
        tree.inTraversal(tree.root);
        System.out.println();
        System.out.println("后序遍历");
        tree.afterTraversal(tree.root);
    }
}