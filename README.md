# Readability (CS50 Problem Set)

# Description
This program implements the Coleman-Liau index to compute the approximate grade level needed to comprehend a text. The program prompts the user for a text and outputs the grade level for that text.

# How it Works
The program calculates the Coleman-Liau index using the formula:
index = 0.0588 * L - 0.296 * S - 15.8

where:
- L is the average number of letters per 100 words
- S is the average number of sentences per 100 words

# Features
- Counts letters, words, and sentences in a given text
- Handles various sentence terminators (., !, ?)
- Provides grade level output from "Before Grade 1" to "Grade 16+"
- Includes debug output showing calculation details

# Usage
```bash
$ ./readability
Add text here to evaluate grade level: Here is some sample text. How readable is it?
```

# Example Output
```
Letters: 30
Words: 8
Sentences: 2
L: 375.000000
S: 25.000000
Grade 8
```

# Requirements
- CS50 Library
- C compiler (clang recommended)
- make

# Compilation
```bash
make readability
```

# Course Information
This project is part of Harvard's CS50: Introduction to Computer Science course, Problem Set 2.

# Author
Michael Despo

# License
This project is part of CS50's course materials. Please refer to CS50's academic honesty guidelines.
