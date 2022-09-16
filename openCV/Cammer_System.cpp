//서버 헤드
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include <signal.h>
//영상처리 헤드
#include <opencv2/opencv.hpp> 
#include <opencv2/imgproc.hpp>
#include <iostream> 
#include <string>
//서버 전역 변수 및 함수
#define BUF_SIZE 100
#define NAME_SIZE 200
#define ARR_CNT 5

void * send_msg(void * arg);
void * recv_msg(void * arg);
void error_handling(char * msg);
char name[NAME_SIZE]="3";
char msg[BUF_SIZE];

//void cammer_client();

using namespace cv; 
using namespace std;  

int main(int, char**) { 
	VideoCapture cap;
	int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_V4L2;      // 0 = autodetect default API
	//web conect
	//VideoCapture cap("http://10.10.141.136:8080/?action=stream");
	//cap.open("http://10.10.141.136:8080/?action=stream");
	cap.open(-1);
	namedWindow("color",WINDOW_AUTOSIZE);

	createTrackbar("R1","color",0,255);
	createTrackbar("G1","color",0,255);
	createTrackbar("B1","color",0,255);
	createTrackbar("R2","color",0,255);
	createTrackbar("G2","color",0,255);
	createTrackbar("B2","color",0,255);
	createTrackbar("RR1","color",0,255);
	createTrackbar("RG1","color",0,255);
	createTrackbar("RB1","color",0,255);
	createTrackbar("RR2","color",0,255);
	createTrackbar("RG2","color",0,255);
	createTrackbar("RB2","color",0,255);
	//blue
	setTrackbarPos("R1","color",100);
	setTrackbarPos("G1","color",80);
	setTrackbarPos("B1","color",100);
	setTrackbarPos("R2","color",115);
	setTrackbarPos("G2","color",255);
	setTrackbarPos("B2","color",255);
	setTrackbarPos("RR1","color",125);
	setTrackbarPos("RG1","color",100);
	setTrackbarPos("RB1","color",150);
	setTrackbarPos("RR2","color",255);
	setTrackbarPos("RG2","color",255);
	setTrackbarPos("RB2","color",255);
	
	//소켓 통신 client
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void * thread_return;
	int test_cnt1 = 0, test_cnt2=0;

	sprintf(msg,"[%s:PASSWD]",name);

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("10.10.141.34");
	serv_addr.sin_port = htons(atoi("5000"));

	if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	
	write(sock, msg, strlen(msg));
	pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock);
	pthread_create(&snd_thread, NULL, send_msg, (void *)&sock);
	pthread_join(snd_thread, &thread_return);
	pthread_join(rcv_thread, &thread_return);
	//
	while(1){
		Mat img_input, img_result, img_gray; //이미지파일을 로드하여 image에 저장
		cap.read(img_input);
		//img_input=img_input+Scalar(50,50,50);		

		int LR=getTrackbarPos("R1","color");
		int LG=getTrackbarPos("G1","color");
		int LB=getTrackbarPos("B1","color");
		int HR=getTrackbarPos("R2","color");
		int HG=getTrackbarPos("G2","color");
		int HB=getTrackbarPos("B2","color");
		int RLR=getTrackbarPos("RR1","color");
		int RLG=getTrackbarPos("RG1","color");
		int RLB=getTrackbarPos("RB1","color");
		int RHR=getTrackbarPos("RR2","color");
		int RHG=getTrackbarPos("RG2","color");
		int RHB=getTrackbarPos("RB2","color");
		if (img_input.empty()) {
			 cout << "Could not open or find the image" << std::endl; return -1;
		 }
   		Mat hsv;
		cvtColor(img_input, hsv, COLOR_BGR2HSV); 

		//Mat col_mask, SC_img;
		Mat col_mask,col_mask2, SC_img;
		//Scalar low_c = Scalar(100,20,100);
		//Scalar up_c = Scalar(130,255,255);
		//파랑색영역 설정
		Scalar low_c = Scalar(LR, LG, LB);
		Scalar up_c = Scalar(HR, HG, HB);
		//빨강색영역 설정
		//Scalar low_c2 = Scalar(125, 100, 150);
		//Scalar up_c2 = Scalar(255, 245, 255);
		Scalar low_c2 = Scalar(RLR, RLG, RLB);
		Scalar up_c2 = Scalar(RHR, RHG, RHB);

		inRange(hsv, low_c, up_c, col_mask);
		bitwise_and(img_input, img_input,SC_img, col_mask);
		inRange(hsv, low_c2, up_c2, col_mask2);
		bitwise_and(img_input, img_input,SC_img, col_mask2);
		
		//그레이스케일 이미지로 변환 
		//cvtColor(img_input, img_gray, COLOR_BGR2GRAY); 
		cvtColor(SC_img, img_gray, COLOR_BGR2GRAY); 
		//이진화 이미지로 변환	
		Mat binary_image; 
		threshold(img_gray, img_gray, 0, 255, THRESH_BINARY_INV | THRESH_OTSU); //contour를 찾는다. 
		Mat img_avg_IS;
		Mat avg_kernel = Mat::ones(5, 5, CV_32F) / 25;
		//filter
		filter2D(img_gray, img_avg_IS, -1, avg_kernel, Point(-1, -1), (0, 0), BORDER_ISOLATED);
		//contour
		vector<vector<Point> > contours; 
		findContours(img_avg_IS, contours, RETR_LIST, CHAIN_APPROX_SIMPLE); //contour를 근사화한다. 
		vector<Point2f> approx; 
		img_result = img_input.clone();
	  	// 중점 대상의 색상 검출	
		uchar* pointer_row = img_result.ptr<uchar>(img_result.rows >> 1);
		uchar h = pointer_row[(img_result.cols >> 1) * 3 + 0];
		uchar s = pointer_row[(img_result.cols >> 1) * 3 + 1];
		uchar v = pointer_row[(img_result.cols >> 1) * 3 + 2];
		int str_h=h;
		int str_s=s;
		int str_v=v;
		//cout<<str_h<<", "<<str_s<<", "<<str_v<<endl;
		for (size_t i = 0; i < contours.size()-1; i++) { 
			//중앙검출 박스 생성
			approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true); 
			line(img_result, Point((img_input.cols >> 1) - 10, img_input.rows >> 1),
				   	Point((img_input.cols >> 1) + 10, img_input.rows >> 1), Scalar(0, 0, 255), 1);
			line(img_result, Point(img_input.cols >> 1, (img_input.rows >> 1) - 10),
				   	Point(img_input.cols >> 1, (img_input.rows >> 1) + 10), Scalar(0, 0, 255), 1);
			rectangle(img_result,Point((img_input.cols>>1)-100, (img_input.rows>>1)-100),
				   	Point((img_input.cols>>1)+100, (img_input.rows>>1)+100),Scalar(0,0,255),1,8,0);


			if (fabs(contourArea(Mat(approx))) > 100) //면적이 일정크기 이상이어야 한다. 
			{
			   	int size = approx.size(); //Contour를 근사화한 직선을 그린다.
					if ((size % 6 == 0) && (150<str_h && str_h<=255)){
						line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3); 
							for (int k = 0; k < size - 1; k++) 
								line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3); 
							for (int k = 0; k < size; k++) 
								circle(img_result, approx[k], 3, Scalar(0, 0, 255));
				   			//도형을 판정한다.
							if (size == 6 && test_cnt1 == 0){
								int *int_sock = (int *)&sock;
								char name_msg[NAME_SIZE+BUF_SIZE+2] = "[ALLMSG]";
								strcat(name_msg, "Blue@L-object\n");
								write(*int_sock, name_msg, strlen(name_msg));
								test_cnt1++;
								/*char buf[256];
								sprintf(buf,"/home/pi/opencv/test/captur/test1.jpg");
								//cout<<buf<<endl;
								imwrite(buf,img_result);*/
							}
						//}							
					}else if (size % 4 == 0) { 
						if(150<str_v && str_v<=255){
							// 면적 계산
							int a = sqrt(pow(approx[0].x - approx[1].x,2) + 
									pow(approx[0].y - approx[1].y,2))* sqrt(pow(approx[1].x - approx[2].x,2) + 
									pow(approx[1].y - approx[2].y,2));	
							cout<<a<<endl;
							if(5500<a && a<6300){
							line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3); 
								for (int k = 0; k < size - 1; k++) 
									line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3); 
								for (int k = 0; k < size; k++) 
									circle(img_result, approx[k], 3, Scalar(0, 0, 255));
				   				//도형을 판정한다.
								if (size == 4 && test_cnt2 == 0){						
									int *int_sock = (int *)&sock;
									char name_msg[NAME_SIZE+BUF_SIZE+2] = "[ALLMSG]";
									strcat(name_msg, "Red@I-object\n");
									write(*int_sock, name_msg, strlen(name_msg));
									test_cnt2++;
									//char buf[256];
									//sprintf(buf,"/home/pi/opencv/test/captur/test1.jpg");
									//cout<<buf<<endl;
									//imwrite(buf,img_result);
								}
							}
						}
					}
			}
		}
			imshow("input", img_gray); 
			imshow("result", img_result);
			if (waitKey(5) >= 0){ 				
				close(sock);
				break;
			}
			}	

			return 0; 
}

