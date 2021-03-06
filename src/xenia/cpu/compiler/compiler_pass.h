/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_COMPILER_COMPILER_PASS_H_
#define XENIA_COMPILER_COMPILER_PASS_H_

#include "xenia/cpu/hir/hir_builder.h"
#include "poly/arena.h"

namespace xe {
namespace cpu {
class Runtime;
}  // namespace cpu
}  // namespace xe

namespace xe {
namespace cpu {
namespace compiler {

class Compiler;

class CompilerPass {
 public:
  CompilerPass();
  virtual ~CompilerPass();

  virtual int Initialize(Compiler* compiler);

  virtual int Run(hir::HIRBuilder* builder) = 0;

 protected:
  poly::Arena* scratch_arena() const;

 protected:
  Runtime* runtime_;
  Compiler* compiler_;
};

}  // namespace compiler
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_COMPILER_COMPILER_PASS_H_
