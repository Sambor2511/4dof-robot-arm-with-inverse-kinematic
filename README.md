# 4dof Robot Arm using Inverse Kinematic

## Overview

4 degree of freedom or 4dof robot arm with inverse kinematic. This project focus on inverse kinematic that is easy to understand through some basic trigonometry that most people can comprehend.

## Before and after

Noted that this robot went through a modification from using sg90 micro servo as the elbow to using mg995.

<img src="https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/ba028357-59e8-4c9b-ba7f-f2440c37741f" width="300" height="300" />
<img src="https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/4024afd6-ecef-44af-809b-1cdcd4cd0911
" width="300" height="300" />

---

#####

## Code we will be using to learn :

` float theta1 = atan2(y, x);
 float theta1deg = degrees(theta1);
 float p = x / cos(theta1);
 float d = sqrt(pow(p, 2) + pow(z, 2));
 float theta2 = acos((pow(L1, 2) + pow(d, 2) - pow(L2, 2)) / (2 * L1 * d)) + atan2(z, p);
 float theta2deg = degrees(theta2);
 float theta3 = acos((pow(L1, 2) + pow(L2, 2) - pow(d, 2)) / (2 * L1 * L2));
 float theta3deg = 180 - degrees(theta3);
 servo1.write(theta2deg);
 servo2.write(theta3deg);`
