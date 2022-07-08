#pragma once

#include <QtWidgets/QWidget>
#include "L39_audio.h"

#include "ui_QtTestAudio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtTestAudioClass; };
QT_END_NAMESPACE

class QtTestAudio : public QWidget
{
    Q_OBJECT

public:
    QtTestAudio(QWidget *parent = nullptr);
    ~QtTestAudio();
private:
    Ui::QtTestAudioClass *ui;
    L39_audio* audio;
    QTimer* timer;
    bool rpm60;
    bool rpm90;
public slots:
    void on_RPM60_clicked( );
    void on_RPM90_clicked( );
    void on_sw_clicked( );
    void on_loading( );
    void on_Timer( );
};
