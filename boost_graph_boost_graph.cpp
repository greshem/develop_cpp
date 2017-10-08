#include <vector>
#include <list>
#include <iostream> // needed by graph_utility. -Jeremy
#include <boost/graph/vector_as_graph.hpp>
#include <boost/graph/graph_utility.hpp>

int
main()
/* [<][>][^][v][top][bottom][index][help] */
{
  enum
  { r, s, t, u, v, w, x, y, N };
  char name[] = "rstuvwxy";
  typedef std::vector < std::list < int > > Graph;
  Graph g(N);
  g[r].push_back(v);
  g[s].push_back(r);
  g[s].push_back(r);
  g[s].push_back(w);
  g[t].push_back(x);
  g[u].push_back(t);
  g[w].push_back(t);
  g[w].push_back(x);
  g[x].push_back(y);
  g[y].push_back(u);
  boost::print_graph(g, name);
  return 0;
}
