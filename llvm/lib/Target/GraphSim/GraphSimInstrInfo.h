#ifndef LLVM_LIB_TARGET_GRAPHSIM_GRAPHSIMINSTRINFO_H
#define LLVM_LIB_TARGET_GRAPHSIM_GRAPHSIMINSTRINFO_H

#include "GraphSimRegisterInfo.h"
#include "MCTargetDesc/GraphSimInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "GraphSimGenInstrInfo.inc"

namespace llvm {

class GraphSimSubtarget;

class GraphSimInstrInfo : public GraphSimGenInstrInfo {
public:
  GraphSimInstrInfo();

};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHSIM_GRAPHSIMINSTRINFO_H
