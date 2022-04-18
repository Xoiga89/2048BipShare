/*
   Application template for Amazfit Bip BipOS
   (C) Maxim Volkov  2019 <Maxim.N.Volkov@ya.ru>

   Game 2048 for Amazfit Bip BipOS
   (C) Claudio Benvenuti  2019 <claudio.benvenuti@gmail.com>

*/

#ifndef __APP_2048_H__
#define __APP_2048_H__

#define	FIRST_MENU_BIG_DIGITS_COORD_X	70
#define	FIRST_MENU_BIG_DIGITS_COORD_Y	60

#define ICON1_RES_ID	98
#define ICON2_RES_ID	99
#define ICON_COORD_X	0
#define ICON_COORD_Y	8

#define	BIG_DIGITS_COORD_X	33
#define	BIG_DIGITS_COORD_Y	5

#define	STATS_COORD_X	90
#define	STATS_COORD_Y	5

#define	SCALE_OFFSET	30

//	параметры отображения
#define DISPLAY_UPDATE_PERIOD	300		//	через каждые 100 мс обновление экрана
#define DISPLAY_SPLASH_PERIOD	2000	//	через 2000 мс убрать заставку

// режим датчиков
#define SENSOR_DISABLE			0
#define SENSOR_ENABLE			1

// состояние датчика
#define SENSOR_GPS_DISABLED		2
#define SENSOR_GPS_NOT_FIXED	3
#define SENSOR_GPS_FIXED		4

// графические ресурсы
#define RES_SPLASH				0
#define RES_GPS_DISABLED		1
#define RES_GPS_NOT_FIXED		2
#define RES_GPS_FIXED			3
#define RES_SETTINGS			4
#define RES_GPS_ADDPOINT		5

// кнопки и тач области экрана
#define BTN_NONE				0
#define BTN_GPS_TOGGLE			1
#define BTN_TIME				2
#define BTN_SETTINGS			3
#define BTN_GPS_SET_POINT		4
#define BTN_PRESSURE_TOGGLE		5
	
// единицы давления	
#define PRESS_UNITS_COUNT		2			//	количество опций
#define PRESS_UNITS_HPA			0			//	первая
#define PRESS_UNITS_MMHG		1			//	вторая

// hệ số chuyển đổi từ Pascals
#define PRESS_TO_in.h20			0.00402		//	конвертирование давления в гектопаскали
#define PRESS_TO_MMHG			133.322F	//	конвертирование давления в мм ртутного столба

// варианты опций
#define SAVE_BAT_MODE_OFF	0
#define SAVE_BAT_MODE_ON	1



#pragma pack(push, 1)		//	запретить выравнивание полей структуры
typedef struct {
	char sig[4];		//	сигнатура NAVI
	char save_bat_mode;	//	режим экономии батареи включен
	char press_units;	//	единицы измерения давления
	float press_cal;	//	калибровочный коэффициент давления
} options_;
#pragma pack(pop)

struct app_data_ {
  void* 	ret_f;
  struct game;
  int		col;	//the current color of the font
  short screen;
  Elf_proc_* proc;
  int        state_hash;
  int        current_screen;
  int		frame;					//	текущий кадр
  int 	status,					//	
					menu_is_on,				//	открыто ли первичное меню
					menu_stage,				//	стадия первичного меню
					pix_per_rec,			//	количество пикселей на одну запись
					curX,					//	текущий X
					curY,					// 	текущий Y
					rec_counter,			//	счетчик записей
					weather_dem,
					weather_dem_man,
					//weather_dem_cao,
					rec_counter_per_screen,	//	счетчик записей для рисования горизонтальных линий
					anim_counter,			//	счетчик для анимации
					seconds_between_rec,	//	задержка между измерениями в секундах
					minutes_for_rec,		//	ограничение по времени работы в минутах
					backlight,				//	включена ли подсветка или нет
					curr_update_period,		//	текущее время обновления экрана
					weather[1000],
					//weather_cao[1000],
					records[1000];			//	массив записей
			long	curr_time;				// thời điểm hiện tại
			char 				splash;			//	активный приветственный экран
			char				sensor_mode;	//	текущий режим сенсора
			char 				notif_type;		//	экспериментально тип уведомления
			char 	store_point_btn_visible;	//	видимость кнопки установки путевой точки
			char 	store_point_delayed;		//	флаг необходимости установить точку
			int 				last_tick;		//	метка данных времени последней отрисовки интерфейса
			options_			options;		//	настройки
			struct 	menu_struct	menu;			//	структура меню приложения
			navi_struct_		navi_data;		//	структура данных геолокации и давления

};

struct settings_ {
			int		pix_per_rec,			//	количество пикселей на одну запись
					seconds_between_rec,	//	задержка между измерениями в секундах
					minutes_for_rec,		//	ограничение по времени работы в минутах
					backlight,			//	включена ли подсветка или нет
					sleep,
					deep,
					nhe,
					tinh;
					int beginhour;
		int beginmin;
		int endhour;
		int endmin;
};

int dp;
int li;
int sl;
int ti;
int h; //light
int j; //deep
int k;  //Tinh
int l;   //Sleep
int afhour,
	afmin,
	edhour,
	edmin;
int anfanghour,
	anfangmin,
	endenhour,
	endenmin;
int GE3,
	GE10,
	US10,
	US3,
	GB10,
	GB3;
	
 



unsigned short randint( short max );
void draw_button(int from_x, int from_y, int to_x, int to_y);
void ask_confirmation(); //6
void chon_lua(); //7

void 	show_screen (void *return_screen);
void 	key_press_screen();
int 	dispatch_screen (void *param);
void 	screen_job();
void draw_board(); //1
void  draw_screen();
void draw_score_screen(); //2
//void draw_score_screen_2(); //22
//Dong ho the gioi
void thegioi1();  //8
void thegioi2();  //9
//Do giac ngu
void takenap(); //10
int takenap_cal();
void takenap_result();
void menu();
void redraw_screen(); //11
int nap_job();
int nap_job_wrapper();
void update_settings();
int find_sum();
int find_avg();
int find_max();
int find_min();
void ketqua(); //16
int deep_them;
int ngu_them;
int time_change;
//Do vo2max
int tim_cal(); //14
void tim(); //13
void tim_result(); //15
int find_vmax();
int find_hr();
//int find_body_temp();
//Do Thoi tiet
void 	key_long_press();	
int		shut_down_navi();
void weather_result(); //19
void weather(); //17
int weather_job();
void weather_screen(); //18
int find_pressure();
int pressure_2();
int pressure_1();
void weather2(); //21
void weather1(); //20
int pressure2;
int pressure1;
//int high1();


/*
  small hack: decide if we should re-render screen
  we calculate state_hash and compare to the old one
*/
int should_update_status(struct app_data_ *app_data) {
  struct datetime_ dt; get_current_date_time(&dt);
  int state_hash = (dt.hour << 2) + dt.min + dt.sec;
  if (app_data->state_hash == state_hash) {
    return 0;
  } else {
    app_data->state_hash = state_hash;
    return 1;
  }
}
#endif
