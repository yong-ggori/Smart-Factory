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

> 수현 part
111
### 개요
스마트 팩토리는 제품의 기획부터 판매까지의 모든 생산과정을 정보통신기술로 통합하여 고객 맞춤형 제품을 생산하는 첨단 지능형 공장이다. 이는 제품 생산 공정만을 적용하는 것이 아니라 제품 기획, 개발, 양산 그리고 주문과 완제품 출하까지 제조와 관련된 모든 과정을 적용하는 것을 의미한다.
사회가 4차 산업혁명 시대로 발전하면서 기존의 제조업에 첨단 IT 기술과 인공지능(AI)이 결합되며 디지털 자동화 시스템의 새로운 플랫폼인 스마트 팩토리가 생겨났다. 이는 공장 내 설비와 기계에 사물인터넷(IoT)을 설치하여 공정 데이터를 실시간으로 수집하고 스스로 데이터를 분석하여 상황을 파악 및 제어할 수 있는 시스템으로, 현실공간에서 데이터를 획득하고 이들을 가상공간에서 처리하여 현실공간에서 다시 활용하여 운영한다. 스마트 팩토리는 전체 공정을 관리하는 것이 어려웠던 기존 공정 자동화 기술의 한계를 ICT 기술을 이용하여 보완하였으며 전체 제조 과정을 자동화, 정보화하고 전체 과정이 실시간으로 연동되도록 하였다. 또한 사전에 정의된 프로그램에 따라 생산 기기들이 일괄적으로 움직이며 제품을 생산하는 과거의 공장 자동화 시스템에서 생산 설비가 제품과 상황에 따라 작업을 수행할 수 있는 지능형 시스템으로 발전할 수 있도록 하였다.
이처럼 스마트 팩토리는 설비나 장치를 모두 무선통신으로 연결하여 각각의 공정 사이에서 데이터를 실시간으로 주고받으며 정보화, 자동화된 제조과정이 이루어지고 생산성, 품질, 고객만족도를 향상시킬 수 있다. 그리고 더 나아가 에너지 절감, 최적화된 작업 과정, 안전한 근무 환경 등을 이루며 제조 효율을 극대화할 수 있다.
우리 팀은 다품종 소량 생산의 목적을 위한 기능들을 구현하고 영상처리 기술과 자율 주행 로봇을 이용한 제조 공정의 효율성에 집중하였으며 최소 비용과 시간으로 전체 공정을 안전하게 관리할 수 있는 스마트 팩토리를 개발하고자 하였다.

### 개발 목표
스마트 팩토리는 제조 과정에 ICT 기술을 접목해 다품종 소량 생산, 개발 기간의 단축, 관리의 최소화 등 지능적인 제조 공정을 구현하는 것을 목표로 한다. 즉, ICT 기술을 활용해 기업의 성과를 창출하고 차별적 경쟁력을 만드는 것이다. 우리 팀은 중소 제조 기업의 성과를 높일 수 있는 스마트 팩토리를 개발하는 것을 목표로 하였으며 기존 다품종 소량 생산의 단점을 극복할 수 있는 시스템을 개발하고자 하였다. 먼저 영상 처리 기술을 통해 설비 기기가 자동으로 제품의 형태, 색을 이용하여 종류를 분류하고 양품과 불량품을 구분하도록 구현한다. 그리고 터틀봇을 이용한 자율 주행을 구현하여 종류에 따라 제품이 알맞은 위치에 운송될 수 있도록 하며 로봇들은 제품의 특징에 따라 협력 운송을 할 수 있도록 구현한다. 시스템은 소켓 통신을 통해 데이터를 주고 받으며, QT로 구현한 화면을 통해 실시간 진행 상황을 확인하고 관리할 수 있다.

