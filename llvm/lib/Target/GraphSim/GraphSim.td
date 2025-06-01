include "llvm/Target/Target.td"
include "GraphSimRegisterInfo.td"
include "GraphSimInstrInfo.td"
include "GraphSimCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features>
 : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def GraphSimInstrInfo : InstrInfo;
def GraphSim : Target {
  let InstructionSet = GraphSimInstrInfo;
}
