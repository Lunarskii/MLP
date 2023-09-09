#include "settings.h"

namespace s21
{

Settings::Settings(const QString& organization, const QString& application)
	: settings_(new QSettings(organization, application))
	, count_(0)
	, current_index_(0)
{}

Settings::~Settings()
{
	delete settings_;
}

void Settings::SetValue(const QVariant& value)
{
	settings_->setValue(QString::number(count_++), value);
}

QVariant Settings::GetValue(const QVariant& default_value)
{
	return settings_->value(QString::number(current_index_++), default_value);
}

} // namespace s21