### 필요성
AI, IoT, 빅데이터 등의 IT 기술이 끊임없이 발전하며 제조 기업에서 이 기술들을 결합한 스마트 팩토리 구축에 큰 관심을 가지고 있다.
스마트 팩토리는 기업의 여력이나 상황에 맞게 단계적 구축을 할 수 있다는 특징을 가지고 있어 규모가 큰 기업들뿐만 아니라 많은 중소 제조 기업들도 비교적 적은 비용으로 시작할 수 있는 기초 단계의 스마트 팩토리를 구축하고 있다.
우리나라 제조 기업 중 50%는 다품종소량생산기업으로서 대부분이 중소기업이며, 이처럼 많은 중소기업들이 다품종소량생산 방식에 의지하고 있다.
하지만 스마트 팩토리에 대한 중소기업의 관심도가 증가하는 정도에 비해 대부분의 스마트 팩토리는 자동화 생산체계가 미흡하고 공정 표준화 수준도 낮은 편이며, 불량률도 높은 편이라고 한다.
그러므로 스마트 팩토리가 중소기업에서 효과적으로 이용되려면 적은 시간과 비용으로 상황과 목적에 맞는 공정 환경 구성이 가능해야 하며 생산 설비의 정확하고 빠른 자동화 기술이 필요하다. 또한 다품종 소량 생산 방식의 단점을 줄이고 생산 효율성을 높일 수 있는 스마트 팩토리 기술이 필요하다. 그리고 무엇보다 기존 제조 공장 시스템의 큰 문제점인 안전 문제를 해결할 수 있어야 하며 관리자가 쉽고 간편하게 사용할 수 있는 시스템의 구현이 필요하다.
그러므로 우리 팀은 다품종 소량 생산 방식으로 이루어지는 스마트 팩토리 시스템으로서, 자동화를 통해 제조 효율을 높이고 기존의 제조 시스템을 보완한 시스템을 개발하여 중소기업에서 효과적으로 이용될 수 있는 스마트 팩토리를 개발하고자 하였다.
시스템을 통해 목적에 따른 최적화된 공정 환경을 구성하여 공정이 복잡하고 설비 부족 현상이 자주 발생했던 다품종 소량 생산의 단점을 보완하는데 도움이 될 것이다. 또한 영상 처리 기술을 기반으로 구현한 자동 제품 분류 및 불량품 검출 과정을 통해 제조 제품의 불량률을 줄이고 생산 시간을 단축시킬 수 있도록 도움을 줄 것이다. 그리고 자율 주행 로봇을 이용한 운송 기능을 통해 이전에는 위험하고 힘들었던 운송 과정을 안전하고 편리하게 보완할 수 있을 것이다.

## 팀명

| 이름 | 역할 |
| ------ | ------------------------------------------------ |
| 황귀용 |  |
| 이지훈 |  |
| 맹용호 |  |
| 지수현 |  |

<br>

## 개발 일지

220714 황귀용 github main readme 작성

<br>

## 사용 기술 

| <center>분류</center> | <center>기술 스택</center> |
| :-------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| __언어__ |<img src="https://img.shields.io/badge/C-A8B9CC?style=flat-square&logo=C&logoColor=white"/> <img src="https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white"/> <img src="https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=Python&logoColor=white"/> <img src="https://img.shields.io/badge/Java-007396?style=flat-square&logo=Java&logoColor=white"/> |
| __IDE__ | <img src="https://img.shields.io/badge/Arduino-00979D?style=flat-square&logo=Arduino&logoColor=white"/> <img src="https://img.shields.io/badge/STM32-03234B?style=flat-square&logo=STMicroelectronics&logoColor=white"/> <img src="https://img.shields.io/badge/Raspberry Pi-A22846?style=flat-square&logo=Raspberry Pi&logoColor=white"/> <img src="https://img.shields.io/badge/Jetson Nano-76B900?style=flat-square&logo=NVIDIA&logoColor=white"/> |
| __서버 및 DB__|<img src="https://img.shields.io/badge/MSSQL-CC2927?style=flat-square&logo=Microsoft SQL Server&logoColor=white"/>  <img src="https://img.shields.io/badge/Apache-D22128?style=flat-square&logo=Apache&logoColor=white"/> <img src="https://img.shields.io/badge/PHP-777BB4?style=flat-square&logo=PHP&logoColor=white"/> <img src="https://img.shields.io/badge/MySQL-4479A1?style=flat-square&logo=MySQL&logoColor=white"/>|
| __VersionControl & CI/CD__| <img src="https://img.shields.io/badge/Git-F05032?style=flat-square&logo=Git&logoColor=white"/> <img src="https://img.shields.io/badge/GitHub-181717?style=flat-square&logo=GitHub&logoColor=white"/>|
| __OS__|<img src="https://img.shields.io/badge/Windows10-0078D6?style=flat-square&logo=Windows&logoColor=white"/> <img src="https://img.shields.io/badge/Ubuntu20.04-E95420?style=flat-square&logo=Ubuntu&logoColor=white"/>|
| __Platform & Library__|<img src="https://img.shields.io/badge/ROS-22314E?style=flat-square&logo=ROS&logoColor=white"/> <img src="https://img.shields.io/badge/OpenCV-5C3EE8?style=flat-square&logo=OpenCV&logoColor=white"/>|
| __Collaboration Tools__|<img src="https://img.shields.io/badge/Google Docs-4285F4?style=flat-square&logo=Google&logoColor=white"/>  <img src="https://img.shields.io/badge/Notion-000000?style=flat-square&logo=Notion&logoColor=white"/>|

