#ifndef L39_AUDIO_H
#define L39_AUDIO_H

#include <Windows.h>
#include <QObject>
#include <QCoreApplication>
#include <QDir>
#include "Audio.h"


class L39_audio : public T_Audio
{
    Q_OBJECT

public:
    enum audio
    {
        TA_START = 0, TA_WORK, TA_STOP, AKKUM, DVG_START, DVG_WORK, DVG_STOP, GEAR_ALARM, FLAPS, 
        ROLL, ROLL2MG, MG, MG2KR, KR, RPM60, RPM70, RPM80, RPM90, RPM100, MAX, MAX2OFF, KR2OFF, MG2OFF
    };

    L39_audio( QObject* parent = nullptr );
    ~L39_audio();
public slots:
    void run( );
signals:
    void loading( );
};


#endif // L39_AUDIO_H
