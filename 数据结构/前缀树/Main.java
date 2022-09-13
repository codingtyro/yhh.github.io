package 数据结构.前缀树;

import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        
    }
}

class Trie {
    private boolean isEnd;
    Map<Character,Trie> children;
    public Trie() {
        isEnd = false;
        children = new HashMap<>();
    }
    
    public void insert(String word) {
        Trie node = this;
        char[] s = word.toCharArray();
        for(char c:s){
            if(!node.children.containsKey(c)){
                node.children.put(c,new Trie());
            }
            node = node.children.get(c);
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        Trie node = searchPrefix(word);
        return node!=null&&node.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        return searchPrefix(prefix)!=null;
    }
    public Trie searchPrefix(String prefix){
        Trie node =this;
        char[] s = prefix.toCharArray();
        for(char c:s){
            if(!node.children.containsKey(c))return null;
            node = node.children.get(c);
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
