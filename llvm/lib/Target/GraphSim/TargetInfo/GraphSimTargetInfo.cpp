#include "TargetInfo/GraphSimTargetInfo.h"
#include "GraphSim.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheGraphSimTarget() {

  static Target TheGraphSimTarget;
  return TheGraphSimTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphSimTargetInfo() {

  RegisterTarget<Triple::graphsim> X(getTheGraphSimTarget(), "graphsim",
                                "GraphSimulator target for LLVM course", "GRAPHSIM");
}
