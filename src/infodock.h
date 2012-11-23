#ifndef INFODOCK_H
#define INFODOCK_H

#include <QDockWidget>

class InfoDock : public QDockWidget
{
    Q_OBJECT
public:
    explicit InfoDock(const QString & title);
    
signals:
    
public slots:
    void viewInfoWidget(QWidget * widget);
    
};

#endif // INFODOCK_H
