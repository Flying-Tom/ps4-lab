#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>

template <typename TGraph>
class MultiSourceShortestPaths {
 public:
  MultiSourceShortestPaths() = delete;
  explicit MultiSourceShortestPaths(const TGraph *graph);
  virtual ~MultiSourceShortestPaths();
 public:
  bool HasPathTo(int source, int destination) const;
  std::optional<TValue> TryGetDistanceTo(int source, int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathTo(int source, int destination) const;
};

#endif
