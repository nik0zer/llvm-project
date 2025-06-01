#include "GraphSimTargetMachine.h"
#include "GraphSim.h"
#include "TargetInfo/GraphSimTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphSimTarget() {
  // Register the target.

  RegisterTargetMachine<GraphSimTargetMachine> A(getTheGraphSimTarget());
}

GraphSimTargetMachine::GraphSimTargetMachine(const Target &T, const Triple &TT,
                                   StringRef CPU, StringRef FS,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CM,
                                   CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {

  initAsmInfo();
}

namespace {

/// GraphSim Code Generator Pass Configuration Options.
class GraphSimPassConfig : public TargetPassConfig {
public:
  GraphSimPassConfig(GraphSimTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  GraphSimTargetMachine &getGraphSimTargetMachine() const {
    return getTM<GraphSimTargetMachine>();
  }

  bool addInstSelector() override {

    addPass(createGraphSimISelDag(getGraphSimTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *GraphSimTargetMachine::createPassConfig(PassManagerBase &PM) {

  return new GraphSimPassConfig(*this, PM);
}

TargetLoweringObjectFile *GraphSimTargetMachine::getObjFileLowering() const {

  return TLOF.get();
}
