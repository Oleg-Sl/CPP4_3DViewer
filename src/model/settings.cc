#include "include/settings.h"


namespace s21 {

MySettings::MySettings(const QString &path_file, QSettings::Format format_file) : settings(path_file, format_file) {
}

SceneParameters MySettings::GetSettings() {
    SceneParameters scene_params{};

    settings.beginGroup("Other");
    scene_params.type_projection = static_cast<SceneParameters::TypeProjection>(settings.value("projection", 0).toInt());
    scene_params.background_color = settings.value("background", QColor(Qt::white)).value<QColor>();
    settings.endGroup();

    settings.beginGroup("Edges");
    scene_params.edge_type = static_cast<SceneParameters::TypeEdges>(settings.value("type", 0).toInt());
    scene_params.edge_width = settings.value("width", 1).toInt();
    scene_params.edge_color = settings.value("color", QColor(Qt::red)).value<QColor>();
    settings.endGroup();

    settings.beginGroup("Vertex");
    scene_params.vertex_type = static_cast<SceneParameters::TypeVertex>(settings.value("type", 1).toInt());
    scene_params.vertex_size = settings.value("size", 3).toInt();
    scene_params.vertex_color = settings.value("color", QColor(Qt::blue)).value<QColor>();
    settings.endGroup();
    return scene_params;
}

void MySettings::UpdateSettings(const SceneParameters& scene_params) {
    settings.beginGroup("Other");
    settings.setValue("projection", QString::number(static_cast<int>(scene_params.type_projection)));
    settings.setValue("background", scene_params.background_color);
    settings.endGroup();

    settings.beginGroup("Edges");
    settings.setValue("type", QString::number(static_cast<int>(scene_params.edge_type)));
    settings.setValue("width", QString::number(scene_params.edge_width));
    settings.setValue("color", scene_params.edge_color);
    settings.endGroup();

    settings.beginGroup("Vertex");
    settings.setValue("type", QString::number(static_cast<int>(scene_params.vertex_type)));
    settings.setValue("size", QString::number(scene_params.vertex_size));
    settings.setValue("color", scene_params.vertex_color);
    settings.endGroup();

    settings.sync();
    }


} // namespace s21
