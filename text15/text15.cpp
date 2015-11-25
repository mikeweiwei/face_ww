#include"stdAfx.h"
#include <opencv2/core/core.hpp> 
#include "cv.h" 
#include "highgui.h" 

int main() 
{ 
	double add=1.1;
	for(int i = 0; i < 5; i++)
	{
		add = add + 0.01;
	}
    const char* cascade_name = "D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";//分类器路径，按实际填写 

    static CvMemStorage* storage = 0; 
    static CvHaarClassifierCascade* cascade = 0; 

         cascade = (CvHaarClassifierCascade*)cvLoad(cascade_name, 0, 0, 0); 
         storage = cvCreateMemStorage(0); 

		 IplImage *image = cvLoadImage("00.jpg");//读入图像，按实际输入 

		  CvSeq* faces = cvHaarDetectObjects(image, cascade, storage, add, 2,CV_HAAR_DO_CANNY_PRUNING, cvSize(0,0));//Haar人脸检测
		  int num_of_face = faces->total;
		  printf("TOTAL;%d",num_of_face);
		  CvScalar color[1] = { 255 };//设置矩形框颜色 
  
		  for (int i = 1; i < num_of_face + 1; i++) 
		   { 
			CvRect* r = (CvRect*)cvGetSeqElem(faces, i); //获取每个人脸的信息，返回类型是矩形。i为人脸编号，0，1，2。。。可以用循环读取。 
			cvRectangle(image, cvPoint(r->x, r->y), cvPoint(r->x + r->width, r->y + r->height), color[0], 2);//画矩形框 
         } 

		cvNamedWindow("Test", CV_WINDOW_AUTOSIZE);//创建窗口，第二个参数CV_WINDOW_AUTOSIZE代表保存图像原来大小  
		cvShowImage("Test", image);//显示图片 

		cvWaitKey(0);//等待操作   

		cvReleaseImage(&image);//释放图片    
		cvDestroyWindow("Test");//销毁窗口 
	

	   // CvSeq* faces = cvHaarDetectObjects(image, cascade, storage, a, 2,CV_HAAR_DO_CANNY_PRUNING, cvSize(0,0));//Haar人脸检测 

    
		//printf("TOTAL;%d",num_of_face);//得到检测所得的人脸个数 

      

		return 0; 
} 