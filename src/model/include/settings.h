#ifndef _3DVIEWER_MODEL_INCLUDE_SETTINGS_H_
#define _3DVIEWER_MODEL_INCLUDE_SETTINGS_H_

#include <QSettings>
#include <QString>

#include "../../view/include/sceneparameters.h"

namespace s21 {

class MySettings {
 public:
  MySettings(const QString &path_file, QSettings::Format format_file);

  SceneParameters GetSettings();

  void UpdateSettings(const SceneParameters &scene_params);

 private:
  QSettings settings;
};

}  // namespace s21

#endif  // _3DVIEWER_MODEL_INCLUDE_SETTINGS_H_
