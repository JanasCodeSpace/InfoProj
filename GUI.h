#pragma once

#include <gtkmm/button.h>

class CGUI  : public QObject
{
	Q_OBJECT

public:
	CGUI(QWidget *parent);
	~CGUI();
};
