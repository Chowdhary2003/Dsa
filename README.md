# DSA — Data Structures & Algorithms

A topic-organized collection of **612 Markdown study notes and problem solutions** covering core data structures, algorithms, and interview patterns. The original notes are preserved; this upgrade adds navigation, a learning roadmap, consistent templates, and an interview-coaching prompt.

> **Language note:** Existing solutions are not assumed to use one consistent C++ standard. Check each solution's includes, namespace usage, constraints, and complexity before relying on it. The recommended baseline for new solutions is **C++17**.

## Quick navigation

| Topic | Notes | Index |
|---|---:|---|
| Arrays | 146 | [`Arrays/README.md`](Arrays/README.md) |
| Basic | 34 | [`Basic/README.md`](Basic/README.md) |
| Binary-Tree | 40 | [`Binary-Tree/README.md`](Binary-Tree/README.md) |
| Bit-Manipulation | 19 | [`Bit-Manipulation/README.md`](Bit-Manipulation/README.md) |
| BST | 27 | [`BST/README.md`](BST/README.md) |
| Dp | 72 | [`Dp/README.md`](Dp/README.md) |
| Graphs | 58 | [`Graphs/README.md`](Graphs/README.md) |
| Greedy-algorithm | 18 | [`Greedy-algorithm/README.md`](Greedy-algorithm/README.md) |
| Linked-list | 42 | [`Linked-list/README.md`](Linked-list/README.md) |
| Priority-Queues-Heaps | 18 | [`Priority-Queues-Heaps/README.md`](Priority-Queues-Heaps/README.md) |
| Recursion-Backtracking | 39 | [`Recursion-Backtracking/README.md`](Recursion-Backtracking/README.md) |
| Sliding-Window-Deque | 15 | [`Sliding-Window-Deque/README.md`](Sliding-Window-Deque/README.md) |
| Stack-Queue | 36 | [`Stack-Queue/README.md`](Stack-Queue/README.md) |
| Strings | 41 | [`Strings/README.md`](Strings/README.md) |
| Trie | 7 | [`Trie/README.md`](Trie/README.md) |

## Recommended learning path

1. **Foundations:** Basic, Bit-Manipulation, Strings
2. **Linear structures:** Arrays, Linked-list, Stack-Queue, Sliding-Window-Deque
3. **Search and hierarchy:** BST, Binary-Tree, Priority-Queues-Heaps, Trie
4. **Problem-solving techniques:** Recursion-Backtracking, Greedy-algorithm
5. **Advanced algorithms:** Graphs, Dp

This is a suggested progression, not a claim that every prerequisite is represented in the repository.

## How to use a problem note

For each problem:

1. Read the statement and constraints.
2. Explain a brute-force approach before optimizing.
3. Identify the pattern and justify why it applies.
4. Implement and test edge cases.
5. State time and auxiliary-space complexity precisely.
6. Revisit the problem after a delay and solve it without looking.

Use [`PROBLEM_TEMPLATE.md`](PROBLEM_TEMPLATE.md) for new or substantially revised notes. Use [`ROADMAP.md`](ROADMAP.md) to track study progress and [`INTERVIEW_COACH_PROMPT.md`](INTERVIEW_COACH_PROMPT.md) when practicing with an AI interview coach.

## Repository conventions

- Keep one principal problem per Markdown file.
- Use descriptive filenames; preserve meaningful existing names unless there is a clear reason to rename.
- Prefer C++17-compatible examples unless a problem requires a newer feature.
- Include all required headers and either qualify standard-library names with `std::` or explicitly document `using` declarations.
- Distinguish **auxiliary space** from total space, and state whether sorting or output storage is counted.
- Do not claim a solution is optimal without explaining the relevant lower bound or trade-off.
- Add representative tests, including empty/small input, duplicates, boundary values, and large constraints where relevant.
- Avoid copying platform-specific problem statements wholesale; summarize them in your own words and link to the original source when appropriate.

## Current contents

- {len(topic_dirs)} topic directories
- {total_topic_files} Markdown files inside topic directories
- {len(root_md)} root-level Markdown files retained from the original archive
- Existing source notes have been preserved rather than automatically rewritten

## Quality status

This repository contains study notes, not a fully verified competitive-programming library. A filename or code snippet is not proof that a solution compiles or passes all constraints. See [`CONTENT_AUDIT.md`](CONTENT_AUDIT.md) for the initial archive audit and known cleanup candidates.

## Contributing

When adding a solution:
1. Use the problem template.
2. Compile the code with the stated standard.
3. Add at least three meaningful tests.
4. Verify complexity against the implementation.
5. Update the relevant topic index.
