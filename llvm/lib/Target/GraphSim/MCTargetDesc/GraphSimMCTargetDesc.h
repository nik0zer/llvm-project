#ifndef LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCTARGETDESC_H
#define LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCTARGETDESC_H

#include <memory>
namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createGraphSimMCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx);
MCAsmBackend *createGraphSimAsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                  const MCRegisterInfo &MRI,
                                  const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter> createGraphSimELFObjectWriter(bool Is64Bit,
                                                               uint8_t OSABI);
} // namespace llvm

// Defines symbolic names for GraphSim registers.  This defines a mapping from
// register name to register number.
//
#define GET_REGINFO_ENUM
#include "GraphSimGenRegisterInfo.inc"

// Defines symbolic names for the GraphSim instructions.
#define GET_INSTRINFO_ENUM
#include "GraphSimGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCTARGETDESC_H
