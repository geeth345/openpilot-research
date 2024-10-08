//
// Created by geeth on 7/20/24.
//
#pragma once

#include <QWidget>
#include <vector>

#include "selfdrive/ui/ui.h"

class Profile : public QWidget {
  Q_OBJECT

public:
  Profile(QWidget *parent = 0) : QWidget(parent) {}
  void updateState(const UIState &s);
  void clear();


protected:
  struct ProfileStatus {
    std::vector<QString> texts;

    bool equal(const ProfileStatus &other) const {
      return texts == other.texts;
    }
  };

  void paintEvent(QPaintEvent*) override;
  ProfileStatus getProfileStatus(const SubMaster &sm, uint64_t started_frame);

  ProfileStatus profile = {};
};

