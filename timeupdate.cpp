#include "timeupdate.h"
#include <QDebug>
#include <QDateTime>

TimeUpdate::TimeUpdate(QObject *parent) : QObject(parent)
{
    QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(notify()));
}

void TimeUpdate::notify()
{
    qDebug() << QDateTime::currentDateTime();
    QVariant currentDateTime(QDateTime::currentDateTime().toString());
    emit currentTime(currentDateTime);
}

void TimeUpdate::startTimer()
{
    mTimer.start(1000);
    emit timerStarted();
}

void TimeUpdate::stopTimer()
{
    mTimer.stop();
    emit timerStopped();
}


