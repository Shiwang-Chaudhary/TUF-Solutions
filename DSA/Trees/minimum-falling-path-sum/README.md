# [286. Minimum Falling Path Sum](https://takeuforward.org/practice/dsa/minimum-falling-path-sum)

![Difficulty: Unspecified](https://img.shields.io/badge/Difficulty-Unspecified-6b7280?style=for-the-badge)

---

## 📝 Problem Statement

Given a **2d** array called **matrix** consisting of **integer** values. Return the **minimum** path sum that can be obtained by **starting** at **any** cell in the **first** row and **ending** at **any** cell in the **last** row.

Movement is allowed only to the **bottom** , **bottom-right** , or **bottom-left** cell of the current cell.

### Example 1:

**Input:** matrix = [[1, 2, 10, 4], [100, 3, 2, 1], [1, 1, 20, 2], [1, 2, 2, 1]]

**Output:** 6

**Explanation:**

One optimal route can be:-

Start at 1st cell of 1st row -> bottom-right -> bottom -> bottom-left.

### Example 2:

**Input:** matrix = [[1, 4, 3, 1], [2, 3, -1, -1], [1, 1, -1, 8]]

**Output:** -1

**Explanation:**

One optimal route can be:-

Start at 4th cell of 1st row -> bottom-left -> bottom.

Still unsure what the problem is asking ?

Let’s go through a few more examples, step by step, to make it clearer.

### Constraints

- m == number of rows in matrix
- n == number of columns in matrix
- 1 <= n, m <= 100
- -1000 <= matrix[i][j] <= 1000
- The answer will not exceed 10^9

---

## 💡 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

<p align="center">
  Generated with ❤️ by <a href="https://github.com/Arora-Sir">Mohit Arora</a> &nbsp;|&nbsp; Practice on <a href="https://takeuforward.org/pricing?affiliate=arorasir">TakeUForward (TUF+)</a> &nbsp;|&nbsp; ⭐ <a href="https://github.com/Arora-Sir/TUFHub">Star TUFHub on GitHub</a>
</p>
