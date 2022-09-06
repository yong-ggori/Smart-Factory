![header](https://capsule-render.vercel.app/api?type=waving&color=auto&height=350&section=header&text=Smart%20Factory&fontSize=70&animation=fadeIn&fontAlignY=38&desc=22%20IoT%20SW%20전문가%20개발%204팀&descAlignY=51&descAlign=62)
<!--# Smart-Factory

### 22 IoT SW 전문가 개발 4팀 공모전
<br>
!-->
# 스마트 팩토리 구현

> 매니 퓰레이터 / 카메라를 통한 양, 불량품 구분 / 터틀봇 활용하여 물품 운송 / QT를 이용한 디스플레이 화면 구성

--------------------------------------------------------------------------

<br>

# 제안서 ref
   
***
##
> 지훈 part   
### ○ 개발결과물의 차별성
#### 1. 다품종 소량생산에 적합한 영상처리
 영상처리를 통한 오류 검출 뿐 아니라 현 시대에 맞는 다품종 소량생산에 적합한 기능을 구현하였다. 다품종 소량생산의 경우 그 형태와 색을 기준으로 품종을 나누고, 분류에 따라 다른 곳에 적재한다. 기존 제품의 경우 완벽한 오류 검출에 집중한다면 분류하는 과정과 오류를 검출하는 과정을 하나로 합하여 생산 라인의 단축 효과를 불러온다. 실시간으로 생성되는 데이터를 서버로 전송해 생산 데이터를 축적할 수 있고, 이는 생산성 향상을 위한 연구 개발에 이용될 수 있다. 또한, 관리자의 실시간 모니터링이 가능하며 예측 생산량을 계산하도록 하여 생산 라인의 효율성을 높인다.
		
#### 2. 모듈화
 생산 라인의 제품과 생산량에 따라 필요한 속도, 설비가 달라진다. 따라서 공장의 증설과 생산 라인의 재구축에 용이하도록 설비의 모듈화가 중요하다. 분류 설비를 모듈화하여 각 생산 공정의 속도에 맞게 설비를 재배치하고 더 효율적인 라인을 구축할 수 있다. 목적에 맞는 설비를 제작하는 것이 아닌 모듈 하나에 불량 검출과 분류의 기능을 더해 소프트웨어 업데이트를 통해 각 공정에 맞는 검출, 분류 기능을 구현한다.

#### 3. 협력 운송
 협력 이동이 기존의 자율 주행 로봇과는 다른 특징이다. 실내 자율 주행 로봇은 작업자의 고된 노동을 덜어주고 안전을 책임진다. 자율 주행 로봇의 주 역할을 재료 및 제품의 운송이다. 다만 제품과 재료의 무게는 천차만별이고, 제품 중 가장 무거운 것에 운송 로봇의 규격을 맞추도록 설계하고 제작한다. 그러나, 로봇이 협력 운송을 한다면 이 문제를 해결할 수 있다. 제품의 무게와 크기에 맞게 로봇의 개수를 설정할 수 있고 로봇은 이를 인지하여 제품을 운송한다. 

### ○ 개발결과물의 파급력 및 기대효과
#### 파급력 및 기대효과
1. 다품종 소량 생산 공정 라인 설계 용이
2. 공정 실시간 모니터링 및 설비 유지 보수 용이
3. 운반 로봇의 이용 다각화

기존의 공정들은 공정의 순서에 맞게 긴 라인으로 형성되어 있고, 한 번 형성된 라인은 쉽게 바꿀 수 없다. 우리 제품은 불량 검출과 제품 분류를 한 번에 할 수 있고, 장비를 모듈화해 공정 라인의 설계를 더 단순히 할 수 있다. 또한 모듈화된 장비는 유지 보수가 쉬워진다. 자율 주행 로봇은 제품의 운송에 적합하고, 산업 재해를 예방한다. 기존의 규격화된 자율 주행 로봇은 제품의 규격에 비해 로봇의 사양이 배 이상 크다면 비효율적일 수 있다. 협력 운송이 가능하도록 설계하여 각각 다른 규격의 제품에 적합한 운송이 가능하며, 이는 서버를 통해 관리하므로 효율적인 이용이 가능하다.
***
## 팀명

| 이름 | 역할 |
| ------ | ------------------------------------------------ |
| 황귀용 |팀장, GitHub관리, 매니퓰레이터 및 컨베이어 벨트 제작, 기능구현 |
| 이지훈 |매니퓰레이터 하드웨어 제작, 터틀 봇 제작 및 기능 구현  |
| 맹용호 |Image Processing, 카메라   |
| 지수현 |서버 구축, Qt UI 구상  |

<br>

## 개발 일지

220714 황귀용 github main readme 작성  
220717 이지훈 제안서 ref 개발결과물의 차별성, 파급력 및 기대효과 작성  
220719 황귀용 매니퓰레이터 동작 소스 추가  
220720 이지훈 터틀봇3 패키지 생성
220721 지수현 Qt ui 구성, php 구축
220721 이지훈 터틀봇3 반복 주행 코드 추가
220722 이지훈 소켓 통신 추가, navigation 패키지 수정

220724 이지훈 amcl 패키지 parameter 수정

<br>

## 사용 기술 

| <center>분류</center> | <center>기술 스택</center> |
| :-------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| __언어__ |<img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=white"/> <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white"/>|
| __IDE__ | <img src="https://img.shields.io/badge/Arduino-00979D?style=flat-square&logo=Arduino&logoColor=white"/> <img src="https://img.shields.io/badge/STM32-03234B?style=flat-square&logo=STMicroelectronics&logoColor=white"/> <img src="https://img.shields.io/badge/Raspberry Pi-A22846?style=flat-square&logo=Raspberry Pi&logoColor=white"/> <img src="https://img.shields.io/badge/Jetson Nano-76B900?style=flat-square&logo=NVIDIA&logoColor=white"/> |
| __서버 및 DB__|<img src="https://img.shields.io/badge/MSSQL-CC2927?style=flat-square&logo=Microsoft SQL Server&logoColor=white"/>  <img src="https://img.shields.io/badge/Apache-D22128?style=flat-square&logo=Apache&logoColor=white"/> <img src="https://img.shields.io/badge/PHP-777BB4?style=flat-square&logo=PHP&logoColor=white"/> <img src="https://img.shields.io/badge/MySQL-4479A1?style=flat-square&logo=MySQL&logoColor=white"/>|
| __VersionControl & CI/CD__| <img src="https://img.shields.io/badge/Git-F05032?style=flat-square&logo=Git&logoColor=white"/> <img src="https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=GitHub&logoColor=white"/>|
| __OS__|<img src="https://img.shields.io/badge/Windows10-0078D6?style=flat-square&logo=Windows&logoColor=white"/> <img src="https://img.shields.io/badge/Ubuntu20.04-E95420?style=flat-square&logo=Ubuntu&logoColor=white"/>|
| __Platform & Library__|<img src="https://img.shields.io/badge/ROS-22314E?style=flat-square&logo=ROS&logoColor=white"/> <img src="https://img.shields.io/badge/OpenCV-5C3EE8?style=flat-square&logo=OpenCV&logoColor=white"/>|
| __Collaboration Tools__|<img src="https://img.shields.io/badge/Google Docs-4285F4?style=flat-square&logo=Google&logoColor=white"/>  <img src="https://img.shields.io/badge/Notion-000000?style=flat-square&logo=Notion&logoColor=white"/>|

