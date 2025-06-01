add_llvm_component_group(GraphSim)

set(LLVM_TARGET_DEFINITIONS GraphSim.td)

tablegen(LLVM GraphSimGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM GraphSimGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM GraphSimGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM GraphSimGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM GraphSimGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM GraphSimGenCallingConv.inc -gen-callingconv)
tablegen(LLVM GraphSimGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM GraphSimGenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(GraphSimCommonTableGen)

add_llvm_target(GraphSimCodeGen
  GraphSimTargetMachine.cpp
  GraphSimRegisterInfo.cpp
  GraphSimInstrInfo.cpp
  GraphSimSubtarget.cpp
  GraphSimAsmPrinter.cpp
  GraphSimISelDagToDag.cpp
  GraphSimISelLowering.cpp
  GraphSimMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  GraphSimInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  GraphSim
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
