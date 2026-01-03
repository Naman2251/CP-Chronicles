"""
Approach:
For each power r (2 to 64):
- Calculate k ≈ n^(1/r)
- Check if 1 + k + k² + ... + k^r = n
- Verify k-1, k, k+1 for floating point precision

Submission Link: https://codeforces.com/contest/1846/submission/356143831
"""

def solve():
    n = int(input())
    
    if n < 3:
        print("NO")
        return
    
    for r in range(2, 65):
        k = int(n ** (1.0 / r))
        
        for candidate_k in [max(2, k - 1), k, k + 1]:
            if candidate_k < 2:
                continue
            
            total = 1
            power = 1
            
            for i in range(r):
                power *= candidate_k
                total += power
                if total > n:
                    break
            
            if total == n:
                print("YES")
                return
        
        if k < 2:
            break
    
    print("NO")

t = int(input())
for _ in range(t):
    solve()