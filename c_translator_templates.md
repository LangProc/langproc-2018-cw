Problem scope and templates for C to python translation
=======================================================

Required Constructs
-------------------

You are only required to support a subset of C when you translate to Python. This subset is to reflect the fact that this deliverable is supposed to be "simpler" than the final C deliverable and mainly test competency with parsers, and also that Python doesn't directly support everything that C does.

Variables
- Local integer variables (though not nested scopes)
- Global integer variables
- You are *not* required to handle any [shadowing of variables](https://en.wikipedia.org/wiki/Variable_shadowing), e.g.
  a local variable with the same name as a global variable

Functions
- Definition of functions taking 0 or more integer parameters and with void or integer return type
- Explicit support for main special functionality

Statements
- if
- if-else
- while
- return
- sequences

Expressions
- Decimal integer constants
- Integer arithmetic: `*`,`+`,`-`
- Logical operations: `&&`,`||`
- Comparison operations: `<`,`==`
- Invocation of functions
- Assignment (but only as a direct expression statement)

Getting this to work
--------------------

Testing the translation is ultimately up to you. However, you may wish to use `c_translator_formative.sh`, which runs a few test-cases. It also gives concrete examples of how a particular C file could be translated into a concrete Python file, and how you can run them.

Templates for translation
=========================

Each of the following gives a template for how to convert a particular C syntactic construct into the equivalent Python.

In the following `...` is used to represent some kind of placeholder structure.

The overall check is on the _functionality_ of the Python, not on the exact textual output. So your output may differ in terms of exactly what you do (you may choose different templates), as long as the Python does the same as the C.

Variables
---------

### Local variables

Declaration with no initialiser:
```C
{
    int x;
}
```
to
```python
x=0
```

Declaration with initialiser:
```C
{
    int x=...;
}
```
to
```python
x=...
```

Note that for C to python translation you are not required to deal with shadowing of local variables, because Python does not have the notion of nested local scopes. So for example this:
```C
{
    int x;
    {
        int x;
    }
}
```
does not need to be translated.

### Global variables

This is probably the most complicated thing to handle. Suppose we have a global variable `x`, which is used within a function `f`:
```C
int x;

int f(){
    return x+10;
}
```
Once a global variable comes into scope, then we need to indicate that
it is global in other functions:
```python
x=0

def f():
    global x
    return x+10
```

There might also be more than one global function:
```C
int x;
int y;

int f(){
    ...
}

int g(){
    ...
}
```
to
```python
x=0
y=0

def f():
    global x
    global y
    ...
    
def g():
    global x
    global y
    ...

```

For C to Python you are not required to deal with globals that are shadowed by a local parameter or a local variable. So in the above example, given there is a global variable called `x`, you will not encounter either a local variable or a function parameter called `x`.


Functions
---------

### Nullary function definition

```C
int f()
{
  ...
}
```
to
```python
def f():
    ...
```

### Unary function definition

```C
int f(int x){ ... };
```
to
```python
def f(x):
    ...
```

### Binary function definition

```C
int f(int x, int y){ ... };
```
to
```python
def f(x,y):
    ...
```

### Main functions

In a C file the `main` function has special status as the start point. We will only require support for main with no parameters:
```C
int main()
{
   ...
}
```
which is converted to:
```python
# Define the actual main function
def main():
    ....
    
# Invoke main as the starting point
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
```
	
The second part is used because in Python statements can be appear at global level (unlike C). So if the Python script is started using the Python interpreter, then the `main` function will be executed.

You can inject this logic either at the bottom of every single Python file, or only if you see a function called `main` (I suggest the former).

Statements
----------

Note that Python requires indentation to indicate block scoping, so for all statements there will be a certain level of whitespace to indicate how nested the statement is.

### If
```C
if(...) ...
```
to
```python
if (...):
    ...
```
Here the indent is important, and means that everything in the
body of the if needs to be at the new indent.

For example:
```C
if(...){
   ...;
   ...;
}
```
to
```python
if (...):
    ...
    ...
```


### IfElse
```C
if(...) ... else ...
```
to
```python
if (...):
    ...
else:
    ...
```
Note that the patterns `If` and `IfElse` together solve the
dangling else problem. While python has `elif`, you don't need
to use it for translation.
    
### While
```C
while(...) ...
```
to
```python
while (...):
    ...
```

### Return
```C
return (...);
```
to
```python
return ...
```

### Sequences
```C
{
...
...
}
```
to
```python
...
...
```
Note that the statements must be output at the current indent level.

Using this template within another template:
```C
while(...) {
   ...
   ...
}
```
to
```python
while (...):
    ...
    ...
```

Expressions
-----------

### Assignment

In C assignment is an expression, but in Python it is a statement. So we only
support C assignments as statements, with the form:
```C
... = ...;
```
which convert to:
```python
... = ...
```
Note that your AST would ideally support assignment as an expression,
but you will only encounter this restricted form when translating to Python.

### Operators

Binary and unary expression have the same form in C and Python; the only
change is to some operator names
```C
( ... C_OP ... )
```
to
```python
( ... PYTHON_OP ... )
```

The only two operators of interest that are different are:
```C
( ... && ... )
```
to
```python
( ... and ... )
```

and

```C
( ... || ... )
```
to 
```python
( ... or ... )
```

### Function invocation

Nullary:
```C
f()
```
to
```python
f()
```

Unary:
```C
f(...)
```
to
```python
f(...)
```

Binary:
```C
f( ... , ... )
```
to
```python
f( ... , ... )
```

