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

- Date solved: 2nd April 2019
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

## Cram Level 2

### [307. Range Sum Query Mutable](https://leetcode.com/problems/range-sum-query-mutable/)

- Date solved: 7th April 2019
- Difficulty: Medium
- Time taken: far too long...
- Attempts: 6+

I knew right away what I had to do, having seen a similar problem in my
previous competitive programming course. (a segment tree). But I couldn't
implement it to save my life. After a lot of false starts and dead ends, I
eventually managed to do it.

### [Counting Inversions](https://www.hackerrank.com/challenges/ctci-merge-sort/problem)

- Date solved: 
- Difficulty: Hard
- Time taken:
- Attempts:

### [212. Word Search II](https://leetcode.com/problems/word-search-ii/)

- Date solved: 
- Difficulty: Hard
- Time taken:
- Attempts:

### [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/)

- Date solved: 6 April 2019
- Difficulty: Medium
- Time taken: At least 90 minutes
- Attempts: 1

Performance:
  - Time: O(nlogn) 104ms
  - Space: O(n)

#### Problem description

> Given a char array representing tasks CPU need to do. It contains capital
> letters A to Z where different letters represent different tasks. Tasks could
> be done without original order. Each task could be done in one interval. For
> each interval, CPU could finish one task or just be idle.

> However, there is a non-negative cooling interval n that means between two
> same tasks, there must be at least n intervals that CPU are doing different
> tasks or just be idle.

> You need to return the least number of intervals the CPU will take to finish
> all the given tasks.

#### Solution

A greedy solution is sufficient here. We always choose to perform the task that
has the most tasks remaining, subject to it not being on cooldown. The problem
is of course how to know what task that is.

I knew I needed some sort of priority queue here. And I tried many different
approaches. My first approach was to have a single priority queue, but I
quickly realised that I had to globally modify all the elements at once in
order to "tick down" the cooldown. On a priority queue, there's no way to do
that quickly.

After looking at some of the solutions, I decided to use *two* priority queues:
one, `task_queue`, that holds tasks ready to be performed (most amount first),
and two, `waiting_queue`, which holds tasks on cooldown (lowest cooldown first)
I also keep a `time` counter.  At every period, I check the top element of
`waiting_queue` and push it into the task queue if its cooldown has elapsed.
Then, I pop the top element of `task_queue`, decrement its `amount`, and
increase its `cooldown` by `n`. If its amount <= 0, the task type is done;
otherwise, I push it into waiting_queue.

The algorithm was easy, but the specific implementation is not. I took so long
due to going down the wrong path by trying to use one priority queue.

### [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

- Date solved: 6th April 2019
- Difficulty: Medium
- Time taken: 30 minutes
- Attempts: 1

- Performance:
  - Time: O(nlogn) 8ms
  - Space: O(n)

1. Sort the intervals in lexicographic order.
2. Maintain a pointer, pointing it to the start of the array.
3. Iterate through the intervals.
  - If 2nd interval does not overlap with the interval pointed to, move the
    left pointer to the second interval.
  - If 2nd interval overlaps with the first, num_intervals ++;
4. Return num_intervals.

Lexicographic order is very helpful here. 

Learned you can define comparator functions as lambda functions and put them in `int main`:

```cpp
int main() {
  auto cmp = [](Interval &a, Interval b) { return a.first < b.first };
  ... // rest of the function here
}
```

