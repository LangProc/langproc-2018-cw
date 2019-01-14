2018/2019 Compilers Coursework
==============================

There is a single assessed code deliverable, which is due on Tue 26 March at 23:59. This deliverable contains three components:

- [*Test suite*](c_test_suite.md) (14.3%): Each submission must contain a set of test programs which are able to determine whether a given compiler implements certain C language features correctly.

- [*C-translator*](c_translator.md) (28.6%): Your compiler will be able to translate a sub-set of C into equivalent Python. This allows each submission to demonstrate lexing and parsing functionality, even if the code generation is weak.

- [*C-compiler*](c_compiler.md) (42.8%): This is a compiler from C to MIPS assembly.
  
In all cases, the source language is pre-processed C90. The target environment is Ubuntu 16.04, so the lab Ubuntu distribution, or equivalently an Ubuntu 16.04 VM as configured in the attached Vagrantfile.

Associated with all deliverables is a

- [time-tracking/project management component](management.md) (14.3%).

This will be updated as you go along, but the final version is due on Fri 29 March at 23:59, then will be assessed orally at the start of Summer term.


Repositories
============

Each group gets a bare private repository. It is up to you if you want to clone the master specification, or to start from scratch.

Submission
==========

Submission will be via GitHub (code) and Blackboard (commit hash), as in the lab.

All submissions will be tested functionally, and won't be modified if they don't correctly compile, or if they produce output in the wrong place or format.
