// App/Navbar.H - This file is part of eln

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

// Navbar.H

#ifndef NAVBAR_H

#define NAVBAR_H

#include "Toolbar.h"

class Navbar: public Toolbar {
  Q_OBJECT;
public:
  Navbar(QGraphicsItem *parent);
  virtual ~Navbar();
  void showHelp();
  void setOnLastPage(bool lastPg, bool isEmpty);
signals:
  void goTOC(Qt::KeyboardModifiers);
  void goFind();
  void goEnd(Qt::KeyboardModifiers);
  void goRelative(int, Qt::KeyboardModifiers);
  // forward by n pages (n may be negative)
  void goPrint();
protected:
  virtual void doLeftClick(QString, Qt::KeyboardModifiers);
private:
  ToolItem *ti_n1, *ti_n10, *ti_end, *ti_plus;
};

#endif
