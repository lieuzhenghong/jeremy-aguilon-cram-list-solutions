These are my solutions to Jeremy Aguilon's [Ranking Interview Questions by Cram Score](https://jeremyaguilon.me/blog/ranking_interview_questions_by_cram_score)

Goals: do every question in 30 minutes without needing to Google for syntax

## Cram Level 1

### Number of Islands

- Date solved: 1st April 2019
- Time taken: 2 hours
- Comments: Very rusty; hadn't touched C++ (or indeed done
any coding!) since August 2018. At least I still remembered my algorithms knowledge from Tim Roughgarden's excellent course: wrote out an implementation of Union-Find.

### Coin Change Problem

- Date solved: 1st April 2019
- Time taken: ~45 minutes
- Difficulty: Medium
- Comments: Still rusty. But this was easier because I knew how the recurrence relation worked; difficulty was handling the edge cases.
- Syntax I learned:
```cpp
	*min_element(v.begin(), v.end())
	#include <limits.h>
	INT_MAX
```

### [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)

- Date solved: 1st April 2019
- Time taken: ~50 minutes
- Difficulty: Hard
- Attempts: 3
- Comments: I got the algorithm right away but got bitten by (not so) corner
  cases: empty inputs, duplicated letters and so on. In the future, I will
  make sure to test with corner cases to make sure I 

- Syntax I learned:
```cpp
map.count()
string.substr(pos, len);
```

### [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

- Date solved: 1st April 2019
- Time taken: ~15 minutes
- Difficulty: Easy
- Attempts: 1
- Comments: Got it to work first time through---easy greedy
  solution.
