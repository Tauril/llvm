//===-- Cpu0TargetMachine.h - Define TargetMachine for Cpu0 -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Cpu0 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_CPU0_CPU0TARGETMACHINE_H
#define LLVM_LIB_TARGET_CPU0_CPU0TARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"
#include <sstream>

namespace llvm {

extern llvm::Target TheCpu0TargetBig;
extern llvm::Target TheCpu0TargetLittle;

class Cpu0TargetMachine : public LLVMTargetMachine {
public:
  Cpu0TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options, Reloc::Model RM,
                    CodeModel::Model CM, CodeGenOpt::Level OL, bool isLittle);
};

class Cpu0ebTargetMachine : public Cpu0TargetMachine {
public:
  Cpu0ebTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options, Reloc::Model RM,
                    CodeModel::Model CM, CodeGenOpt::Level OL)
    : Cpu0TargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, false)
  {
  }
};

class Cpu0elTargetMachine : public Cpu0TargetMachine {
public:
  Cpu0elTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options, Reloc::Model RM,
                    CodeModel::Model CM, CodeGenOpt::Level OL)
    : Cpu0TargetMachine(T, TT, CPU, FS, Options, RM, CM, OL, true)
  {
  }
};

} // end namespace llvm

#endif
