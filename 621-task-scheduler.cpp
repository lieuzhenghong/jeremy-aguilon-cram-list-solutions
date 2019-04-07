class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        struct Task {
            int cooldown = 0;
            int amount = 0;
        };
        
        auto cmp = [](Task &a, Task &b) {
                return a.amount < b.amount;
        };
        
        auto cd_cmp = [](Task &a, Task &b) {
            return a.cooldown > b.cooldown;
        };
        
        map<char, Task> ts;
        priority_queue<Task, vector<Task>, decltype(cmp)> pq(cmp);
        priority_queue<Task, vector<Task>, decltype(cd_cmp)> waiting_q(cd_cmp);
        
        for (auto &t: tasks) {
            ts[t].amount += 1; 
        }
        
        for (auto &e : ts) {
            pq.push(e.second);
        }
        
        int time = 0;
        
        while (pq.size() || waiting_q.size()) {
            if (waiting_q.size()) {
                auto tmp = waiting_q.top();
                    if (tmp.cooldown < time) {
                        waiting_q.pop();
                        pq.push(tmp);
                    }
            }
            
            // take the first element of pq and increment it
            if (pq.size()) {
                auto tmp = pq.top();
                pq.pop();
                tmp.cooldown = time + n;
                tmp.amount--;
		// if finished task, then ignore
                if (tmp.amount > 0) {
                    waiting_q.push(tmp);
                }
            }
            time++;
        }
        
        return time;
    }
};
