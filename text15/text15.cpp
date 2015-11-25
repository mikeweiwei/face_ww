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
    const char* cascade_name = "D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";//������·������ʵ����д 

    static CvMemStorage* storage = 0; 
    static CvHaarClassifierCascade* cascade = 0; 

         cascade = (CvHaarClassifierCascade*)cvLoad(cascade_name, 0, 0, 0); 
         storage = cvCreateMemStorage(0); 

		 IplImage *image = cvLoadImage("00.jpg");//����ͼ�񣬰�ʵ������ 

		  CvSeq* faces = cvHaarDetectObjects(image, cascade, storage, add, 2,CV_HAAR_DO_CANNY_PRUNING, cvSize(0,0));//Haar�������
		  int num_of_face = faces->total;
		  printf("TOTAL;%d",num_of_face);
		  CvScalar color[1] = { 255 };//���þ��ο���ɫ 
  
		  for (int i = 1; i < num_of_face + 1; i++) 
		   { 
			CvRect* r = (CvRect*)cvGetSeqElem(faces, i); //��ȡÿ����������Ϣ�����������Ǿ��Ρ�iΪ������ţ�0��1��2������������ѭ����ȡ�� 
			cvRectangle(image, cvPoint(r->x, r->y), cvPoint(r->x + r->width, r->y + r->height), color[0], 2);//�����ο� 
         } 

		cvNamedWindow("Test", CV_WINDOW_AUTOSIZE);//�������ڣ��ڶ�������CV_WINDOW_AUTOSIZE������ͼ��ԭ����С  
		cvShowImage("Test", image);//��ʾͼƬ 

		cvWaitKey(0);//�ȴ�����   

		cvReleaseImage(&image);//�ͷ�ͼƬ    
		cvDestroyWindow("Test");//���ٴ��� 
	

	   // CvSeq* faces = cvHaarDetectObjects(image, cascade, storage, a, 2,CV_HAAR_DO_CANNY_PRUNING, cvSize(0,0));//Haar������� 

    
		//printf("TOTAL;%d",num_of_face);//�õ�������õ��������� 

      

		return 0; 
} 