Deliverable 3: A compiler for the C language
============================================

Your program should read C source code from a file, and write MIPS assembly to another file.

Program build and execution
---------------------------

Your program should be built using the command:

    make bin/c_compiler

The compilation function is invoked using the flag `-S`, with the source file and output file specified on the command line:

    bin/c_compiler -S [source-file.c] -o [dest-file.s]
    
You can assume that the command-line arguments will always be in this order, and that there will be no spaces in source or destination paths.

Input Format
------------

The input format is the same as for the translator (pre-processed C90).

Output Format
-------------

The output format should be MIPS1 assembly code.

It should be possible to assemble and link this code against a C run-time, and have it execute correctly on a MIPS processor as emulated by `qemu-mips`.
