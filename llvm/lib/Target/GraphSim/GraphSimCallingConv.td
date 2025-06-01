//===----------------------------------------------------------------------===//
 // This describes the calling conventions for GraphSim architecture.
 //===----------------------------------------------------------------------===//

 //===----------------------------------------------------------------------===//
 // GraphSim Return Value Calling Convention
 //===----------------------------------------------------------------------===//
 def RetCC_GraphSim : CallingConv<[
   // i32 return values
   CCIfType<[i32, i64], CCAssignToReg<[X9, X10, X11, X12]>>,

   // Integer values get stored in stack slots that are 4 bytes in
   // size and 4-byte aligned.
   CCIfType<[i64], CCAssignToStack<8, 4>>,
   CCIfType<[i32], CCAssignToStack<4, 4>>
 ]>;

 //===----------------------------------------------------------------------===//
 // GraphSim Argument Calling Conventions
 //===----------------------------------------------------------------------===//
 def CC_GraphSim : CallingConv<[
   // Promote i8/i16 arguments to i32.
   CCIfType<[i8, i16], CCPromoteToType<i32>>,

   // The first 4 integer arguments are passed in integer registers.
   CCIfType<[i32, i64], CCAssignToReg<[X9, X10, X11, X12]>>,

   // Integer values get stored in stack slots that are 4 bytes in
   // size and 4-byte aligned.
   CCIfType<[i64], CCAssignToStack<8, 4>>,
   CCIfType<[i32], CCAssignToStack<4, 4>>
 ]>;

 def CSR_GraphSim : CalleeSavedRegs<(add X0, X1, X3, X5, X6, X7, X8)>;
