// Scenes/DefaultingQTI.h - This file is part of eln

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

// DefaultingQTI.h

#ifndef DEFAULTINGQTI_H

#define DEFAULTINGQTI_H

#include <QGraphicsTextItem>

class DefaultingQTI: public QGraphicsTextItem {
  Q_OBJECT;
public:
  DefaultingQTI(QString dflttxt, QGraphicsItem *parent=0);
  virtual ~DefaultingQTI();
  virtual QRectF boundingRect() const;
  void setFont(QFont);
  void setDefaultText(QString);
  void paint(QPainter *painter,
	     const QStyleOptionGraphicsItem *option,
	     QWidget *widget);
protected:
  virtual void focusInEvent(QFocusEvent *);
  virtual void focusOutEvent(QFocusEvent *);
private:
  QString dt;
};

#endif
