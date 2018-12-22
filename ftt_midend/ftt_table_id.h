/*
 * Midend for adding custom table id (FTT) annotation.
 */
#include "ir/ir.h"
#include "frontends/common/resolveReferences/resolveReferences.h"

class HandleFttTableId : public Modifier {
    int nextTableId;
    bool preorder(IR::P4Table* table) override;
public:
    HandleFttTableId() { this->nextTableId = 0; }
};
