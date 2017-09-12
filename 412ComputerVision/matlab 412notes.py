；：分号，不显示结算结果
cameraCalibrator： 估算相机的参数

detectFeatures: 各种抽取特征 
detectSURFFeatures: 提取特征方法，类似harris,但增加了方向向量
detectMSERFeatures: 提取特征方法，类似harris，但把方向向量固定向上
detectHarrisFeatures: 找出corner特征
	点不够可以增加strongest的数字
	还可以用 imadjust 增强黑白，减少灰色地带
detectMinEigenFeatures: 特征检测，跟Harris差不多
detectFASTFeatures: 特征检测，跟Harris差不多

doc: 查看帮助 
estimateGeometricTransform: 在拼合两张图片时 排除一些不好的连接点
fullfile： 转译地址为matlab可以读取的地址
imageDatastore: 存储多个图片文件 
	读取 I1 = readimage(images, 1);
imshowpair: 两个图片对比显示
imwarp: 对图形进行变形 如倾斜 旋转 	

matchFeatures: 匹配特征
legend: 显示图示，放在角落表示每个符号意思的方块
vision.PointTracker: 
showMatchedFeatures: 显示匹配特征
undistortImage:消除相机带来的边缘变形


rand:生产随机数
	生产49-49-3 的随机数
	A = rand(49,49);
	A(:,:,2) = rand(49,49);
	A(:,:,3) = rand(49,49);、
fspecial('motion',5,5)
	motion is type of filter
	second para is the length of the blur
	thrid para is the degree of tilt
imfilter(originalRGB, h, 'replicate');
	'replicate' is to deal with boundary - copy the nearest pixels
plot:画图
	plot(x,y)
	plot(x,y,'*')
	plot(x,y,'LineWidth',3) %%增加线宽
	显示颜色块：plot(regions,'showPixelList',true,'showEllipses',false);
doc： 显示帮助页
	doc plot
help: 显示帮助信息
	help plot
whos:显示变量或相关信息
save：保存数据
	save mydata
load：加载数据
	load mydata
	load('mydata.mat')
clear：清楚数据
	clear x
	clear
imread:读取文件
	A = imread('ngc6543a.jpg');
	读取特定位置
		A = imread('corn.tif','PixelRegion',{[1,2],[2,5]});
		只能读取tif的1-2行和2-5列，png格式不行
image:显示图片
	A = imread('ngc6543a.jpg');
	image(A)
isempty:判断是否为空
	if ~isempty(map)
		im = ind2rgb(X,map);
	end
ind2rgb:转成rgb图片
	[X,map] = imread('corn.tif');
	if ~isempty(map)
		Im = ind2rgb(X,map);
	end
imwrite:保存文件
	A = rand(50);
	imwrite(A,'myGray.png')
	imwrite(X,map,'myclown.png') %% X 是图像，map有点像滤镜
	把图像变成 铜色
		newmap = copper(81);
		imwrite(X,newmap,'copperclown.png');
	增加comment
		imwrite(A,'newImage.jpg','jpg','Comment','My JPEG file')
	追加到前面的图中
		imwrite(im1,'myMultipageFile.tif')
		imwrite(im2,'myMultipageFile.tif','WriteMode','append')
imfinfo：查看图片信息
	imfinfo('newImage.jpg')、
imshow：显示图片
	imshow('peppers.png');
	显示灰度图片
		RGB = imread('peppers.png');
		I = rgb2gray(RGB);
		imshow(I)
	显示带map的图片
		[X,map] = imread('corn.tif');
		imshow(X,map)
rgb2gray:变成灰度图片
	RGB = imread('peppers.png');
	I = rgb2gray(RGB);
	imshow(I)
CodingMethod:查看文件编码形式
	imfinfo('newImage.jpg')
	info.CodingMethod
title：添加标题
	title(['y = x^n,  n = ' num2str(n) ])
	title('original picture')
imagesc：显示分块的色图
	数组中最大的数颜色为黄，最小为深紫
	先行后列
	a = [1 2 3] 是三列
	基本例子
		C = [0 2 4 6; 8 10 12 14; 16 18 20 22];
		imagesc(C)
		colorbar
	显示x轴和y轴
		x = [5 8]; %%x轴小格显示5-8
		y = [3 6]; %%y轴小格显示6-3
		C = [0 2 4 6; 8 10 12 14; 16 18 20 22];
		imagesc(x,y,C)
	调节色度条的数据范围
		C = [0 2 4 6; 8 10 12 14; 16 18 20 22];
		clims = [4 18];
		imagesc(C,clims)
		colorbar
	创建后再修改
		C = [1 2 3; 4 5 6; 7 8 9];
		im = imagesc(C);
		im.AlphaData = .5; %%更改透明度
	3D图像
		Z = 10 + peaks; %%产生一些数据
		surf(Z) %% 根据数据产生3维面图
		hold on %% 连接上下图
		imagesc(Z) %% 绘制色图
imresize:放大缩小图片
imrotate:旋转图片
hold on：连接两个图
		Z = 10 + peaks;
		surf(Z)
		hold on %% 连接上下图
		imagesc(Z)
colorbar:显示色度条在图旁边
	C = [0 2 4 6; 8 10 12 14; 16 18 20 22];
	imagesc(C)
	colorbar

动画例子 doc imwrite

imadjust：增强黑白，减少灰色地带
extractFeatures: 提取可以匹配的descriptor点



OpenCV特征点提取算法对比
	http://www.p-chao.com/%E5%9B%BE%E5%83%8F%E5%A4%84%E7%90%86/2017-06-14/opencv%E7%89%B9%E5%BE%81%E7%82%B9%E6%8F%90%E5%8F%96%E7%AE%97%E6%B3%95%E5%AF%B9%E6%AF%94.html
