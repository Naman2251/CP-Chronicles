"""
Problem: C. Robin Hood in Town
Link: https://codeforces.com/contest/2014/problem/C

Short Problem Statement:
There are n people with given wealth.
The richest person finds extra gold.
A person is unhappy if their wealth is less than half of the average.
Find the minimum gold required so that more than half the population becomes unhappy.

Approach:
- If n <= 2, it is impossible.
- Sort the wealth array.
- To make strictly more than n/2 people unhappy, it is sufficient to
  make the person at index n//2 unhappy (0-based).
- Derive the inequality directly and compute the minimum required gold.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Example:
Input:
4
1 2 3 4

Output:
15

Submission Link:
https://codeforces.com/contest/2014/submission/356103335
"""

import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    if n <= 2:
        print(-1)
        continue

    a.sort()
    total = sum(a)

    k = n // 2
    x = 2 * n * a[k] - total + 1

    print(max(0, x))
