# [99. House robber](https://takeuforward.org/practice/dsa/house-robber)

![Difficulty: Unspecified](https://img.shields.io/badge/Difficulty-Unspecified-6b7280?style=for-the-badge)

---

## 📝 Problem Statement

A robber is targeting to rob houses from a street. Each house has security measures that alert the police when two adjacent houses are robbed. The houses are arranged in a **circular manner** , thus the first and last houses are adjacent to each other.

Given an integer array money, where money[i] represents the amount of money that can be looted from the (i+1)^th house. Return the **maximum** amount of money that the robber can loot without alerting the police.

### Example 1:

**Input:** money = [2, 1, 4, 9]

**Output:** 10

**Explanation:**

[2, <u>1</u>, 4, <u>9</u>] The underlined houses would give the maximum loot.

Note that we cannot loot the 1st and 4th houses together.

### Example 2:

**Input:** money = [1, 5, 2, 1, 6]

**Output:** 11

**Explanation:**

[1, <u>5</u>, 2, 1, <u>6</u>] The underlined houses would give the maximum loot.

Still unsure what the problem is asking ?

Let’s go through a few more examples, step by step, to make it clearer.

### Constraints

- 1 <= money.length <= 10^5
- 0 <= money[i] <= 1000

---

## 💡 Complexity Analysis

- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

<p align="center">
  Generated with ❤️ by <a href="https://github.com/Arora-Sir">Mohit Arora</a> &nbsp;|&nbsp; Practice on <a href="https://takeuforward.org/pricing?affiliate=arorasir">TakeUForward (TUF+)</a> &nbsp;|&nbsp; ⭐ <a href="https://github.com/Arora-Sir/TUFHub">Star TUFHub on GitHub</a>
</p>
