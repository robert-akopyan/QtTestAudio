#include "L39_audio.h"

L39_audio::L39_audio( QObject* parent ) : T_Audio( parent )
{
}

L39_audio::~L39_audio()
{

}

void L39_audio::run( )
{
	if ( QDir( ).exists( QCoreApplication::applicationDirPath( ).append( "/wav/" ) ) )
	{
		sounds.reserve( 23 );
		sounds.push_back( new TSound( 0, "/wav/ta_start.wav" ) );	//0
		sounds.push_back( new TSound( 1, "/wav/ta_work.wav" ) );	//1 
		sounds.push_back( new TSound( 2, "/wav/ta_stop.wav" ) );	//2 
		sounds.push_back( new TSound( 3, "/wav/akkum.wav" ) );		//3
		sounds.push_back( new TSound( 4, "/wav/dvg_start.wav" ) );	//4
		sounds.push_back( new TSound( 5, "/wav/dvg_work.wav" ) );	//5
		sounds.push_back( new TSound( 6, "/wav/dvg_stop.wav" ) );	//6
		sounds.push_back( new TSound( 7, "/wav/gear_alarm.wav" ) );//7
		sounds.push_back( new TSound( 8, "/wav/flaps.wav" ) );		//8
		sounds.push_back( new TSound( 9, "/wav/roll.wav" ) );		//9
		sounds.push_back( new TSound( 10, "/wav/roll2mg.wav" ) );	//10
		sounds.push_back( new TSound( 11, "/wav/mg.wav" ) );		//11
		sounds.push_back( new TSound( 12, "/wav/mg2kr.wav" ) );		//12
		sounds.push_back( new TSound( 13, "/wav/kr.wav" ) );		//13
		sounds.push_back( new TSound( 14, "/wav/60.wav" ) );		//14
		sounds.push_back( new TSound( 15, "/wav/70.wav" ) );		//15
		sounds.push_back( new TSound( 16, "/wav/80.wav" ) );		//16
		sounds.push_back( new TSound( 17, "/wav/90.wav" ) );		//17
		sounds.push_back( new TSound( 18, "/wav/100.wav" ) );		//18
		sounds.push_back( new TSound( 19, "/wav/max.wav" ) );		//19
		sounds.push_back( new TSound( 20, "/wav/max2off.wav" ) );	//20
		sounds.push_back( new TSound( 21, "/wav/kr2off.wav" ) );	//21
		sounds.push_back( new TSound( 22, "/wav/mg2off.wav" ) );	//22
	}
	Init( );
	emit loading();
}
