# Contributing to DSA-Basic

This repository is a personal, learning-oriented DSA notebook. Keep additions easy to scan, understand, search, and revise.

## Add a problem

1. Choose the most relevant existing topic folder. Create a new topic only when a meaningful group of problems exists.
2. Create one Markdown note using the [problem template](templates/PROBLEM-TEMPLATE.md).
3. Name the file in lowercase `kebab-case.md`, for example `binary-search.md`.
4. Keep the visible title as the first-level heading (`# Problem title`).
5. Put code in fenced `cpp` blocks. Include required headers when useful and label separate approaches clearly.
6. Include examples and explain time complexity and auxiliary space complexity.
7. Add the problem to that topic's `README.md` and to `REVISION-TRACKER.md`.
8. Update the topic counts in the root `README.md`.

## Note-writing rules

- Keep one problem per note; do not combine unrelated problems.
- Keep the problem statement, reasoning, code, and examples together.
- Prefer concise explanations that make the algorithm understandable without external context.
- Distinguish the optimal approach from a simpler or alternative approach when both are useful.
- State assumptions and constraints. Do not silently invent constraints when the source problem does not provide them.
- Use consistent names and formatting within a note.
- Do not claim code is a complete executable if it is only a function or snippet.
- Do not add copied binaries, generated build files, editor configuration, or unrelated notes.

## Updating an existing problem

- Preserve its original problem intent and useful examples.
- Correct formatting and links without duplicating the implementation.
- If the algorithm changes, update the explanation and complexity alongside the code.
- Update the topic index and revision tracker when the file is renamed or removed.

## Before committing

- Open every changed Markdown link and verify its relative path.
- Check that code fences are balanced and use the correct language label.
- Make sure the topic count and revision tracker match the problem notes.
