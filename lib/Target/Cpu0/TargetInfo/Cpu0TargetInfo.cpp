//===-- Cpu0TargetInfo.cpp - Cpu0 Target Implementation -------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
#include "Cpu0TargetMachine.h"
using namespace llvm;

Target llvm::TheCpu0TargetBig;
Target llvm::TheCpu0TargetLittle;

extern "C" void LLVMInitializeCpu0TargetInfo() {
  RegisterTarget<Triple::cpu0,
        /*HasJIT=*/false> X(TheCpu0TargetBig, "cpu0", "Cpu0");

  RegisterTarget<Triple::cpu0el,
        /*HasJIT=*/false> Y(TheCpu0TargetLittle, "cpu0el", "Cpu0el");
}
