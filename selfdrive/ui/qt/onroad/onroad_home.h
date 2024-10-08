#pragma once

#include "selfdrive/ui/qt/onroad/alerts.h"
#include "selfdrive/ui/qt/onroad/profile.h"
#include "selfdrive/ui/qt/onroad/annotated_camera.h"

class OnroadWindow : public QWidget {
  Q_OBJECT

public:
  OnroadWindow(QWidget* parent = 0);

private:
  void resizeEvent(QResizeEvent *event);
  void paintEvent(QPaintEvent *event);
  OnroadAlerts *alerts;
  Profile *profileInfo;
  AnnotatedCameraWidget *nvg;
  QColor bg = bg_colors[STATUS_DISENGAGED];
  QHBoxLayout* split;
  QWidget *profileInfoBox;

private slots:
  void offroadTransition(bool offroad);
  void updateState(const UIState &s);
};
