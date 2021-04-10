#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <set>
#include <queue>

template <typename TGraph>
class BreadthFirstSearcher
{
public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action)
    {
        set<int> vis;
        queue<int> q{start};
        if (graph->ContainsVertex(start))
        {
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                action(cur);
                vis.emplace(cur);
                for (int u : graph->GetNeighbors(cur))
                {
                    if (!vis.count(u))
                        q.emplace(u);
                }
            }
        }
    };
    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate)
    {
        set<int> vis;
        queue<int> q{start};
        if (graph->ContainsVertex(start))
        {
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                if (predicate(cur))
                    return cur;
                vis.emplace(cur);
                for (int u : graph->GetNeighbors(cur))
                {
                    if (!vis.count(u))
                        q.emplace(u);
                }
            }
        }
        return std::nullopt;
    };
};

#endif
