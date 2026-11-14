# [Count Square Submatrices with All Ones](https://takeuforward.org/practice/dsa/count-square-submatrices-with-all-one)

![Difficulty: Unspecified](https://img.shields.io/badge/Difficulty-Unspecified-6b7280?style=for-the-badge)

---

## 📝 Problem Statement

You are given a binary matrix matrix containing only 0s and 1s.

Your task is to find the total number of square submatrices that contain only 1s.

A square submatrix can have any valid size, such as 1 × 1, 2 × 2, 3 × 3, and so on. Each square is counted separately based on its position in the matrix.

Return the total number of such square submatrices.

### Example 1:

**Input:** matrix = [ [1, 1, 1], [1, 1, 1], [0, 1, 1] ]

**Output:** 11

**Explanation:**

There are:

- 8 squares of size 1 × 1
- 3 squares of size 2 × 2
- 0 squares of size 3 × 3

Therefore: 8+3 =11

### Example 2:

**Input:** matrix = [ [1, 0, 1, 1], [1, 1, 1, 1], [1, 1, 1, 0] ]

**Output:** 13

**Explanation:**

There are 10 individual 1 × 1 squares.

There is also 3 square of size 2 × 2.

So total count is 13.

Still unsure what the problem is asking ?

Let’s go through a few more examples, step by step, to make it clearer.

### Constraints

- 1 <= matrix.length <= 300
- 1 <= matrix[0].length <= 300
- 0 <= matrix[i][j] <= 1

---

## 💡 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

<p align="center">
  Generated with ❤️ by <a href="https://github.com/Arora-Sir">Mohit Arora</a> &nbsp;|&nbsp; Practice on <a href="https://takeuforward.org/pricing?affiliate=arorasir">TakeUForward (TUF+)</a> &nbsp;|&nbsp; ⭐ <a href="https://github.com/Arora-Sir/TUFHub">Star TUFHub on GitHub</a>
</p>
