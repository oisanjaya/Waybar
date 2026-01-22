#pragma once

#include <fmt/format.h>

#include <fstream>

#include "AIconLabel.hpp"
#include "util/sleeper_thread.hpp"

namespace waybar::modules {

class Temperature : public AIconLabel {
 public:
  Temperature(const std::string&, const Json::Value&);
  virtual ~Temperature() = default;
  auto update() -> void override;

 private:
  float getTemperature();
  bool isCritical(uint16_t);
  bool isWarning(uint16_t);
  bool onTemperatureQueryTooltip(int x, int y, bool keyboard_mode, const Glib::RefPtr<Gtk::Tooltip>& tooltip, std::string& data);

  std::string file_path_;
  util::SleeperThread thread_;
};

}  // namespace waybar::modules
