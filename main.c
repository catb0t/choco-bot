#pragma config(Motor,  port1,           Lshoot,        tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           Rfront,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           Rback,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           Lfront,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port5,            ,             tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port6,           Loader,        tmotorNone, openLoop)
#pragma config(Motor,  port7,           Feeder,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           Lback,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Servo,         tmotorNone, openLoop)
#pragma config(Motor,  port10,          Rshoot,        tmotorVex393TurboSpeed_HBridge, openLoop, reversed)

void
zeroServo() {
  motor[Servo] = 0;
}
​
void
retractServo (bool wait) {
  motor[Servo] = -200;
  if (wait) {
    wait1Msec(350);
  }
}
​
void
pushServo (bool wait) {
  motor[Servo] = -50;
  if (wait) {
    wait1Msec(350);
  }
}
​
task
main () {
  //Tank controls
  while(true) {
    motor[Lfront]  = vexRT[Ch3] / 2;
    motor[Lback]  = vexRT[Ch3] / 2;      // Left Joystick Y value
    motor[Rfront] = vexRT[Ch2] / 2;
    motor[Rback] = vexRT[Ch2] / 2;    // Right Joystick Y value

    //Loader
    if (vexRT[Btn5D]==1) { //if the Button (5D) is pressed...
      motor[Loader] = 100;
    }  else { //Load a ball. If not, stop the loader.
      motor[Loader] = 0;
    }

    //Shooter
    if (vexRT[Btn6D] == 1) { //if the Button (6D) is pressed...
      motor[Lshoot] = 105;
      motor[Rshoot] = 105;
    }  else { //...shoot a ball. If not, stop the motors.
      motor[Lshoot] = 0;
      motor[Rshoot] = 0;
    }

    //Servo Shoot
    if (vexRT[Btn6U] == 1) {
      pushServo(false);
    } else {
      retractServo(false);
    }
    //Feeder wheels suck in the balls when the button 8D is pressed.
    if (vexRT[Btn5U]) {
      motor[Feeder] = 100;
    } else {
      motor[Feeder] = 0;
    }
  }
}