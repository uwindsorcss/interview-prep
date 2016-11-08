#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>

template <typename T>
class Graph {
	std::map<T, std::set<T>> g;
public:
	void addEdge(T a, T b) {
		g[a].insert(b);
	}
	void removeEdge(T a, T b) {
		g[a].insert(b);
	}

	std::vector<T> toposort() {
		std::set<T> visited;
		std::vector<T> result;

		for(auto const& v : g) {
			if(visited.find(v.first) == visited.end())
				dfs(visited, v.first, result);
		}
		return result;
	}
	void dfs(std::set<T>& visited, const T& v, std::vector<T>& result) {
		visited.insert(v);
		for(auto const& e : g[v]) {
			if(visited.find(e) == visited.end()) {
				dfs(visited, e, result);
			}
 		}
		result.push_back(v);
	}

	void bfs(graph<T> g, T start) {
		std::queue<T> q;
		std::set<T> seen;

		q.push(start);
		while(!q.empty()) {
			auto t = q.front();
			q.pop();

			for(auto const& i : g[t]) {
				auto check = seen.insert(i);
				if(check.second)
					q.push(i);
			}
		}
	}
};

int main() {
	int n;
	Graph<std::string> g;
	std::string a, b;

	std::cin >> n;
	while(n-- > 0) {		
		std::cin >> a >> b;
		g.addEdge(a,b);
	}

	auto const& result = g.toposort();
	
	for(auto const& e : result) {
		std::cout << e << ' ';
	}
	std::cout << std::endl;
};
