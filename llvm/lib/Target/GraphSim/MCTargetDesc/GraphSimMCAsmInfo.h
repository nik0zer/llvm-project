#ifndef LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCASMINFO_H
#define LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class GraphSimELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit GraphSimELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_GRAPHSIM_MCTARGETDESC_GRAPHSIMMCASMINFO_H