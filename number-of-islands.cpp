class Solution {
public:
    map<int, pair<int, int>> graph;
    set<int> islands;
    
    // while leader doesn't point to itself,
    // traverse (by leader) until we reach a node that points to itself
    int get_root(int i)
    {
        if (graph[i].first == i)
        {
           return i;
        }
        else {
            return get_root(graph[i].first);
        }
    }
    
    // get the roots and point b to a
    void join(int i, int j)
    {
        int a = get_root(i);
        int b = get_root(j);
        graph[b].first = a;
    }
    
    // point the leaf node j directly to the leader of i
    // essentially flattening the graph
    void flatten(int i, int j)
    {
        graph[j].first = get_root(i);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int height = grid.size();
        
        if (height == 0)
        {
            return 0;
        }
        
        int width = grid[0].size();
        
        // First flatten the 2D array into a map
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int idx = j + (i*width);
                graph[idx] = make_pair(idx, int(grid[i][j]) - 48);
            }
        }

        // Iterate over all cells and join neighbours together
        // (point B's leader to A's leader) if they are both land cells.
        
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // compare all four neighbours and join all land neighbours
                // i realise don't compare all four neighbours; only compare bottom
                // and right will cover all already. Otherwise we might actually
                // break the SCC
                
                int idx = j + (i*width);
                int bot = j + (i+1)*width;
                int right = j + (i*width) + 1;
                    
                if (grid[i][j] == 49)
                {
                    if (j < width -1 && grid[i][j+1] == 49)
                    {
                        join(idx, right);
                        flatten(idx, right);
                    }
                    if (i < height - 1 && grid[i+1][j] == 49)
                    {
                        join(idx, bot);
                        flatten(idx, bot);
                    }
                }
            }
        }
        
        // count the number of islands
        // First flatten all the nodes of the graph    
        for (auto &it : graph) 
        {
            int key = it.first, value1 = it.second.first;
            flatten(value1, key);
        }
        // Then, count the number of unique leaders
        for (auto &it : graph) 
        {
            int value1 = it.second.first, value2 = it.second.second;        
            if (value2) islands.insert(value1);
        }
        return islands.size(); 
    }
};
