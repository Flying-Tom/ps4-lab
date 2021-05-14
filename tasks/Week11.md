# Week 11 - 二分图匹配

本周我们需要完成无权的二分图匹配算法，**在`Algorithms/BipartiteGraphMatching.h`中已经定义了模板类`BipartiteGraphMatching`，你需要实现它的若干个接口**，各接口说明如下：

- `BipariteGraphMatching(const TGraph* g, std::unordered_set<int> left, std::unordered_set<int> right)`：在给定的图`g`上执行二分图匹配算法（`g`一定是`UndirectedGraph`或`UndirectedWeightedGraph`），以`left`为左部，`right`为右部（图中可能存在既不属于左部也不属于右部的点，这种情况不需要报错），遇到以下情况，则抛出异常`std::invalid_argument`，报错信息随意（不会被测）：
  - `left`与`right`存在公共点。
  - `left`或`right`存在图中没有的点。
  - `left`（或`right`）中的点，在图上与`right`（或`left`）以外的点相连（无论是与自己所在集合还是非`left`、`right`的集合）
- `int SumOfMatches() const;`：返回图`g`的最大匹配中的边个数。
- `optional<int> FindMatchOf(int idx) const;`：返回与`idx`配对的点。如果没有与`idx`配对的点或`idx`不属于图的左右部，则返回空。

由于二分图的最大匹配可能存在多个解，返回任何一个解都是可行的。但是需要注意，`BipariteGraphMatching`对象构造完毕后，你的解应该确定好。对于同一个对象的多次函数调用，返回的结果应该属于同一个解。

