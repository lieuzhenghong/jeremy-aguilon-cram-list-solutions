class Solution {
public:
    map<int, pair<int, int>> graph;
    set<int> islands;
    
    // while leader doesn't point to itself,
    // traverse until we point to a leader
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
        //cout << "Joining " << i << " and " << j << endl;
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
        
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int idx = j + (i*width);
                graph[idx] = make_pair(idx, int(grid[i][j]) - 48);
            }
        }

        
        if (height == 1)
        {          
            // iterate through the grid, and join them if they are both land
            
            for (int i = 0; i < width-1; i++)
            {
                // compare the two of them and join them together if they are both land
                
                if (graph[i].second == 1 && graph[i+1].second == 1)
                {
                    join(i, i+1);
                    flatten(i, i+1);
                }
            }
        }
        
        else
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    // compare all four neighbours and join all land neighbours
                    int idx = j + (i*width);
                    int top = j + (i-1)*width;
                    int bot = j + (i+1)*width;
                    int left = j + (i*width) - 1;
                    int right = j + (i*width) + 1;
                    
                    if (grid[i][j] == 49)
                    {
                        if (j < width -1)
                        {
                            if (grid[i][j+1] == 49)
                            {
                                //cout << "Joining right" << endl;
                                join(idx, right);
                                flatten(idx, right);
                            }
                        }
                        if (i < height - 1 && grid[i+1][j] == 49)
                        {
                            //cout << "Joining bottom" << endl;
                            join(idx, bot);
                            flatten(idx, bot);
                        }
                    }
                }
            }
        }
        
        
        // count the number of islands
            
        for (auto &it : graph) 
        {
            int key = it.first, value1 = it.second.first, value2 = it.second.second;
            //cout << key << " " << value1 << " " << value2 << endl;
            flatten(value1, key);
        }
        for (auto &it : graph) 
        {
            int key = it.first, value1 = it.second.first, value2 = it.second.second;
            //cout << key << " " << value1 << " " << value2 << endl;
        
            if (value2) islands.insert(value1);
        }
        return islands.size(); 
        
    }
};
