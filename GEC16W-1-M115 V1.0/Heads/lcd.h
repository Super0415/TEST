#ifndef	_LCD_H
#define	_LCD_H
#pragma DATA_SEG DEFAULT

/*****************************************\
			public type definition
\*****************************************/
typedef void (*LCD_SCREEN)(void);
typedef union
{
	uchar Byte;
	struct
	{
		uchar lcd_need_clear					:1;
		uchar first_line_need_disp		:1;
		uchar lcd_change_page					:1;
		uchar lcd_curve_index					:1;
		uchar lcd_display_page				:4;
	}Bits;
}typLCD_FLAG;

/*****************************************\
			public macro definition
\*****************************************/
#define lcd_need_clear						lcd_flag.Bits.lcd_need_clear
#define first_line_need_disp     				lcd_flag.Bits.first_line_need_disp
#define lcd_change_page 				lcd_flag.Bits.lcd_change_page
#define lcd_curve_index				lcd_flag.Bits.lcd_curve_index
#define lcd_display_page		lcd_flag.Bits.lcd_display_page
/*****************************************\
			public variable definition
\*****************************************/
PUBLIC volatile LCD_SCREEN    lcd_state;
PUBLIC uint  lcd_disp_page;
PUBLIC typLCD_FLAG lcd_flag;
/*****************************************\
			public function prototyps
\*****************************************/

PUBLIC void hrdlcd_init(void);
PUBLIC void lcd_display(void);
PUBLIC void lcd_dummy(void);
PUBLIC void lcd_disp_status(void);
PUBLIC void lcd_disp_engine(void);
PUBLIC void lcd_disp_alarm(void);
PUBLIC void lcd_disp_gen(void);
PUBLIC void lcd_disp_main(void);
PUBLIC void lcd_disp_load(void);
PUBLIC void lcd_disp_his(void);
PUBLIC void lcd_disp_other(void);
PUBLIC void lcd_disp_about(void);
PUBLIC void lcd_general_set(void);
PUBLIC void lcd_ge_conn(void);//设置起动成功条件
PUBLIC void lcd_password(void);//输入密码
PUBLIC void lcd_hi_set(void);//高级参数设置
PUBLIC void lcd_hi_timers(void);//定时器设置
PUBLIC void lcd_hi_mains(void);//市电设置
PUBLIC void lcd_hi_engine(void);//发动机设置
PUBLIC void lcd_hi_gen(void);//发电机设置
PUBLIC void lcd_loss_speed(void);//速度信号丢失
PUBLIC void lcd_act(void);//设定报警等级，报警停机或者是报警
PUBLIC void lcd_set_rutine(void);//参数设置子程序
PUBLIC void lcd_crank_disconnect(void);//起动设置
PUBLIC void lcd_gen_voltage(void);// 电动机电压设置
PUBLIC void lcd_gen_freq(void);// 电动机频率设置
PUBLIC void lcd_gen_phase(void);// 电动机相位设置
PUBLIC void lcd_load_ovcur(void);
PUBLIC void lcd_load_inverse_pwr(void);
PUBLIC void lcd_load_ov_pwr(void);
PUBLIC void lcd_hi_load(void);//负载设置
PUBLIC void lcd_ovcur_en(void);//过流使能及阈值
PUBLIC void lcd_hi_switch(void);//开关设置
PUBLIC void lcd_hi_sensor(void);//模拟传感器设置
PUBLIC void lcd_sensor_temp(void);//温度传感器设置
PUBLIC void lcd_sensor_op(void);//油压传感器设置
PUBLIC void lcd_sensor_level(void);//油压传感器设置
PUBLIC void lcd_sensor_cfg1(void);//可编程1传感器传感器设置
PUBLIC void lcd_sensor_cfg2(void);//可编程2传感器设置
PUBLIC void lcd_hi_di(void);//开关量输入口设置
PUBLIC void lcd_hi_do(void);//继电器输出口设置
PUBLIC void lcd_hi_module(void);// 模块设置
PUBLIC void lcd_lose_speed(void);//速度信号丢失
PUBLIC void lcd_temp_type(void);//温度传感器曲线类型
PUBLIC void lcd_temp_over_stop(void);//温度过高停机设置
PUBLIC void lcd_shutdown(void);//停机设置 
PUBLIC void lcd_alram(void);//报警设置
PUBLIC void lcd_custom_curve(void);//用户自定义曲线
PUBLIC void lcd_op_type(void);
PUBLIC void lcd_level_type(void);
PUBLIC void lcd_cfg_type(void);
PUBLIC void lcd_cfg_sensor(void);
PUBLIC void lcd_di_set(void);
PUBLIC void lcd_do_set(void);
PUBLIC void lcd_module_power_on(void);
PUBLIC void lcd_module_language(void);
PUBLIC void lcd_mode_default(void);
//	PUBLIC void lcd_ele_trip_item3(void);
//	PUBLIC void lcd_puts_delay(uint sec_buf);
#endif
