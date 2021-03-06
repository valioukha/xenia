/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_FS_DEVICES_HOST_PATH_DEVICE_H_
#define XENIA_KERNEL_FS_DEVICES_HOST_PATH_DEVICE_H_

#include <string>

#include "xenia/common.h"
#include "xenia/kernel/fs/device.h"

namespace xe {
namespace kernel {
namespace fs {

class HostPathDevice : public Device {
 public:
  HostPathDevice(const std::string& path, const std::wstring& local_path,
                 bool read_only);
  ~HostPathDevice() override;

  bool is_read_only() const { return read_only_; }

  std::unique_ptr<Entry> ResolvePath(const char* path) override;

 private:
  std::wstring local_path_;
  bool read_only_;
};

}  // namespace fs
}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_FS_DEVICES_HOST_PATH_DEVICE_H_
