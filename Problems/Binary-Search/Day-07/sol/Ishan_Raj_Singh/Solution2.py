"""
Approach: Optimized Sliding Window with Divisor Enumeration
Submission Link: https://codeforces.com/contest/1777/submission/356144999
"""

def solve_optimized():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    
    students = []
    for val in a:
        divisors = []
        i = 1
        while i * i <= val:
            if val % i == 0:
                if i <= m:
                    divisors.append(i)
                if i != val // i and val // i <= m:
                    divisors.append(val // i)
            i += 1
        
        if divisors:
            students.append((val, divisors))
    
    if not students:
        print(-1)
        return
    
    students.sort()
    
    left = 0
    ans = float('inf')
    freq = {}
    
    for right in range(len(students)):
        for topic in students[right][1]:
            freq[topic] = freq.get(topic, 0) + 1
        
        while len(freq) == m:
            ans = min(ans, students[right][0] - students[left][0])
            
            remove_ok = True
            for topic in students[left][1]:
                if freq.get(topic, 0) == 1:
                    remove_ok = False
                    break
            
            if remove_ok:
                for topic in students[left][1]:
                    freq[topic] -= 1
                    if freq[topic] == 0:
                        del freq[topic]
                left += 1
            else:
                break
    
    print(ans if ans != float('inf') else -1)

t = int(input())
for _ in range(t):
    solve_optimized()