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
        queue<int> q;
        if (graph->ContainsVertex(start))
        {
            q.emplace(start);
            vis.emplace(start);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                action(cur);
                for (int u : graph->GetNeighbors(cur))
                {
                    if (!vis.count(u))
                    {
                        q.emplace(u);
                        vis.emplace(u);
                    }
                }
            }
        }
    };
    static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate)
    {
        set<int> vis;
        queue<int> q;
        if (graph->ContainsVertex(start))
        {
            q.emplace(start);
            vis.emplace(start);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                if (predicate(cur))
                    return cur;
                for (int u : graph->GetNeighbors(cur))
                {
                    if (!vis.count(u))
                    {
                        q.emplace(u);
                        vis.emplace(u);
                    }
                }
            }
        }
        return std::nullopt;
    };
};

#endif
