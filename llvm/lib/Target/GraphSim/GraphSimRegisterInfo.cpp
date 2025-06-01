#include "GraphSimRegisterInfo.h"
#include "GraphSim.h"
#include "GraphSimFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "GraphSimGenRegisterInfo.inc"

GraphSimRegisterInfo::GraphSimRegisterInfo() : GraphSimGenRegisterInfo(GraphSim::R0) {
  GRAPHSIM_DUMP_GREEN
}
const MCPhysReg *
GraphSimRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  GRAPHSIM_DUMP_GREEN
  return CSR_GraphSim_SaveList;
}

BitVector GraphSimRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  GRAPHSIM_DUMP_GREEN
  GraphSimFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(GraphSim::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(GraphSim::R2);
  }
  return Reserved;
}

bool GraphSimRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool GraphSimRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  GRAPHSIM_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register GraphSimRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  GRAPHSIM_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? GraphSim::R2 : GraphSim::R1;
}

const uint32_t *
GraphSimRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                      CallingConv::ID CC) const {
  GRAPHSIM_DUMP_GREEN
  return CSR_GraphSim_RegMask;
}
