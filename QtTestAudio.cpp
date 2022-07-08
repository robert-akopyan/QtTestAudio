#include "QtTestAudio.h"
#include <QThread>
#include <QDebug>

QtTestAudio::QtTestAudio(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtTestAudioClass())
{
    ui->setupUi(this);

    rpm60 = true;
    rpm90 = false;

    audio = new L39_audio( );
    auto thread = new QThread( );
    QObject::connect( thread, SIGNAL( started( ) ), audio, SLOT( run( ) ), Qt::QueuedConnection );
    QObject::connect( audio, SIGNAL( loading( ) ), this, SLOT( on_loading( ) ), Qt::QueuedConnection );
    audio->moveToThread( thread );
    thread->start( );
    timer = new QTimer( this );
    connect( timer, SIGNAL( timeout()), this, SLOT( on_Timer()) );
    timer->setInterval( 20 );
}

QtTestAudio::~QtTestAudio()
{
    delete ui;
}

void QtTestAudio::on_RPM60_clicked( )
{
    qDebug( ) << __FUNCTION__;
    rpm60 = !rpm60;
}

void QtTestAudio::on_RPM90_clicked( )
{
    qDebug( ) << __FUNCTION__;
    rpm90 = !rpm90;
}

void QtTestAudio::on_sw_clicked( )
{
    qDebug( ) << __FUNCTION__;
    rpm90 = !rpm90;
    rpm90 = !rpm90;
}

void QtTestAudio::on_Timer( )
{
    audio->Play( L39_audio::RPM60, rpm60 );
    audio->Play( L39_audio::RPM90, rpm90 );
}

void QtTestAudio::on_loading( )
{
    qDebug( ) << __FUNCTION__;
    timer->start( );
}