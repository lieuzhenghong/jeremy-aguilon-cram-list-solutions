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

### [303. Range Sum Query --- Immutable](https://leetcode.com/problems/range-sum-query-immutable/submissions/)

- Date solved: 2nd April 2019
- Time taken: 90 minutes (but actually 10 minutes --- see my comments)
- Attempts: 1

- Comments: I found the O(n) solution right away. Given that the array does not
  change, we notice that 

  $$sum(i, j) = sum(j,0) - sum(i-1,0)$

  So we simply generate an array where the i-th element is the sum up to i
  inclusive.

  However, I spent more than an hour debugging because my code kept throwing a cryptic error:

  `solution.cpp: In static member function 'static NumArray* DriverSolution::helperConstructor(const string&, const std::vector<std::__cxx11::basic_string<char> >&)':
Line 55: Char 41: error: cannot bind non-const lvalue reference of type 'std::vector<int>&' to an rvalue of type 'std::vector<int>'`

  I had no idea what was going on. I deleted all my code but it still didn't
  compile. I was completely lost. Luckily Wei Heng is much smarter than me and
  realised that there was actually a problem with the **stub code**. You can
  see the problem
  [here](https://leetcode.com/problems/range-sum-query-immutable/discuss/265043/c%2B%2B-template-remove-reference-on-vector).

### [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)

- Date solved: 2nd April 2019
- Difficulty: Medium
- Time taken: 25 minutes (1510-1535)
- Attempts: 1

- Comments: Not too difficult. I am now more careful in checking edge cases. I
  actually caught something before I ran it, which is great!

  What I managed to catch: After sorting the intervals, I wrote this:
  
```cpp
if (new_intervals.back().end < iv.start) // start a new interval if there is no overlap
{
    new_intervals.push_back(iv);
}
else
{
    new_intervals.back().end = iv.end;
}
```

But this is wrong. Specifically, what if `iv.end` is less than
`new_intervals.back().end`? The test cases given didn't catch this, luckily I
did. This is of course rather trivial, but it's good that I am becoming more
careful. I also made sure to test (and write code to handle) empty vectors.

- Syntax I (re)learned:
custom comparator function (must return boolean)

Without lambdas:
```cpp
bool cmp(Interval &a, Interval &b) {
    return a.start < b.start;
}

sort(intervals.begin(), intervals.end(), cmp)
```

With lambda functions:
```cpp
sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

```

### [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

- Difficulty: Easy
- Time taken: 15 minutes (1550-1606)
- Attempts: 1

- Performance:
  - Time: O(n). 8ms > 99.48% of C++ solutions
  - Space: O(1). 9.1MB < 99.75 of C++ solutions

Easy question. Again, managed to catch wrong behaviour before I ran it.

No new syntax. But learning it's good to define a utility function `max`: has been quite helpful.
```cpp
int max (int a, int b) {
   return (a > b) ? a : b;
}
```
