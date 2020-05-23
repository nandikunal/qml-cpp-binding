#ifndef TIMEUPDATE_H
#define TIMEUPDATE_H

#include <QTimer>
#include <QObject>
#include <QVariant>

class TimeUpdate : public QObject
{
    Q_OBJECT
public:
    explicit TimeUpdate(QObject *parent = nullptr);

signals:
    void currentTime(QVariant currentDateTime);
    void timerStarted();
    void timerStopped();

public slots:
    void notify();
    void startTimer();
    void stopTimer();

private:
    QTimer mTimer;
};

#endif // TIMEUPDATE_H
