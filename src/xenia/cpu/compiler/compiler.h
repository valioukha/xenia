/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_COMPILER_COMPILER_H_
#define XENIA_COMPILER_COMPILER_H_

#include <memory>
#include <vector>

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

class CompilerPass;

class Compiler {
 public:
  Compiler(Runtime* runtime);
  ~Compiler();

  Runtime* runtime() const { return runtime_; }
  poly::Arena* scratch_arena() { return &scratch_arena_; }

  void AddPass(std::unique_ptr<CompilerPass> pass);

  void Reset();

  int Compile(hir::HIRBuilder* builder);

 private:
  Runtime* runtime_;
  poly::Arena scratch_arena_;

  std::vector<std::unique_ptr<CompilerPass>> passes_;
};

}  // namespace compiler
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_COMPILER_COMPILER_H_
