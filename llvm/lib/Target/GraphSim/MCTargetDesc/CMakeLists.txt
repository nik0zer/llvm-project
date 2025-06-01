add_llvm_component_library(LLVMGraphSimDesc
  GraphSimMCTargetDesc.cpp
  GraphSimMCAsmInfo.cpp
  GraphSimInstPrinter.cpp

  LINK_COMPONENTS
  MC
  Support
  GraphSimInfo

  ADD_TO_COMPONENT
  GraphSim
 )
