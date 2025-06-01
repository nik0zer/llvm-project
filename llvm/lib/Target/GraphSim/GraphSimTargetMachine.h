#ifndef LLVM_LIB_TARGET_GRAPHSIM_GRAPHSIMTARGETMACHINE_H
#define LLVM_LIB_TARGET_GRAPHSIM_GRAPHSIMTARGETMACHINE_H

#include "GraphSimSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheGraphSimTarget;

class GraphSimTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  GraphSimSubtarget Subtarget;

public:
  GraphSimTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);

  const GraphSimSubtarget *getSubtargetImpl(const Function &) const override {
    GRAPHSIM_DUMP_CYAN
    return &Subtarget;
  }
  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHSIM_GRAPHSIMTARGETMACHINE_H
