#include "ftt_midend.h"
#include "ftt_table_id.h"
#include "midend/midEndLast.h"

FttMidEnd::FttMidEnd(CompilerOptions& options) {
    refMap.setIsV1(false);
    auto evaluator = new P4::EvaluatorPass(&refMap, &typeMap);
    setName("FttMidEnd");
    addPasses({
        new HandleFttTableId(),

        // After frontend and midend, to evaluate
        evaluator,
        new VisitFunctor([evaluator](const IR::Node *root) -> const IR::Node * {
            // Visitor to check if main exists
            auto toplevel = evaluator->getToplevelBlock();
            auto main = toplevel->getMain();
            if (main == nullptr) {
            	return nullptr;
            }
            return root;
        }),
        new VisitFunctor([this, evaluator]() {
            // Setup FttMidEnd::toplevel
            this->toplevel = evaluator->getToplevelBlock();
        }),
        new P4::MidEndLast()
    });
}
