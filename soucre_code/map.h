#ifndef MAP_H
#define MAP_H

#include <QWidget>

namespace Ui {
class map;
}

class map : public QWidget
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    ~map();
public slots:
    void new_label();
private:
    Ui::map *ui;
};

#endif // MAP_H
