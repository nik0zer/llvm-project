// GraphSim Register file declaration
class GraphSimReg<bits<16> Enc, string n> : Register<n>{
    let HWEncoding = Enc;
    let Namespace = "GraphSim";
}

// Registers
foreach I = 0-15 in {
    def R#I : GraphSimReg<I, "r"#I>;
}

// Classes
def GPR : RegisterClass<"GraphSim", [i32], 32, (add
  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15)>;
