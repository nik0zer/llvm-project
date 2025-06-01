add_llvm_component_library(LLVMGraphSimDesc
  GraphSimMCTargetDesc.cpp
  GraphSimMCAsmInfo.cpp
  GraphSimInstPrinter.cpp
  GraphSimMCCodeEmitter.cpp
  GraphSimAsmBackend.cpp
  GraphSimELFObjectWriter.cpp

  LINK_COMPONENTS
  MC
  Support
  GraphSimInfo

  ADD_TO_COMPONENT
  GraphSim
 )
