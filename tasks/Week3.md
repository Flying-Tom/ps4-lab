# Week3 - 虚函数

请实现下面两个类：

- `DataStructures/UndirectedGraph.h`中定义`UndirectedGraph`类表示无向无权图，无向无权图继承自有向无权图（`Graph`类）
- `DataStructures/UndirectedWeightedGraph.h`中定义`UndirectedWeightedGraph`类表示无向有权图，无向有权图继承自有向有权图（`WeightedGraph`类）

这两个类的所有需要实现的接口都和父类相同，也就是说最优情况下只需要将`AddEdge`、`RemoveEdge`等方法进行重载即可。对一些可能存在歧义的函数我们做出如下约定：

1. 无向图中所有边虽然使用了有向图的数据结构，但是所有边都是没有方向的，也就是说`AddEdge(1, 2)`可以看作是添加了两条有向边，之后执行`AddEdge(2, 1)`时`2->1`这条边已经存在，应该返回`false`。
2. `CountEdges`返回的是无向边的数量。
3. `GetEdges`中，每条无向边可以以任意方向表示，但是不能出现重边（也就是说可以是`{{1, 2}}`，也可以是`{{2, 1}}`，但不能是`{{1, 2}, {2, 1}}`这样的结果）。

提示：

1. 无向图必须实现成有向图的子类（有权图和无权图的继承关系可以随意设计），测试中会考察的继承关系如下图所示。
2. 小心特殊情况（自环）。

```
                     G and UG not required
        Graph                                   WeightedGraph
          ^                                           ^
          | UG inherits G                             | UWG inherits WG
          |                                           |
   UndirectedGraph                          UndirectedWeightedGraph
```

---

如果你感兴趣的话，可以研究一下这种由于C++不存在接口类型但却允许多继承的奇怪机制*导致的奇怪又糟糕继承关系是如何实现的：

```
        UnweightedGeneric ------------->+<---------------- WeightedGeneric<T>
                ^                       |                          ^
                |                       |                          |
                |                       v                          |
              Graph -------------> Generic<T> <------------ WeightedGraph<T>
                ^                       ^                          ^
                |                       |                          |
                |                       |                          |
         UndirectedGraph -----> UndirectedGeneric <---- UndirectedWeightedGraph<T>
```

注：

1. 奇怪机制的意思是，如果C类同时继承了抽象类A和A的某一种实现B，由于C直接继承A，即使从B那里获得了这些纯虚函数的具体实现，由于他们是同名函数，所有的函数都被重写了，就导致(1)出现二义性，编译器不知道应该调用谁；或者(2)编译器认为纯虚函数没有被实现，C是一个纯虚类。（可以参考[这个Stackoverflow问题](https://stackoverflow.com/questions/29288295/c-abstract-class-implementation-in-another-base-class)）。
2. 这个设计出现了不可避免的菱形继承问题，使用了大量的虚继承。
