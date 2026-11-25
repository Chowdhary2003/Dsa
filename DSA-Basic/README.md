# DSA-Basic

A focused, Markdown-first collection of Data Structures & Algorithms (DSA) practice notes and C++ solution snippets. The repository is organized to make problems easy to **find, understand, store, and revisit**.

## Start here

| Goal | Open |
|---|---|
| Browse all topics | [Problem index](#topic-index) |
| Learn a new problem | [Learning workflow](#learning-workflow) |
| Revise previously learned problems | [Revision guide](REVISION.md) |
| Track your revision progress | [Revision tracker](REVISION-TRACKER.md) |
| Add or update a problem | [Contribution guide](CONTRIBUTING.md) |
| Create a new problem note | [Problem template](templates/PROBLEM-TEMPLATE.md) |

## Repository snapshot

| Topic | Problems |
|---|---:|
| [Number & Mathematics](01-number-math/README.md) | 24 |
| [Arrays & Matrices](02-arrays-matrices/README.md) | 4 |
| [Strings](03-strings/README.md) | 3 |
| [Recursion](04-recursion/README.md) | 3 |
| **Total** | **34** |

## Topic index

- [01 — Number & Mathematics](01-number-math/README.md)
- [02 — Arrays & Matrices](02-arrays-matrices/README.md)
- [03 — Strings](03-strings/README.md)
- [04 — Recursion](04-recursion/README.md)

## Learning workflow

1. **Attempt first.** Read the problem and examples, then try to solve it before opening the solution.
2. **Understand, do not copy.** Read the approach and code; explain the key idea in your own words.
3. **Rebuild from memory.** Close the solution and write it again without looking.
4. **Check the details.** Verify the examples, edge cases, time complexity, and auxiliary space complexity.
5. **Schedule revision.** Add the learning date and review checkpoints to the [revision tracker](REVISION-TRACKER.md).

Use [REVISION.md](REVISION.md) for a repeatable active-recall routine.

## How solutions are stored

Each problem has one Markdown note. Its problem statement, complexity, C++ snippet, and examples stay together so the code is never separated from the context needed to understand it. This is intentional: several current snippets are function-level solutions rather than complete programs, so duplicating them into separate `.cpp` files would create two sources of truth.

When a solution is a complete standalone program in the future, a matching `.cpp` file can be added beside its note. Keep the note as the explanation and the `.cpp` as the executable source; do not maintain two independently edited copies of the same implementation.

## Repository structure

```text
DSA-Basic/
├── 01-number-math/       # Topic index + problem notes
├── 02-arrays-matrices/   # Topic index + problem notes
├── 03-strings/           # Topic index + problem notes
├── 04-recursion/         # Topic index + problem notes
├── templates/            # Reusable problem-note template
├── CONTRIBUTING.md       # Rules for adding and updating notes
├── REVISION.md           # Active-recall and spaced-revision routine
├── REVISION-TRACKER.md   # Per-problem revision checklist
├── .gitignore
└── README.md
```

## Repository conventions

- Keep one problem per note and store it under the most relevant topic.
- Use lowercase `kebab-case` filenames; keep the visible problem title as the Markdown H1.
- Keep code in fenced `cpp` blocks and preserve the explanation, complexity, and examples with it.
- Avoid committing binaries, build output, editor settings, or unrelated personal notes.
- Update the topic index and revision tracker whenever a problem is added, renamed, or removed.
