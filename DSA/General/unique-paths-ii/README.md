# [257. Unique paths II](https://takeuforward.org/practice/dsa/unique-paths-ii)

![Difficulty: Unspecified](https://img.shields.io/badge/Difficulty-Unspecified-6b7280?style=for-the-badge)

---

## 📝 Problem Statement

Given an m x n 2d array named matrix, where each cell is either 0 or 1. Return the number of **unique ways** to go from the top-left cell (matrix[0][0]) to the bottom-right cell (matrix[m-1][n-1]). A cell is blocked if its value is 1, and no path is possible through that cell.

Movement is allowed in only two directions from a cell - **right** and **bottom** .

### Example 1:

**Input:** matrix = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]

**Output:** 2

**Explanation:**

The two possible paths are:

1) down -> down-> right -> right

2) right -> right -> down -> down

### Example 2:

**Input:** matrix = [[0, 0, 0], [0, 0, 1], [0, 1, 0]]

**Output:** 0

**Explanation:**

There is no way to reach the bottom-right cell.

Still unsure what the problem is asking ?

Let’s go through a few more examples, step by step, to make it clearer.

### Constraints

- m == number of rows in matrix
- n == number of columns in matrix
- 1 <= n, m <= 100
- Value of each cell in matrix is either 0 or 1
- The answer will not exceed 10^9

---

## 💡 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

<p align="center">
  Generated with ❤️ by <a href="https://github.com/Arora-Sir">Mohit Arora</a> &nbsp;|&nbsp; Practice on <a href="https://takeuforward.org/pricing?affiliate=arorasir">TakeUForward (TUF+)</a> &nbsp;|&nbsp; ⭐ <a href="https://github.com/Arora-Sir/TUFHub">Star TUFHub on GitHub</a>
</p>
