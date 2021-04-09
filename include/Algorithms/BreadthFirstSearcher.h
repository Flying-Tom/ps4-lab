#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>

template <typename TGraph>
class BreadthFirstSearcher {
 public:
  static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action);
  static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);
};

#endif
