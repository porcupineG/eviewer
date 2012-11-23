#include "infodock.h"

InfoDock::InfoDock(const QString & title) :
    QDockWidget(title)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void InfoDock::viewInfoWidget(QWidget *widget)
{
    QWidget * last = this->widget();
    setWidget(widget);
    if (last != NULL) {
        delete last;
    }
    resize(widget->width(), widget->height());
    updateGeometry();
}
