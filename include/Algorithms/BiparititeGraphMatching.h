#ifndef GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#define GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#include <unordered_set>
#include <optional>

template<typename TGraph>
class BipariteGraphMatching {
public:
    BipariteGraphMatching(const TGraph* g, std::unordered_set<int> left, std::unordered_set<int> right);
    int SumOfMatches() const;
    std::optional<int> FindMatchOf(int idx) const;
};

#endif //GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
