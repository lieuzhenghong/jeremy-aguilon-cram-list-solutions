class Solution {
public:
    
    string minWindow(string s, string t) {
        int l_best_window = INT_MAX;
        string best_window = "";
        map<char, int> letters_used;
        map<char, int> letters_in_t; 
        int l=0, r = 0; //technically should be pointers
        
        for (char &c: t)
        {
            letters_used[c] = 0;
            letters_in_t[c]++;
        }
        
        for (int i = 0; i < s.length(); i++)
        {
            char a = s[r];
            r++;
            
            if (letters_used.count(a)) letters_used[a]++;
            
            // now move the left iterator 
            for (int j = l; j <= r; j++)
            {
                if (letters_used.count(s[j]))
                {
                    if (letters_used[s[j]] > letters_in_t[s[j]])
                    {
                        //cout << "Detected extra letter: " << s[j] << ": " << letters_used[s[j]] << endl;
                        letters_used[s[j]]--;
                        continue;
                    }
                    else 
                    {
                        //cout << "Looking at letter: " << s[j] << endl;
                        l = j;
                        break;    
                    }
                    
                }
                l = j;
            }
            
            // Now check if all letters are included
            // If all letters are 1, then we have
            // a window.
            
            // NOT if all 
            bool is_window = true;
            for (auto &k: letters_used)
            {
                if (k.second < letters_in_t[k.first])
                {
                    is_window = false;
                    break;
                }
            }
            if (is_window) 
            {
                if (r-l < l_best_window)
                {
                    l_best_window = r-l;
                    best_window = s.substr(l,r-l);
                }
            }
        }
        
        return best_window;
    }
};
