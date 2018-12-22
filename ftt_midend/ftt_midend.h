#ifndef _FTT_MIDEND_H_
#define _FTT_MIDEND_H_

#include "ir/ir.h"
#include "frontends/common/options.h"
#include "frontends/p4/evaluator/evaluator.h"

class FttMidEnd : public PassManager {
public:
    P4::ReferenceMap    refMap;
    P4::TypeMap         typeMap;
    IR::ToplevelBlock   *toplevel = nullptr;

    explicit FttMidEnd(CompilerOptions& options);
    IR::ToplevelBlock* process(const IR::P4Program *&program) {
        program = program->apply(*this);
        return toplevel;
    }
};

#endif /* _FTT_MIDEND_H_ */
