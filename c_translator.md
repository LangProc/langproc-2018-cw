Deliverable 1: C-to-Python Translator
=====================================

Your compiler should support a translation mode, which translates a subset of pre-processed C90 into Python.

Program build and execution
---------------------------

Your program should be built using the command:

    make bin/c_compiler

The translator function is invoked using the flag `--translate`, with the source file and output file specified on the command line:

    bin/c_compiler --translate [source-file.c] -o [dest-file.py]
    
You can assume that the command-line arguments will always be in this order, and that there will be no spaces in source or destination paths.

Input format
------------

The input file will be pre-processed [ANSI C](https://en.wikipedia.org/wiki/ANSI_C), also called C90 or C89. It's what's generally thought of as "classic" or "normal" C, but not the _really_ old one without function prototypes (you may never have come across that). C90 is still often used in embedded systems, and pretty much the entire Linux kernel is in C90.

You've mainly been taught C++, but you're probably aware of C as a subset of C++ without classes, which is a good mental model. Your programs (lexer, parser and compiler) will never be given code that has different parsing or execution semantics under C and C++ (so, for example, I won't give you code that uses `class` as an identifier).

The source code will not contain any compiler-specific or platform-specific extensions. If you pre-process a typical program (see later), you'll see many things such as `__attribute__` or `__declspec` coming from the system headers. You will not need to deal with any of these.

The test inputs will be a set of files of increasing complexity and variety. All files will be [well-formed](https://en.wikipedia.org/wiki/Well-formedness).

Output format
-------------

The output format will be a Python3 program equivalent to the input C.

The full set of patterns required is described [here](c_translator_templates.md).

As an example, we would translate the input program:

```
int f(int x)
{
  return x*x;
}
```
into the Python:
```
def f(x):
    return x*x
```

As another example, this program:
```
int f(int x)
{
  if(x>1){
    return x*f(x-1);
  }else{
    return x;
  }
}
```
turns into:
```
def f(x):
   if x>1:
       return x*f(x-1)
   else:
       return x
```
