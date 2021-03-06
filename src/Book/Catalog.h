// Catalog.h

#ifndef CATALOG_H

#define CATALOG_H

#include <QMap>
#include <QMultiMap>
#include <QString>
#include <QDateTime>
#include <QStringList>

class Catalog {
  // Catalog of files in the pages/ folder
public:
  Catalog(QString pgdir);
  QString path() const { return pgdir; }
  bool isValid() const { return ok; } // dir could be read
  bool isClean() const; // no errors and no duplicates
  QMultiMap<int, QString> const &pageToFileMap() const { return pg2file; }
  QDateTime fileMod(QString) const;
  bool hasNotes(QString) const;
  QDateTime noteDirMod(QString) const;
  QStringList errors() const { return err; }
private:
  QString pgdir;
  QMultiMap<int, QString> pg2file;
  QMap<QString, QDateTime> filemods;
  QMap<QString, QDateTime> notemods;
  bool ok;
  QStringList err;
};

#endif
