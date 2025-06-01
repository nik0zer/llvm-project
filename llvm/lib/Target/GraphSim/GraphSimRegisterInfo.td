// GraphSim Register file declaration
class GraphSimReg<bits<16> Enc, string n> : Register<n>{
    let HWEncoding = Enc;
    let Namespace = "GraphSim";
}

// Registers
foreach I = 0-15 in {
    def X#I : GraphSimReg<I, "x"#I>;
}

// Classes
def GPR : RegisterClass<"GraphSim", [i32], 32, (add
  X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15)>;
