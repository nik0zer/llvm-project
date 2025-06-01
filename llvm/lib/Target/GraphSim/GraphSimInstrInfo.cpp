#include "GraphSimInstrInfo.h"
#include "GraphSim.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "GraphSimGenInstrInfo.inc"

#define DEBUG_TYPE "GraphSim-inst-info"

GraphSimInstrInfo::GraphSimInstrInfo() : GraphSimGenInstrInfo() { GRAPHSIM_DUMP_GREEN }
