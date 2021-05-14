#ifndef GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#define GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#include <unordered_set>
#include <optional>
#include <map>

template <typename TGraph>
class BipariteGraphMatching
{
private:
    map<int, bool> used;
    map<int, int> belong;
    int max_matches;
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
                if (belong.find(y) == belong.end() || find(belong.find(y)))
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
            max_matches = 0;
            L = left;
            R = right;
            for (auto v : left)
            {
                if (right.find(v) != right.end)
                    throw std::invalid_argument;
            }

            for (auto v : left)
            {
                if (!g->ContainsVertex(v))
                    throw std::invalid_argument;
            }
            for (auto v : right)
            {
                if (!g->ContainsVertex(v))
                    throw std::invalid_argument;
            }

                        for (auto v : left)
            {
                used.clear();
                if (find(g, v))
                    max_matches++;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    };
    int SumOfMatches() const
    {
        return max_matches;
    };
    std::optional<int> FindMatchOf(int idx) const
    {
        if (belong.find(idx) != belong.end())
            return belong[idx];
        return std::nullopt;
    };
};

#endif //GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
