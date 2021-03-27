# Week 4 - 范型与模板

## Step 1 - 合并无权图和有权图的代码（选做）

既然无权图和有权图有大量重复的代码，我们可以提取出他们共同的部分来实现一个模板类，通过模板实例化实现代码复用。

我们可以创建一个模板类`Generic<TEdge>`，并添加一些使用边作为参数类型的内部接口：

```c++
template <typename TEdge>
class Generic {
    private:
        map<int, vector<TEdge>> edges;   // 此处举例使用邻接表作为数据结构
    protected:                           // 定义一些供派生类使用的内部接口
        bool InsertEdge(TEdge edge);     // 使用模板的参数作为参数类型，这样代码就可以轻松复用了
    public:
        bool RemoveEdge(int v1, int v2); // 删除边的参数是一样的，所以可以直接在模板类中定义
};

class Graph : public Generic<Edge> {     // 模板实例化，这是一种使用了无权图的边
    public:
        bool AddEdge(int v1, int v2);    // 通过调用父类的InsertEdge方法（注意继承关系中一定要尽量避免重名）来实现具体的接口
};

class WeightedGraph : public Generic<WeightedEdge> {
    public:
        bool AddEdge(int v1, int v2, int w);
};
```

## Step 2 - 将有权边和有权图更改为模板类型

现实生活中的图可能具有各种类型的权重（比如说地图用实数表示距离，自动机用字符串表示转移），我们需要支持各种各样的权重。

如果你完成了Step1的修改，下面的部分只需要添加几个`template`修改为模板即可。如果你没有完成Step1的部分，你就需要到处修改你的代码了，祝你好运。

```c++
template <typename T>
class WeightedEdge {
    // ......
};

// 做了step 1
template <typename T>
class WeightedGraph : public Generic<WeightedEdge<T>> {
    // ......
};

// 没做step 1
template <typename T>
class WeightedGraph {
    private:
        map<int, vector<WeightedEdge<T>>> edges; // 根据具体的类型创建不同的邻接表
};
```

## Step 3 - 提交代码进行测试

- 本次测试的所有内容和上周完全一致，时间限制提高到上周的1.5倍（具体的测试接口看上周的task）。
- 实现继承关系不强制要求实现`Generic`模板类，四种图可以没有任何继承关系（能AC的代码依然是好代码）。
- 测试有权图时，会测试两种C++内置的基础数据类型构成的有权图。

