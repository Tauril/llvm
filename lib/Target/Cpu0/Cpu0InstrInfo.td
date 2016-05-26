//===-- Cpu0InstrInfo.td -----------------------------------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//

include "Cpu0InstrFormats.td"

//===----------------------------------------------------------------------===//
// Describe constraints
//===----------------------------------------------------------------------===//

def addr : ComplexPattern<iPTR, 2, "SelectAddr", [], []>;
def mem : Operand<i32>;

//===----------------------------------------------------------------------===//
// Describe instructions
//===----------------------------------------------------------------------===//

// FIXME: Fix itineraries.

def NOP : FJ<0x0, (outs), (ins), "nop", [], NoItinerary>;

def LD : FL<0x1, (outs CPURegs:$ra), (ins mem:$addr),
            "ld\t$ra, $rb, $cx", [(set CPURegs:$ra, (load addr:$addr))],
            NoItinerary>;
