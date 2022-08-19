# 并查集

并查集

1. 将两元素两两合并 （union）
2. 询问两个元素是否在一个集合中 （find）
3. 求连通子图
4. 求公共祖先

## 模版（Java）

```java
class UF {
    public int N;
    public int count;

    public int[] id;   // 存当前id的祖宗节点
    public int[] size; // 当节点是祖宗节点时有效。每个节点都是其自身的祖宗（默认为1）

    UF(int n) {
        N = n;
        count = n;

        id = new int[n+1];   // 节点id从1开始
        size = new int[n+1]; // 节点id从1开始

        for (int i = 1; i <= n; i++) {
            id[i] = i;      // 初始化每个节点都是其自身的祖宗
            size[i] = 1;
        }
    }

    public int find(int p) {
        if (p == id[p]) {
            return p;
        }

        id[p] = find(id[p]); // 带路径压缩的方法

        return id[p];
    }
    
}
```

## 