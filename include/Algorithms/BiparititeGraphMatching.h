#ifndef GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#define GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#include <unordered_set>
#include <unordered_map>
#include <optional>
#include <map>

template <typename TGraph>
class BipariteGraphMatching
{
private:
    std::unordered_set<int> L, R;
    mutable std::map<int, bool> used;
    mutable std::map<int, int> belong;
    int matches_sum;

private:
    bool find(const TGraph *g, int x)
    {
        for (auto e : g->GetOutgoingEdges(x))
        {
            int y = e.GetDestination();
            if (R.find(y) != R.end() && used.find(y) == used.end())
            {
                used[y] = true;
                if (belong.find(y) == belong.end() || find(g, belong[y]))
                {
                    belong[y] = x;
                    return true;
                }
            }
        }
        return false;
    }
    void check()
    {
        for (auto v : L)
        {
            if (R.find(v) != R.end())
                throw std::invalid_argument("There exists an intersection between left and right!");
        }

        for (auto x : L)
        {
            if (!g->ContainsVertex(x))
                throw std::invalid_argument("Left set has unexpected point!");
            std::vector<int> temp = g->GetNeighbors(x);
            for (auto y : temp)
            {
                if (R.find(y) == R.end())
                    throw std::invalid_argument("A point in Left connects to unexpected point!");
            }
        }
        for (auto x : R)
        {
            if (!g->ContainsVertex(x))
                throw std::invalid_argument("Right set has unexpected point!");
            std::vector<int> temp = g->GetNeighbors(x);
            for (auto y : temp)
            {
                if (L.find(y) == L.end())
                    throw std::invalid_argument("A point in Right connects to unexpected point!");
            }
        }
    }

public:
    BipariteGraphMatching(const TGraph *g, std::unordered_set<int> left, std::unordered_set<int> right)
    {
        matches_sum = 0;
        L = left;
        R = right;
        check();
        for (auto v : L)
        {
            used.clear();
            if (find(g, v))
                matches_sum++;
        }

        for (auto p : belong)
        {
            belong[p.first] = p.second;
            belong[p.second] = p.first;
        }
    };
    int SumOfMatches() const
    {
        return matches_sum;
    };
    std::optional<int> FindMatchOf(int idx) const
    {
        if ((L.find(idx) == L.end() && R.find(idx) == R.end()) || belong.find(idx) == belong.end())
            return std::nullopt;
        return belong[idx];
    };
};

#endif //GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
