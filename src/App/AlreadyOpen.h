// App/AlreadyOpen.H - This file is part of eln

/* eln is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   eln is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with eln.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ALREADYOPEN_H

#define ALREADYOPEN_H

#include <QObject>
#include <QPointer>
#include <QList>

class AlreadyOpen: public QObject {
  Q_OBJECT;
public:
  static bool check(QString fn);
public:
  AlreadyOpen(QString fn, class QWidget *parent);
  virtual ~AlreadyOpen();
private slots:
  void raise();
  void addEditor(QWidget *);
  void dropEditor(QObject *);
private:
  QList<QPointer<QWidget> > toBeRaised;
  class QLocalServer *server;
};

#endif
