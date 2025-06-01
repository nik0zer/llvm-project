#ifndef LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCTARGETDESC_H
#define LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCTARGETDESC_H

// Defines symbolic names for GraphSim registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GraphSimGenRegisterInfo.inc"

// Defines symbolic names for the GraphSim instructions.
#define GET_INSTRINFO_ENUM
#include "GraphSimGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCTARGETDESC_H
