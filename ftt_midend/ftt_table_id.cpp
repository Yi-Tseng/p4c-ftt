#include "ftt_table_id.h"

bool HandleFttTableId::preorder(IR::P4Table* table) {
    IR::Annotations *annot = table->annotations->clone();
    annot->annotations.push_back(new IR::Annotation("FTTID", nextTableId));
    table->annotations = annot;
    nextTableId++;
    return true;
}
