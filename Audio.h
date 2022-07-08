#ifndef AUDIO_H
#define AUDIO_H

#include <Windows.h>
#include <QObject>
#include <QAudioOutput>
#include <QFile>
#include <QBuffer>
#include <QVector>
#include <QTimer>
//#include <vector>


//const BYTE N_SOUNDS = 20;
// Информация о структуре файлов WAV

struct WAVFILEHEADER
{
	// заголовок риффа
	char RiffName[4];
	unsigned long nRiffLength;
	// идентификатор типа данных
	char WavName[4];
	// Блок в блоке формата
	char FmtName[4];
	unsigned long nFmtLength;
	// Блокировать данные в блоке формата
	unsigned short nAudioFormat;
	unsigned short nChannleNumber;
	unsigned long nSampleRate;
	unsigned long nBytesPerSecond;
	unsigned short nBytesPerSample;
	unsigned short nBitsPerSample;
	// Блок в блоке данных
	char    DATANAME[4];
	unsigned long   nDataLength;
};

class TSound : public QObject
{
	Q_OBJECT
public:
	TSound( int index, QString name );
	int		index;	 // номер трека
	QString URL;     // путь к файлу
	float   VOL;     // громкость
	bool    MIX;     // звук в треке
	bool    REP;     // повтор семпла
	int     fading;  // затухение трека
	QFile   File;
	QAudioOutput* audioOutput;
signals:
	void stoping( int i );
private slots:
	void On_StateChanget( QAudio::State state );
};

class T_Audio : public QObject
{
	Q_OBJECT

public:
	T_Audio( QObject* parent = nullptr );
	~T_Audio( );
	bool SoundsEnabled;
	void Play( int num, bool play );
	void PlayOnce( int num );
	void Stop( int num );
	void StopAll( );
	void Init( );

protected:
	QVector<TSound*> sounds;
	void LoadSounds( );

signals:
	void play_once( int i );
	void play( int i );
	void stop( int i );
	void stop_all( );
	void ending( int i );

private slots:
	void On_PlayOnce( int num );
	void On_Play( int i );
	void On_Stop( int i );
};

#endif // AUDIO_H
