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

private:
    bool find(const TGraph *g, int x)
    {
        for (auto e : g->GetOutgoingEdges(x))
        {
            int y = e.GetDestination();
            if (used.find(y) == used.end())
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

    void hungarian(){

    };

public:
    BipariteGraphMatching(const TGraph *g, std::unordered_set<int> left, std::unordered_set<int> right)
    {
        max_matches = 0;
        for (auto v : left)
        {
            used.clear();
            if (find(g, v))
                max_matches++;
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
