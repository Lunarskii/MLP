#ifndef CPP7_MLP_VIEW_SETTINGS_H_
#define CPP7_MLP_VIEW_SETTINGS_H_

#include <QSettings>

namespace s21
{

class Settings
{
public:
    Settings(const QString& organization, const QString& application);
    ~Settings();
    void SetValue(const QVariant& value);
    QVariant GetValue(const QVariant& default_value);
private:
    QSettings* settings_;
    std::size_t count_;
    std::size_t current_index_;
};

} // namespace s21

#endif // CPP7_MLP_VIEW_SETTINGS_H_
