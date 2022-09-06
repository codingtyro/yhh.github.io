package 数据结构.队列;

/*
 * 队列是一个有序列表，可以用数组或是链表来实现。
 * 遵循先入先出的原则。即：先存入队列的数据，要先取出，后存入的要后取出。
 */

class ArrayQueue{
    // 队列最大长度
    int maxSize;
    // 数组队列
    int[] arr;
    // 指向队列首元素
    int front;
    // 指向队列尾元素
    int rear;

    int size;

    // 初始化队列只需要指定队列的最大长度
    public ArrayQueue(int maxSize){
        this.maxSize = maxSize;
        arr = new int[this.maxSize];
        // front指向首元素的前一个位置
        front = -1;
        rear = -1;
        size = 0;
    }

    // 判断队列是否为空
    boolean isEmpty(){
        return front == rear;
    }
    // 判断队列是否满了
    boolean isFull(){
        return front == maxSize -1;
    }

    // 进队列
    public void addElement(int element){
        if (isFull()){
            System.out.println("已经填满了，不能再塞了!");
        }
        rear ++;
        size ++;
        arr[rear]  = element;
    }

    //  获取出队列元素
    public int getElement(){
        if (isEmpty()){
            System.out.println("队列为空，无法出来！");
        }
        /**
         * 这个地方可能会有疑问？因为我当时也没想清楚，记录一下
         *   假设  进队列   1  2  3  4   rear随着元素添加，rear也在变大
         *   front是不用动的，他只是在等待，当有人获取时我永远获取队列首的元素
         *   因为出队列出来的永远都是队列第一个元素  arr[0] arr[1]  arr[2]
         */
        front++;
        size--;
        System.out.print("出队列的元素是：");
        return arr[front];

    }

    // 打印队列
    public void show(){
        if (isEmpty()){
            System.out.println("空队列你想看啥！");
            return;
        }
        System.out.println("遍历元素");
        /**
         * 遍历没有出队列的元素
         */
        for (int start = front+1; start <= rear; start++) {
            System.out.print(arr[start]+" ");
        }
    }

    //得到队列的长度
    public int size(){
        return  size;
    }
}