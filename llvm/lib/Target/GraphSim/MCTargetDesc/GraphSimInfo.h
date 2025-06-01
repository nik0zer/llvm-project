#ifndef LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMINFO_H
#define LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace GraphSimOp {
enum OperandType : unsigned {
  OPERAND_GRAPHSIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace GraphSimOp

} // end namespace llvm

#endif
