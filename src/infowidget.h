#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QTreeWidget>
#include <QMap>

class InfoWidget : public QTreeWidget
{
    Q_OBJECT

private:
    QMap<QString, int> levels;

public:
    explicit InfoWidget(QWidget *parent = 0);
    
    void setTopLevelName(QString name);
    void addLevel(QString levelName);
    void addSublevel(QString levelName, QString sublevelName, QVariant value, QString units);

signals:
    
public slots:
    
};

#endif // INFOWIDGET_H
