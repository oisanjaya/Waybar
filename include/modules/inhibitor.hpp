#pragma once

#include <gio/gio.h>

#include <memory>

#include "AIconLabel.hpp"
#include "bar.hpp"

namespace waybar::modules {

class Inhibitor : public AIconLabel {
 public:
  Inhibitor(const std::string&, const waybar::Bar&, const Json::Value&);
  virtual ~Inhibitor();
  auto update() -> void override;
  auto activated() -> bool;

 private:
  auto handleToggle(::GdkEventButton* const& e) -> bool override;
  bool onInhibitorQueryTooltip(int x, int y, bool keyboard_mode, const Glib::RefPtr<Gtk::Tooltip>& tooltip, std::string& data);

  const std::unique_ptr<::GDBusConnection, void (*)(::GDBusConnection*)> dbus_;
  const std::string inhibitors_;
  int handle_ = -1;
};

}  // namespace waybar::modules
