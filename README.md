P4 Backend Compiler for FTT (Fixed Three Tables) Target & Architecture
====

This compiler is designed and developed for tutorial of [p4tw.org](https://p4tw.org)

## How to compile it

To compile it, link this directory in to `p4c/extensions` and compile the p4c.

```bash
$ cd p4c
$ mkdir -p extensions
$ ln -s three-table-arch extensions/three-table-arch
$ ./bootstrap
$ cd build && make -j4
$ make install
```

## Tutorials (Mandarin, Traditional Chinese) (_Work in progress_)

 - [x] [P4 Compiler overview and architecture](https://p4tw.org/p4-compiler-architecure/)
 - [x] [Create your own architecture package](https://p4tw.org/p4-copmiler-define-architecture-package/)
 - [x] [Create new compiler for your target and put it into p4c](https://p4tw.org/p4-compiler-create-new-bc/)
 - [x] [Add frontend compiler to your compiler binary](https://p4tw.org/p4-compiler-add-frontend/)
 - [x] [IR and Visitor introduction](https://p4tw.org/p4-compiler-ir-and-visitor/)
 - [ ] Midend
 - [ ] Complete the backend compiler
