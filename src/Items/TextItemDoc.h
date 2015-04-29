// TextItemDoc.H

#ifndef TEXTITEMDOC_H

#define TEXTITEMDOC_H

#include <QObject>

#include <QFont>
#include <QColor>
#include <QRectF>
#include <QMap>

class TextItemDoc: public QObject {
  Q_OBJECT;
public:
  static TextItemDoc *create(class TextData *data, QObject *parent=0);
  TextItemDoc(class TextData *data, QObject *parent=0);
  // Properties
  /* Setting a property does _not_ trigger automatic relayout. You must
     call relayout() directly.
  */
  ~TextItemDoc();
  void setFont(QFont const &f);
  QFont font() const;
  void setIndent(double pix);
  double indent() const;
  void setLeftMargin(double pix);
  double leftMargin() const;
  void setRightMargin(double pix);
  double rightMargin() const;
  void setWidth(double pix);
  double width() const;
  void setLineHeight(double pix);
  double lineHeight() const;
  void setColor(QColor const &c);
  QColor color() const;
  bool isEmpty() const;
  // Other functions
  QChar characterAt(int pos) const;
  QRectF boundingRect() const;
  QString text() const;
  QVector<int> lineStarts() const;
  int lineStartFor(int pos) const;
  int lineEndFor(int pos) const;
  void relayout(bool preserveWidths=false);
  void partialRelayout(int startOffset, int endOffset);
  void setSelection(class TextCursor const &c);
  void clearSelection();
  void render(class QPainter *, QRectF roi=QRectF()) const;
  int find(QPointF p, bool strict=false) const;
  /* Return offset from graphical position.
     If STRICT is set, points outside the bounding rectangle return -1.
     Otherwise, they get clamped to beginning/end of line for x violations,
     or to start/end of document for y violations.
  */
  QPointF locate(int offset) const; // returns the location of the given
  // offset. The location will be on the baseline of the line of text.
  void insert(int offset, QString text);
  void remove(int offset, int length);
  int find(QString) const; // offset or -1
  void makeWritable();
signals:
  void contentsChange(int pos, int nDel, int nIns);
private:
  class TextItemDocData *d;
};

#endif
