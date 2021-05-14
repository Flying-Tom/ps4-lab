# Week 10 - 异常

## 接口调整

`include/Algorithm/MultiSourceShortestPaths.h` 中的`HasPathTo`、`TryGetShortestPathTo`和`TryGetShortestPathTo`中的To替换为了语义更准确的Of。



本周我们需要实现对异常的支持，在`include/Exceptions/GLException`中已经定义了`GLException`，**请在`include/Exceptions`中定义`NegativeCycleException`**，并继承自`GLException`。

## 不符合规约的情况

在上周，我们提到，利用`static_assert`，我们可以检查传入的模板参数是否符合某些约束条件（C++20中将引入concept以简化代码写法），以此在编译期拒绝掉不符合规约的情况。

然而，有一些不符合规约的情况，是难以或者无法在编译期检查出来的。此时，我们就要利用异常。

我们前两周实现的Bellman Ford和Floyd都是这样的例子。如果输入的图中存在负环（在Bellman-Ford中只需要检查从起点可达的负环即可），那么算法的更新就无法停止或者返回的结果没有意义。

所以，我们要修改上周的代码，在检测到这种情况时，通过`throw`抛出一个类型为`NegativeCycleException`或其子类的异常。

由于负环难以定义，所以抛出的异常中不需要包含负环。但为了方便潜在的用户debug，异常中需包含当前正在运行的算法名（分别是`Bellman-Ford`和`Floyd`）。（这样，如果用户在运行一个非常复杂的算法时遇到异常，他就可以通过异常中的信息，确定异常发生在哪个函数的内部）

你throw的异常的结构体里可以包含任意你觉得可能有助于debug的信息，我们只会通过`operator<<(std::ostream&, const GLException&)`对结果进行评判，因此你要确保`cout`的输出结果只包含算法名。

评判方式类似于：

```c++
try {
    // 建图、跑算法
} catch(const NegativeException& e) {
    cout << e;
}
```

所以，如果运行的是Bellman-Ford算法，你要确保`cout`打印出的值为`Bellman-Ford`；如果运行的是Floyd算法，你要确保`cout`打印出的值为`Floyd`（都不包含回车或括号）。

### 浮点误差

如果`TValue`都是整型，那么没有什么难度。但实际上，`TValue`可能是浮点数，那就有可能导致判断时发生误判。

这个问题比较难，因此这里直接给出解决方案。

我们在比较误差时，可以采用一个模板$\epsilon$：

```c++
template<typename TValue>
TValue epsilon();
```

我们希望，当`TValue`是浮点数时，epsilon返回`1e-5`，其他情况，则返回`TValue()`。

如何判断`TValue`是不是浮点数呢？我们可以用到`<type_traits>`里的`is_floating_point`。

`is_floating_point<TValue>()`是一个特殊的函数，当`TValue`是浮点数时，返回值的类型是`true_type`，否则，则是`false_type`。

`true_type`和`false_type`是什么呢？

还记得我们在讲迭代器的时候，讲到迭代器有一个tag域，用来表示自己是什么样的迭代器，进而使用不同的函数调用吗？

`true_type`和`false_type`也是类似的！

既然`is_floating_point<TValue>`的返回类型会根据`TValue`的类型而变，那么，我们就可以写出这样的实现

```c++
template<typename TValue>
TValue epsilon() {
    return epsilon_real<TValue>(std::is_floating_point<TValue>());
}
```

然后，把两种情况的`epsilon_real`（偏特化模板）分别实现：

```c++
template<typename TValue>
TValue epsilon_real(std::true_type) {
    return 1e-5;
}

template<typename TValue>
TValue epsilon_real(std::false_type) {
    return TValue();
}
```

而`epsilon`函数的调用，就是简单的`epsilon<TValue>()`。

### 为什么负环难以定义

![Example](https://oj-solutions.njujb.com/2020-2/10/a/string_graph.png)

如上图，从1到3的最短路径是什么呢？$1\rightarrow 3$是`c`，按照字典序，似乎$1\rightarrow 2\rightarrow 3$的`ad`更小。

但是，$1\rightarrow 2\rightarrow 1\rightarrow 3$的`abc`按照字典序也小于`ad`。

因此，在本例中，1到3没有最短路。但是，如果把1到3和2到3的边换成空字符串或者`a`，最短路又出现了！

因此，我们难以给负环一个严格的定义。

此外，在Bellman-Ford中，我们也难以判断从起点出发不可达的环是否是负环，所以我们并不需要检查不可达的可能负环。



导致这一反直觉现象的原因，很可能是因为给定类型不一定满足$a\lt b \Leftrightarrow a+c\lt b+c$。

对于这个Lab，我们不再深入考虑太多东西了。

感兴趣的同学可以思考一下，如果我们在编写一个复杂的程序，里面实现了一个类型，它重载了加号、比较运算符等函数。如果我们期望它满足一些常见的算术性质，以确保大多数算法可以正常运行，我们该怎么办呢？

答案就是你们大一时候接触过的Coq。如果做这个Lab的过程中，你开始对如何保证程序正确性感兴趣，那么欢迎了解软件所的各个研究方向，或者了解程序语言中的相关知识。或者，单纯重温一下Coq也可以。

~~明明还不是最后一次Lab，为什么遣词造句都莫名煽情啊喂~~