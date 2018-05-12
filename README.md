P4 Backend Compiler for FTT (Fixed Three Tables) Target & Architecture
====

This compiler is designed and developed for tutorial of [p4tw.org](https://p4tw.org)

## How to compile it

To compile it, link this directory in to `p4c/extensions` and compile the p4c.

```bash
$ cd p4c
$ ./bootstrap
$ ln -s 'PATH_OF_THIS_DIR' extensions/three-table-arch
$ cd build && make -j4
```

## Tutorials (Mandarin, Traditional Chinese) (_Work in progress_)

 - [x] [P4 Compiler overview and architecture](https://p4tw.org/p4-compiler-architecure/)
 - [x] [Create your own architecture package](https://p4tw.org/p4-copmiler-define-architecture-package/)
 - [] Create new compiler for your target and put it into p4c
 - [] Add frontend and midend compiler to your compiler binary
 - [] IR introduction and what IR looks like
 - [] Visitors
 - [] Complete the backend compiler
