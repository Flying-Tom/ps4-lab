#ifndef GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#define GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#include <unordered_set>
#include <optional>
#include <unordered_map>
#include <map>

template <typename TGraph>
class BipariteGraphMatching
{
private:
    mutable std::map<int, bool> used;
    mutable std::map<int, int> belong;
    mutable std::map<int, int> rec;
    int matches_sum;
    std::unordered_set<int> L, R;

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

public:
    BipariteGraphMatching(const TGraph *g, std::unordered_set<int> left, std::unordered_set<int> right)
    {
        try
        {
            matches_sum = 0;
            L = left;
            R = right;
            for (auto v : left)
            {
                if (right.find(v) != right.end())
                    throw std::invalid_argument("There exists an intersection between left and right!");
            }

            for (auto x : left)
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
            for (auto x : right)
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

            for (auto v : L)
            {
                used.clear();
                if (find(g, v))
                    matches_sum++;
            }

            for (auto p : belong)
            {
                rec[p.first] = p.second;
                rec[p.second] = p.first;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    };
    int SumOfMatches() const
    {
        return matches_sum;
    };
    std::optional<int> FindMatchOf(int idx) const
    {
        if (L.find(idx) == L.end() && R.find(idx) == R.end())
            return std::nullopt;
        if (rec.find(idx) == rec.end())
            return std::nullopt;
        return rec[idx];
    };
};

#endif //GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
