#include <boost/config.hpp>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/graph_traits.hpp>
using namespace boost;


int main()
{
//###############################################################################/
//graph_traits
//##vertex
//typedef typename graph_traits < Graph >::vertices_size_type size_type;
//typedef typename boost::graph_traits<Graph>::vertex_iterator    Viter;
//graph_traits < graph_t >::vertex_descriptor u = add_vertex(g);
//##edge
//typedef 	typename 	boost::graph_traits<Graph>::out_edge_iterator OutEdgeIter;
//typedef 	typename 	boost::graph_traits<Graph>::in_edge_iterator InEdgeIter;
//			typename 	boost::graph_traits<Graph>::edge_iterator ei, ei_end;
//typedef     		 	boost::graph_traits<graph_t>::edge_descriptor edge_descriptor;
//
//##
 

//###############################################################################/ 
//property_map  and put. get.
//typename property_map<Graph, edge_mycapacity_t>::const_type  flow = get(edge_myflow, G);
//###############################################################################
//typedef adjacency_list < listS, listS, directedS, property < vertex_index_t, std::size_t, property< vertex_name_t, std::string > >  >graph_t;
// property_map < GRAPH, vertex_index_t >::type index_map =get(vertex_index, g);
// property_map < GRAPH, vertex_name_t >::type  name_map  =get(vertex_name, g);
//	boost::put(name_map, 0, "Jeremy");
//	boost::put(name_map, 1, "Rich");
//	boost::put(name_map, 2, "Andrew");
//	boost::put(name_map, 3, "Jeff");
//	name[4] = "Kinis"; // you can use operator[] too
//	name[2] = string(MString<char>("wenshuna").c_str());
//	boost::put(name_map, 5, "wenshuna");
//
//###############################################################################/



//###############################################################################/
//graph defined 定义的时候， 第二个最好是vecS ， 随机存储。 
//typedef adjacency_list < listS,listS,vecS,directedS,property < vertex_name_t, std::string > >graph_type;
//typedef adjacency_list < listS,std::list,vecS,directedS,property < vertex_name_t, std::string > >graph_type;
//typedef adjacency_list < listS, listS, directedS, property < vertex_index_t, std::size_t, property< vertex_name_t, std::string > >  >graph_t;
//typedef adjacency_list < vecS, vecS, directedS,property < vertex_name_t, string > > graph_t;
//typedef adjacency_list<> 			GRAPH;
//typedef adjacency_list<vecS,vecS,bidirectionalS> Graph;
//
//
typedef adjacency_list<vecS, vecS, directedS, property<vertex_name_t, std::string> > GRAPH;

//typedef adjacency_list < property < vertex_name_t, std::string > >graph_type;
//graph_type g;
GRAPH g;
property_map < GRAPH, vertex_name_t >::type name_map =get(vertex_name, g);



}

