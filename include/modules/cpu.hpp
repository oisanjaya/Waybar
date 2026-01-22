#pragma once

#include <fmt/format.h>

#include <cstdint>
#include <fstream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

#include "AIconLabel.hpp"
#include "util/sleeper_thread.hpp"

namespace waybar::modules {

class Cpu : public AIconLabel {
  bool onCpuQueryTooltip(int x, int y, bool keyboard_mode, const Glib::RefPtr<Gtk::Tooltip>& tooltip, std::string& data);
 public:
  Cpu(const std::string&, const Json::Value&);
  virtual ~Cpu() = default;
  auto update() -> void override;

 private:
  std::vector<std::tuple<size_t, size_t>> prev_times_;

  util::SleeperThread thread_;
};

}  // namespace waybar::modules
