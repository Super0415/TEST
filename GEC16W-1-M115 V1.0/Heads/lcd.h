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
PUBLIC void lcd_ge_conn(void);//�����𶯳ɹ�����
PUBLIC void lcd_password(void);//��������
PUBLIC void lcd_hi_set(void);//�߼���������
PUBLIC void lcd_hi_timers(void);//��ʱ������
PUBLIC void lcd_hi_mains(void);//�е�����
PUBLIC void lcd_hi_engine(void);//����������
PUBLIC void lcd_hi_gen(void);//���������
PUBLIC void lcd_loss_speed(void);//�ٶ��źŶ�ʧ
PUBLIC void lcd_act(void);//�趨�����ȼ�������ͣ�������Ǳ���
PUBLIC void lcd_set_rutine(void);//���������ӳ���
PUBLIC void lcd_crank_disconnect(void);//������
PUBLIC void lcd_gen_voltage(void);// �綯����ѹ����
PUBLIC void lcd_gen_freq(void);// �綯��Ƶ������
PUBLIC void lcd_gen_phase(void);// �綯����λ����
PUBLIC void lcd_load_ovcur(void);
PUBLIC void lcd_load_inverse_pwr(void);
PUBLIC void lcd_load_ov_pwr(void);
PUBLIC void lcd_hi_load(void);//��������
PUBLIC void lcd_ovcur_en(void);//����ʹ�ܼ���ֵ
PUBLIC void lcd_hi_switch(void);//��������
PUBLIC void lcd_hi_sensor(void);//ģ�⴫��������
PUBLIC void lcd_sensor_temp(void);//�¶ȴ���������
PUBLIC void lcd_sensor_op(void);//��ѹ����������
PUBLIC void lcd_sensor_level(void);//��ѹ����������
PUBLIC void lcd_sensor_cfg1(void);//�ɱ��1����������������
PUBLIC void lcd_sensor_cfg2(void);//�ɱ��2����������
PUBLIC void lcd_hi_di(void);//���������������
PUBLIC void lcd_hi_do(void);//�̵������������
PUBLIC void lcd_hi_module(void);// ģ������
PUBLIC void lcd_lose_speed(void);//�ٶ��źŶ�ʧ
PUBLIC void lcd_temp_type(void);//�¶ȴ�������������
PUBLIC void lcd_temp_over_stop(void);//�¶ȹ���ͣ������
PUBLIC void lcd_shutdown(void);//ͣ������ 
PUBLIC void lcd_alram(void);//��������
PUBLIC void lcd_custom_curve(void);//�û��Զ�������
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
