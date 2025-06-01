#include "MCTargetDesc/GraphSimInfo.h"
#include "GraphSim.h"
#include "GraphSimInstPrinter.h"
#include "GraphSimMCAsmInfo.h"
#include "TargetInfo/GraphSimTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "GraphSimGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "GraphSimGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "GraphSimGenSubtargetInfo.inc"

static MCRegisterInfo *createGraphSimMCRegisterInfo(const Triple &TT) {
  GRAPHSIM_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitGraphSimMCRegisterInfo(X, GraphSim::R0);
  return X;
}

static MCInstrInfo *createGraphSimMCInstrInfo() {
  GRAPHSIM_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitGraphSimMCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *createGraphSimMCSubtargetInfo(const Triple &TT,
                                                 StringRef CPU, StringRef FS) {
  GRAPHSIM_DUMP_MAGENTA
  return createGraphSimMCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCAsmInfo *createGraphSimMCAsmInfo(const MCRegisterInfo &MRI,
                                     const Triple &TT,
                                     const MCTargetOptions &Options) {
  GRAPHSIM_DUMP_MAGENTA
  MCAsmInfo *MAI = new GraphSimELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(GraphSim::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createGraphSimMCInstPrinter(const Triple &T,
                                             unsigned SyntaxVariant,
                                             const MCAsmInfo &MAI,
                                             const MCInstrInfo &MII,
                                             const MCRegisterInfo &MRI) {
  GRAPHSIM_DUMP_MAGENTA
  return new GraphSimInstPrinter(MAI, MII, MRI);
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeGraphSimTargetMC() {
  GRAPHSIM_DUMP_MAGENTA
  Target &TheGraphSimTarget = getTheGraphSimTarget();
  RegisterMCAsmInfoFn X(TheGraphSimTarget, createGraphSimMCAsmInfo);
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheGraphSimTarget, createGraphSimMCRegisterInfo);
  // Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheGraphSimTarget, createGraphSimMCInstrInfo);
  // Register the MC subtarget info.
  TargetRegistry::RegisterMCSubtargetInfo(TheGraphSimTarget,
                                          createGraphSimMCSubtargetInfo);

  // Register the MCInstPrinter
  TargetRegistry::RegisterMCInstPrinter(TheGraphSimTarget, createGraphSimMCInstPrinter);
}
