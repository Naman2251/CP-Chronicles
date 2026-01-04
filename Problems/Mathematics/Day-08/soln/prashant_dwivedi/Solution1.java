import java.util.*;
import java.io.*;

public class Solution1 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {

            String[] first = br.readLine().split(" ");
            int n = Integer.parseInt(first[0]);
            int k = Integer.parseInt(first[1]);

            long[] a = new long[n];
            String[] arr = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(arr[i]);
            }

            Arrays.sort(a);

            int m = n - k;
            int mid = (m - 1) / 2;

            long left = a[mid];
            long right = a[n - 1 - mid];

            System.out.println(right - left + 1);
        }
    }
}

/*
-------------------- SIMPLE DOCUMENTATION --------------------

What this code does:
- Reads positions of bars on a street
- Allows closing at most k bars
- Finds how many house positions can give minimum total distance

Core idea:
- To minimize distance, always remove the farthest bars
- After removing k bars, only (n - k) bars matter
- The best position is always at the median

Why sorting:
- Makes it easy to remove farthest bars
- Helps find the median range directly

How answer is computed:
- Find the valid median range [left, right]
- Every integer in this range gives the same minimum distance
- Count = right - left + 1

Time Complexity:
- O(n log n) due to sorting

Submission:
https://codeforces.com/contest/2098/submission/356145066
----------------------------------------------------------
*/
