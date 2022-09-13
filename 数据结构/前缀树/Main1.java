package 数据结构.前缀树;

public class Main1 {
    public static void main(String[] args) {
        
    }
}

class Trie {
    private Trie[] children;//当前这颗树的子树。
    private boolean isEnd;
    // 前缀树的初始化
    public Trie() {
        children = new Trie[26];
        isEnd = false;
    }
    //将字符串插入前缀树中
    public void insert(String word) {
        Trie node = this;
        char[] s = word.toCharArray();
        for(char c:s){
            int index = c - 'a';
            if(node.children[index] == null){
                node.children[index] = new Trie();
            }
            node = node.children[index];
        }
        node.isEnd = true;
    }
    //判断是否存在word这个字符串。
    public boolean search(String word) {
        Trie node = searchPrefix(word);
        return node!=null&&node.isEnd;
    }
    //判断是否存在以prefix这个字符串为前缀的字符串。
    public boolean startsWith(String prefix) {
        return searchPrefix(prefix)!=null;
    }
    
    public Trie searchPrefix(String prefix){
        Trie node = this;
        char[] s = prefix.toCharArray();
        for(char c:s){
            int index = c - 'a';
            if(node.children[index]==null)return null;
            node = node.children[index];
        }
        return node;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
