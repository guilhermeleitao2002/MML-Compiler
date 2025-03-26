# MML Language Compiler Project

## Overview
MML is a weakly typed programming language with C-like syntax and features. This project involves implementing a compiler for MML, supporting its syntax, semantics, and runtime behavior. Below are the key aspects of the language and the compiler's implementation.

---

## Key Features of MML

### Data Types
- **Primitive Types**:
  - `int`: 4-byte integers (two's complement).
  - `double`: 8-byte floating-point numbers (IEEE 754).
  - `string`: Null-terminated character arrays (ASCII).
  - Pointers: 4-byte addresses (e.g., `[int]` for an integer pointer).
- **Type Compatibility**:
  - Weak typing with implicit conversions (e.g., int to double).
  - `void` for generic pointers or no return type.

### Variables and Scoping
- **Declaration**:
  - Explicit: `int x = 5;`
  - Implicit (type inference): `auto y = 3.14;`
  - Pointers: `[double] ptr = null;`
- **Scoping Rules**:
  - Global variables: Visible throughout the file.
  - Local variables: Block-scoped (shadowing allowed).
  - `public` keyword for cross-module visibility.
  - `forward` for external declarations.

### Lexical Conventions
- **Whitespace**: Ignored (spaces, tabs, newlines).
- **Comments**:
  - Line comments: `// ...`
  - Block comments: `/* ... */` (nesting allowed).
- **Literals**:
  - Integers: Decimal (`123`), octal (`012`).
  - Strings: `"Hello"` (supports escape sequences like `\n`).
  - Null pointer: `null`.

### Functions
- **Declaration**:
  - Anonymous functions assigned to variables:
    ```cpp
    auto factorial = (int n) -> int {
        if (n > 1) return n * @(n - 1); // @ for recursion
        else return 1;
    };
    ```
  - Return type `void` for no return value.
- **Invocation**:
  - Cdecl calling convention (arguments pushed right-to-left).
  - Function pointers: `int<int> func_ptr = factorial;`

### Control Structures
- **Conditionals**:
  ```cpp
  if (condition) { ... }
  elif (condition) { ... }
  else { ... }
  ```
- **Loops**:
  ```cpp
  while (condition) { ... }
  ```
- **Flow Control**:
  - `stop [n];` (break out of `n` loops).
  - `next [n];` (continue to next iteration).
  - `return [value];`

### Expressions and Operators
- **Operators**:
  - Arithmetic: `+`, `-`, `*`, `/`, `%` (C-like semantics).
  - Pointer arithmetic: `ptr + offset`.
  - Logical: `&&`, `||`, `~` (bitwise NOT).
  - Assignment: `=`.
- **Special Operators**:
  - `sizeof(expr)`: Size in bytes.
  - `?` (address-of): `a?` returns the address of `a`.
  - Memory allocation: `[double] p = [5];` (allocates 5 doubles on the stack).

### Input/Output
- **Input**: `input` keyword reads integers/doubles.
- **Output**:
  - `I` (inline print): `expr1, expr2 I`
  - `II` (print with newline): `"Result: ", x II`

### Interoperability
- **Foreign Functions**:
  - Declare external C functions with `foreign`:
    ```cpp
    foreign [void]<int> malloc; // C's malloc
    ```
- **Global Variables**:
  - Use `forward` to declare variables/functions from other modules.

---

## Example Programs

### Factorial Function
```cpp
// factorial.mml
public factorial = (int n) -> int {
    if (n > 1) return n * @(n - 1);
    else return 1;
};
```

### Main Program
```cpp
// main.mml
forward int<int> factorial;
foreign string<int> argv;
foreign int(string) atoi;

begin
    auto value = 1;
    if (argc() == 2) {
        string s = argv(1);
        value = atoi(s);
    }
    value, "! = ", factorial(value) II
    return 0;
end
```

---

## Compilation
The compiler generates assembly code, which is assembled and linked with the runtime library (RTS):
```bash
mml --target asm file.mml
yasm -felf32 file.asm
ld -melf_i386 -o output file.o -lrts
```

---

## Omissions and Notes
- Pointer arithmetic for `void*` increments/decrements by 1 byte.
- No direct string manipulation (use assignments or function arguments).
- Full operator precedence follows C rules.
