//===-- Cpu0TargetMachine.cpp - Define TargetMachine for Cpu0 00-----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

#include "Cpu0TargetMachine.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeCpu0Target() {
  // Register the target.
  RegisterTargetMachine<Cpu0ebTargetMachine> X(TheCpu0TargetBig);
  RegisterTargetMachine<Cpu0elTargetMachine> Y(TheCpu0TargetLittle);
}

static std::string computeDataLayout(const Triple &TT) {
  std::stringstream ss;
  ss << (TT.getArch() == Triple::cpu0el ? "e" : "E");
  ss << "-p:32:32";
  return ss.str();
}

static Reloc::Model getEffectiveRelocModel(Optional<Reloc::Model> RM) {
  if (!RM.hasValue())
    return Reloc::Static;
  return *RM;
}

Cpu0TargetMachine::Cpu0TargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     Optional<Reloc::Model> RM,
                                     CodeModel::Model CM, CodeGenOpt::Level OL,
                                     bool isLittle)
    : LLVMTargetMachine(T, computeDataLayout(TT), TT, CPU, FS, Options,
                        getEffectiveRelocModel(RM), CM, OL) {}