void * send_msg(void * arg)
{
	int *sock = (int *)arg;
	int str_len;
	int ret;
	fd_set initset, newset;
	struct timeval tv;
	char name_msg[NAME_SIZE + BUF_SIZE+2];

	FD_ZERO(&initset);
	FD_SET(STDIN_FILENO, &initset);

	fputs("Input a message! [ID]msg (Default ID:ALLMSG)\n",stdout);
		memset(msg,0,sizeof(msg));
		name_msg[0] = '\0';
		tv.tv_sec = 1;
		tv.tv_usec = 0;
		newset = initset;
		ret = select(STDIN_FILENO + 1, &newset, NULL, NULL, &tv);
		if(FD_ISSET(STDIN_FILENO, &newset))
		{
			fgets(msg, BUF_SIZE, stdin);
			if(!strncmp(msg,"quit\n",5)) {
				*sock = -1;
				return NULL;
			}
			else if(msg[0] != '[')
			{
				strcat(name_msg,"[ALLMSG]");
				strcat(name_msg,msg);
			}
			else
				strcpy(name_msg,msg);
			if(write(*sock, name_msg, strlen(name_msg))<=0)
			{
				*sock = -1;
				return NULL;
			}
		}
		if(ret == 0)
		{
			if(*sock == -1)
				return NULL;
		}
}

void * recv_msg(void * arg)
{
	int * sock = (int *)arg;
	int i;
	char *pToken;
	char *pArray[ARR_CNT]={0};

	char name_msg[NAME_SIZE + BUF_SIZE +1];
	int str_len;
		memset(name_msg,0x0,sizeof(name_msg));
		str_len = read(*sock, name_msg, NAME_SIZE + BUF_SIZE );
		if(str_len <= 0)
		{
			*sock = -1;
			return NULL;
		}
		name_msg[str_len] = 0;
		fputs(name_msg, stdout);
	
}

void error_handling(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}

