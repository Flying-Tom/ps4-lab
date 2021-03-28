template <typename TEdge>
class Generic
{
private:
    map<int, vector<TEdge>> edges; // 此处举例使用邻接表作为数据结构
protected:                         // 定义一些供派生类使用的内部接口
    bool InsertEdge(TEdge edge);   // 使用模板的参数作为参数类型，这样代码就可以轻松复用了
public:
    bool RemoveEdge(int v1, int v2); // 删除边的参数是一样的，所以可以直接在模板类中定义
};

class Graph : public Generic<Edge>
{ // 模板实例化，这是一种使用了无权图的边
public:
    bool AddEdge(int v1, int v2); // 通过调用父类的InsertEdge方法（注意继承关系中一定要尽量避免重名）来实现具体的接口
};

class WeightedGraph : public Generic<WeightedEdge>
{
public:
    bool AddEdge(int v1, int v2, int w);
};