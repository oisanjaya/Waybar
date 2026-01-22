#pragma once

#include <fmt/format.h>

#include "AIconLabel.hpp"
#include "bar.hpp"
#include "client.hpp"

namespace waybar::modules {

class IdleInhibitor : public AIconLabel {
  sigc::connection timeout_;

 public:
  IdleInhibitor(const std::string&, const waybar::Bar&, const Json::Value&);
  virtual ~IdleInhibitor();
  auto update() -> void override;
  static std::list<waybar::AModule*> modules;
  static bool status;

 private:
  bool handleToggle(GdkEventButton* const& e) override;
  void toggleStatus();
  bool onIdleInhibitorQueryTooltip(int x, int y, bool keyboard_mode, const Glib::RefPtr<Gtk::Tooltip>& tooltip, std::string& data);

  const Bar& bar_;
  struct zwp_idle_inhibitor_v1* idle_inhibitor_;
  int pid_;
};

}  // namespace waybar::modules
