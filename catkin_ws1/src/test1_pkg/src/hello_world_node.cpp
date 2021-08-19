#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>
using namespace ros;
int main(int argc, char **argv)
{
  init(argc, argv, "hello_world_node"); // ROS를 처음 초기화 함
  NodeHandle nh; // 뭔 핸들러가 있음
  Publisher chatter_pub = nh.advertise<std_msgs::String>("say_hello_world", 1000); // 

  Rate loop_rate(10); 
  
  int count = 0;// 카운트
  while (ok())// ros가 OK인 동안 괄호 안 반복
  {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count; // ex) hello world 카운트(몇번 반복했는지 보기 위해) 메시지에 담을 준비
    msg.data = ss.str(); //  메시지 데이터에 실음
    ROS_INFO("%s", msg.data.c_str()); // ROS 로그에다가 한번 슥 출력
    chatter_pub.publish(msg);//"hello world 1" 퍼블리셔에다가 전송
    spinOnce();// 로본 한바퀴 돌아라
    loop_rate.sleep();// 10만큼 기다림
    ++count;// 카운트 증가
  }
  return 0;
}
