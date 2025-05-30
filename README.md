# CedarLang

🌲 Cedar is a high-level programming language with executable-oriented design.  
Human-readable, compiler-powerful, and low-level output capable.

## Features
- Elegant high-level syntax with low-level NASM x64 backend
- LLVM IR codegen and C-compatible semantics
- Real `.cdr` files compiled into `.exe` binaries
- Dynamic indentation, intrinsic punctuation, and modular logic

## Getting Started

### Requirements
- Flex & Bison
- LLVM
- NASM
- GCC

### Compile
```bash
make
```

### Run Example
```bash
./bin/cedarc examples/hello.cdr
```

## Windows Installer
Run `CedarLangInstaller.exe` to install the compiler on Windows.

## Maintained by
**Violet Aura Creations**

Modified Quick-Sample-Reference Long-code (QSRLC) License V2.0




🌲 Cedar: Language Identity
Name: Cedar

Type: High-level syntax / Low-level semantics

Paradigm: Instructional-Structured with Modular Execution

Target: LLVM IR → C-based NASM x64 → .exe binary

Compiler Output: Real Executable Machine Code

Design Ethos:

Dynamic Indentation: Flow-based scoping

Intrinsic Punctuation: Symbol-as-syntax logic

Human-Spaced: Readable, double-spaced keyword blocks

Intuitive Inlining: Clean integration of logic within logic

Passive Constructs: Iterations, proofs, linkers flow gently

Aggressive Constructs: Inheritance, nodes, branches execute deterministically

🔠 Grammar & Syntax Rules
Indentation: Dynamic
Two-space minimum to trigger block scope

Indentation depth affects compilation (like Python, but contextualized)

Punctuation: Intrinsic
: = Declare or label

-> = Function arrow

. = Access

.. = Range

: (at EOL) starts passive scope

{} not required, but supported for inline nesting

Spacing: Human-Friendly
Double-space between all declarations, modules, logic flows

Compiler recognizes line breaks and spacing in parsing pass

🔧 Compiler Design
Parser: CedarParser → Token Queue

AST: Dynamic, node-prioritized, GCC-compatible

IR Generation: LLVM IR

Assembly: C-style NASM x64 backend

Binary Output: .exe, .elf, or .bin (platform-targeted)



| Construct    | Behavior                   | Aggressive / Passive |
| ------------ | -------------------------- | -------------------- |
| `proof:`     | Asserts or conditions      | Passive              |
| `truth:`     | Immutable constant         | Passive              |
| `texture:`   | Enum or union-like variant | Passive              |
| `modifier:`  | Function pre/post filter   | Passive              |
| `linker:`    | Shared resource binder     | Passive              |
| `branch:`    | Decision fork              | Aggressive           |
| `inherit:`   | Class inheritance          | Aggressive           |
| `structure:` | Data model                 | Aggressive           |
| `route:`     | Execution flow route       | Passive              |
| `channel:`   | Async/stream handler       | Passive              |




🗺️ Reserved Words (Core Lingo)

start
end
define
structure
inherit
branch
proof
truth
texture
route
channel
linker
modifier
repeat
until
echo
await
emit
within
begin
halt




