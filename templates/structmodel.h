/****************************************************************************
** This is an auto-generated file.
** Do not edit! All changes made to it will be lost.
****************************************************************************/

#pragma once

#include <QtCore>

#include "{{struct}}.h"

class {{struct}}Model : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    enum Roles { {{struct.members|map('upperfirst')|join(', ')}} };
    {{struct}}Model(QObject *parent=0);
    Q_INVOKABLE {{struct}} get(int index);
    int count() const;
    void insert{{struct}}(int row, const {{struct}} &{{struct|lower}});
    void update{{struct}}(int row, const {{struct}} &{{struct|lower}});
    void remove{{struct}}(int row);
public: // from QAbstractListModel    
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;    
Q_SIGNALS:
   void countChanged(int count);
private:
    QList<{{struct}}> m_data;
    QHash<int, QByteArray> m_roleNames;
};


