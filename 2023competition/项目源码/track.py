"""
实时圆形特征检测例程：使用霍夫变换算法
"""
# 导入相应的库
import sensor, image, time

# 初始化摄像头
sensor.reset()

# 设置采集到照片的格式：彩色RGB，使用灰色图像会加快检测速度
sensor.set_pixformat(sensor.RGB565)

# 设置采集到照片的大小： 320 * 240
sensor.set_framesize(sensor.QQVGA)

# 等待一段时间2s，等摄像头设置好
sensor.skip_frames(time = 2000)

# 创建一个时钟来计算摄像头每秒采集的帧数FPS
clock = time.clock()

# 实时显示摄像头拍摄的照片
while(True):
	# 更新FPS时钟
	clock.tick()
	
	# 拍摄图片并返回img, lens_corr()目的是去畸变，1.8是默认值
	img = sensor.snapshot().lens_corr(1.8)

	# 检测圆形, 并在图像上画出。 parms时检测圆形返回的对象参数，包括圆心（x,y）, 半径( r), 量级（magnitude）
	for params in img.find_circles(threshold = 2000,
								   x_margin = 10, y_margin = 10, r_margin = 10,
								   r_min = 2, r_max = 100,
								   r_step = 2):
		# 将圆画出来
		img.draw_circle(params.x(), params.y(), params.r(), color = (255, 0, 0))

		# 将圆的参数信息打印出来
		print(params)

	# 串口打印FPS参数
	print(clock.fps())
