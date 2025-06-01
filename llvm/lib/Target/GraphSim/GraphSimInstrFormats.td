//===----------------------------------------------------------------------===//
//  Describe GraphSim instructions format
//
//  CPU INSTRUCTION FORMATS
//
//  FF FF FF FF
//        ^^ ^^ - r3_imm - third reg or imm
//      ^       - r2     - second reg
//     ^        - r1     - first reg
//  ^^          - opcode - operation code
//
//===----------------------------------------------------------------------===//

// Generic GraphSim Format
class GraphSimInst<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern>: Instruction
{
  // Inst and Size: for tablegen(... -gen-emitter) and
  // tablegen(... -gen-disassembler) in CMakeLists.txt
  let Namespace = "GraphSim";
  let DecoderNamespace = "GraphSim";
  let Size = 4;

  field bits<32> Inst;

  bits<8> Opcode = op;
  bits<4>  r1;
  bits<4>  r2;
  bits<16> r3_imm;

  let Inst{7-0} = Opcode;
  let Inst{11-8} = r1;
  let Inst{15-12} = r2;
  let Inst{31-16}  = r3_imm;

  let OutOperandList = outs;
  let InOperandList  = ins;
  let AsmString   = asmstr;
  let Pattern     = pattern;

}

// Pseudo instructions format
class GraphSimPseudoInst<dag outs, dag ins, string asmstr, list<dag> pattern>
   : GraphSimInst<0, outs, ins, asmstr, pattern> {
  let isPseudo = 1;
  let isCodeGenOnly = 1;
}
