#ifndef WORDGAMECLASS_H
#define WORDGAMECLASS_H

#include <QObject>

class WordGameClass : public QObject {
private:
    Q_OBJECT
public:
    explicit WordGameClass(QObject *parent = nullptr);
    int cur = 0;
    int tar = 42;
    QString mes = "Результат будет здесь...";
    int quess(int n, int m) {
        if (n < m) {
            return 1;
        } else if (n > m) {
            return 2;
        } else if (n == m) {
            return 3;
        }
    }

signals:
    void on_newgame();
    void on_quessed();
    void win();
    void less();
    void more();

public slots:
    void new_game() {
        cur = 0;
    }

    void quessed() {
        if (quess(cur, tar) == 1) {
            emit more();
        } else if (quess(cur, tar) == 2) {
            emit less();
        } else if (quess(cur, tar) == 3){
            emit win();
        }
    }

    void on_win() {
        mes = "Вы угадали число! Вы молодец!\nПопробуйти еще раз!";
    }

    void on_less() {
        mes = "Искомое число меньше!";
    }

    void on_more() {
        mes = "Искомое число больше!";
    }

};

#endif // WORDGAMECLASS_H
