#ifndef monitoreddatamapper_H
#define monitoreddatamapper_H

#include <QDataWidgetMapper>

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE

/** Data to Widget mapper that watches for edits and notifies listeners when a field is edited.
   This can be used, for example, to enable a commit/apply button in a configuration dialog.
 */
class monitoreddatamapper : public QDataWidgetMapper
{
    Q_OBJECT
public:
    explicit monitoreddatamapper(QObject *parent=0);

    void addMapping(QWidget *widget, int section);
    void addMapping(QWidget *widget, int section, const QByteArray &propertyName);
private:
    void addChangeMonitor(QWidget *widget);

signals:
    void viewModified();

};



#endif // monitoreddatamapper_H
