#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <set>
#include <stack>

template <typename TGraph>
class DepthFirstSearcher
{
public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action)
    {
        set<int> vis;
        stack<int> s(start);
        if (graph->ContainsVertex(start))
        {
            while (!s.empty())
            {
                int cur = s.top();
                s.pop();
                action(cur);
                vis.emplace(cur);
                for (int u : graph->GetNeighbors(cur))
                {
                    if (!vis.count(u))
                        s.emplace(u);
                }
            }
        }
    };
    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate)
    {
        set<int> vis;
        stack<int> s(start);
        if (graph->ContainsVertex(start))
        {
            while (!s.empty())
            {
                int cur = s.top();
                s.pop();
                if (predicate(cur))
                    return cur;
                vis.emplace(cur);
                for (int u : graph->GetNeighbors(cur))
                {
                    if (!vis.count(u))
                        s.emplace(u);
                }
            }
        }
        return std::nullopt;
    };
};

#endif
