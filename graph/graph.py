class graph:
    def __init__(self):
        self._adj_map = dict()

    def connect(self, fro, to):
        edges = self._adj_map.setdefault(fro, set())
        edges.add(to)
        self._adj_map.setdefault(to, set())

    def disconnect(self, fro, to):
        edges = self._adj_map.get(fro, set())
        edges.discard(to)

    def connect_bidirectional(self, a, b):
        self.connect(a, b)
        self.connect(b, a)

    def get_adjacent(self, node):
        # dict's get method returns the value for key node if it exists,
        # or returns the second argument otherwise.
        # Unlike the setdefault method it does not then set the second argument
        # as the value of the key for the dict.
        return self._adj_map.get(node, set())

    def get_topo_sorted_list(self):
        stack = list()
        marked = set()

        def _visit(node):
            if node not in marked:
                for neighbour in self.get_adjacent(node):
                    _visit(neighbour)
                marked.add(node)
                stack.append(node)

        for node, neigbours in self._adj_map.items():
            if node not in marked:
                _visit(node)

        return stack

if __name__ == "__main__":
    # Stuff in here would only be run if the script was
    # called as an executable, and not if it was imported as a library.
    # This can be useful as a place to have tests for a library.
    g = graph()

    g.connect(5, 11)
    g.connect(7, 11)
    g.connect(7, 8)
    g.connect(3, 8)
    g.connect(3, 10)
    g.connect(11, 2
    g.connect(11, 9)
    g.connect(11, 10)
    g.connect(8, 9)

    for node in g.get_topo_sorted_list():
        print(node)
