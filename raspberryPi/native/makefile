TARGET = helloRaspberry switch_led device_gpio interrupt led_pwm tone_buzzer i2c_rgb_led i2c_rgb_led_switch i2c_servo fnd_cnt pir_cnt touch_ATQT1070 temp_humi gyro_cnt led_piezo_gyro gyro_detector


all : ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}


clean :
	rm ${TARGET}