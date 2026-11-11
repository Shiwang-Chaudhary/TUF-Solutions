# [17. Grid unique paths](https://takeuforward.org/practice/dsa/grid-unique-paths)

![Difficulty: Unspecified](https://img.shields.io/badge/Difficulty-Unspecified-6b7280?style=for-the-badge)

---

## 📝 Problem Statement

Given two integers m and n, representing the number of rows and columns of a 2d array named matrix. Return the number of **unique ways** to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]).

&nbsp;Movement is allowed only in two directions from a cell: **right** and **bottom** .

### Example 1:

**Input:** m = 3, n = 2

**Output:** 3

**Explanation:**

There are 3 unique ways to go from the top left to the bottom right cell.

1) right -> down -> down

2) down -> right -> down

3) down -> down -> right

### Example 2:

**Input:** m = 2, n = 4

**Output:** 4

**Explanation:**

There are 4 unique ways to go from the top left to the bottom right cell.

1) down -> right -> right -> right

2) right -> down -> right -> right

3) right -> right -> down -> right

4) right -> right -> right -> down

Still unsure what the problem is asking ?

Let’s go through a few more examples, step by step, to make it clearer.

### Constraints

- 1 <= n, m <= 100
- The answer will not exceed 10^9

---

## 💡 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

<p align="center">
  Generated with ❤️ by <a href="https://github.com/Arora-Sir">Mohit Arora</a> &nbsp;|&nbsp; Practice on <a href="https://takeuforward.org/pricing?affiliate=arorasir">TakeUForward (TUF+)</a> &nbsp;|&nbsp; ⭐ <a href="https://github.com/Arora-Sir/TUFHub">Star TUFHub on GitHub</a>
</p>
