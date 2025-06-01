#ifndef LLVM_LIB_TARGET_GraphSim_GraphSim_H
#define LLVM_LIB_TARGET_GraphSim_GraphSim_H

#include "MCTargetDesc/GraphSimMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

#define GRAPHSIM_DUMP(Color)                                                        \
  {                                                                            \
    llvm::errs().changeColor(Color)                                            \
        << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
    llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
  }
// #define GRAPHSIM_DUMP(Color) {}

#define GRAPHSIM_DUMP_RED GRAPHSIM_DUMP(llvm::raw_ostream::RED)
#define GRAPHSIM_DUMP_GREEN GRAPHSIM_DUMP(llvm::raw_ostream::GREEN)
#define GRAPHSIM_DUMP_YELLOW GRAPHSIM_DUMP(llvm::raw_ostream::YELLOW)
#define GRAPHSIM_DUMP_CYAN GRAPHSIM_DUMP(llvm::raw_ostream::CYAN)
#define GRAPHSIM_DUMP_MAGENTA GRAPHSIM_DUMP(llvm::raw_ostream::MAGENTA)
#define GRAPHSIM_DUMP_WHITE GRAPHSIM_DUMP(llvm::raw_ostream::WHITE)
namespace llvm {
class GraphSimTargetMachine;
class FunctionPass;
class GraphSimSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerGraphSimMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                  AsmPrinter &AP);
bool LowerGraphSimMachineOperandToMCOperand(const MachineOperand &MO,
                                       MCOperand &MCOp, const AsmPrinter &AP);
FunctionPass *createGraphSimISelDag(GraphSimTargetMachine &TM, CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_GraphSim_GraphSim_H