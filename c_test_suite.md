Deliverable 1: Test suite
=========================

You need test programs in order to check whether your compiler emits code that actually works. Writing test-cases is quite a skill, and it is very difficult to get good test coverage.  As much as possible you should develop independent test-cases that look at individual features you are working on. Also, once a test-case is successfully passed, no future features should stop that test-case passing. The situation where the addition of something new stops something old working is generally called a _regression_, and _regression testing_ is used to make sure that functionality doesn't go backwards.

In order to do regression testing, you need two things:

1. a set of test-cases, and

2. an automated system for running the test-cases.

Your task is to develop ten test cases looking for different functionality. There is no requirement that your compiler implements these features, only that your test-cases try to test them.

Test case format
----------------

Each test case has a name ${NAME}, and consists of two files:

- `${NAME}.c`: The source file to be compiled by the compiler-under-test. This should be very minimal, and use the smallest amount of code needed to perform the test.

- `${NAME}_driver.c`: A driver file to be compiled by GCC, which knows how to invoke the functionality in the tested file. This can contain any C code at all, as it will be compiled by GCC.

The testing process for a test-case is then:

1. Compile `${NAME}.c` using the compiler-under-test into MIPS assembly.

2. Compile `${NAME}_driver.c` using GCC into a MIPS object file.

3. Link the generated assembly and the driver object into a MIPS executable.

4. Run the executable under QEMU.

5. If the executable returns 0 (via `$?` in the shell), then the test-case has passed.

If any of these steps fail, then either the test-case is malformed, or the compiler-under-test is not generating correct code.

Required tests
--------------

The requirements for the deliverable are to create ten tests:

1. `IF_T`: Can the compiled code correctly execute a branch of an if.

2. `IF_F`: Can the compiled code correctly not execute a branch of an if.

3. `IF_ELSE_T`: Test that an if else condition correctly executes the true branch.

4. `IF_ELSE_F`: Test that an if else condition correctly executes the false branch.

5. `FOR_N`: Check that a for-loop can execute more than one iteration.

6. `LOCAL_ARRAY`: Check that an array can be allocated locally and used within a function.

7. `SELF_RECURSION`: A minimal test that a single function can call itself.

8. `GLOBAL`: Check that global variables can be shared between object files.

9. `MAIN`: Check that the compiler under test can emit a valid `main` entry point.

10. `ATOF`: Check that the generated code can call the C function `atof` (note that `atof` is just a function, so all you need is the declaration for `atof` -- you don't need to be able to handle all of the C standard library header).

Note that these tests do not reflect either a required level of achievement for your compiler, nor should they mean that you can't add other tests.

Submitted files
---------------

Your tests cases should be included in a folder called

    test_deliverable/test_cases

and follow the naming convention in the example files
we'll develop in the lecture.
