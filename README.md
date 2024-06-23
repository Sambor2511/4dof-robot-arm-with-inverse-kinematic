

4dof Robot Arm using Inverse Kinematic

## Overview

4 degree of freedom or 4dof robot arm with inverse kinematic. This project focus on inverse kinematic that is easy to understand through some basic trigonometry that most people can comprehend.

## Before and after

Noted that this robot went through a modification from using sg90 micro servo as the elbow to using mg995.
<img src="https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/ba028357-59e8-4c9b-ba7f-f2440c37741f" width="300" height="300" /><img src="https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/4024afd6-ecef-44af-809b-1cdcd4cd0911" width="300" height="300" />

----------

## Code we will be using to learn :

    float theta1 = atan2(y, x);
    float theta1deg = degrees(theta1);
    float p = x / cos(theta1);
    float d = sqrt(pow(p, 2) + pow(z, 2));
    float theta2 = acos((pow(L1, 2) + pow(d, 2) - pow(L2, 2)) / (2 * L1 * d)) + atan2(z, p);
    float theta2deg = degrees(theta2); float theta3 = acos((pow(L1, 2) + pow(L2, 2) - pow(d, 2)) / (2 * L1 * L2));
    float theta3deg = 180 - degrees(theta3);
    servo0.write(theta1deg);
    servo1.write(theta2deg);
    servo2.write(theta3deg);
we will convert these code to math expression with pictures for the ease of understanding.

### 4dof Robot Arm :

Top View

![image](https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/ee3b468b-535a-4f70-b117-d38450197b69)

### $\theta_1 = \tan^{-1} \left(\frac{y}{x}\right)$ this find the angle of $\theta_1$ in radian using the inverse of tangent.

### $\theta_1 *\frac{180}{PI} = \theta_1$ in degrees

### now that we got $\theta_1$ in degree we need to find the length of $P$

 ### $\cos \theta_1= \frac{P}{x} \Rightarrow P=\cos \theta_1 * x$ 

### after finding $\theta_1$ and $P$ we can start finding another another angles such as $\theta_2$, $\theta_3$ and $\theta_4$.

Side view of the robot arm

![image](https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/c8771a8a-d049-4da6-aa03-4e5b3c681804)

so let start by calculating $\theta_2$

![image](https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/54b7adbb-a3f3-4bb9-9c0f-32c13bb94823)

as shown in the picture above, we can see that the sum of $\theta_2$ is the equivalent to $\alpha_1 + \alpha_2$.
Since $\alpha_1$ is in a scalene triangle while $\alpha_2$ is in a right triangle, that mean we have to use cosine law to find $\alpha_1$ and pythagorean theorem for $\alpha_2$.
So here a quick preview of the formula we are going to use:
![image](https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/053366ce-de35-4c53-98e5-509e09d57dca)
![image](https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/dd691da8-5429-4a1b-9e1d-7eddf65bdcdd)


with the help of these formulas we can apply it to our robot arm as seen from the picture above.

### $\alpha_1 = \frac{L1^2 + d^2 - L2^2}{2 * L1 * d}$

since ${d}$ is not yet known, we can find it using the pythagorean theorem

### $d = \sqrt{P^2 + z^2}$

$z$ is the distance from the ground to the end of the $2^{nd}$ link
now that we have found $d$ we can calculate $\alpha1$ but we are still missing $\alpha2$.
as the picture above we can see that $\alpha2$ is in a right triangle therefore we can use tangent and the inverse tangent.

### $\tan\alpha_2 =\frac{P}{z} \Rightarrow \alpha_2= \tan^{-1} \frac{P}{z}$ 

### since $\theta_2$ is the sum of $\alpha_1$ and $\alpha_2$

### $\theta_2 = \alpha_1 + \alpha_2$

### $\theta_2 * \frac{180}{PI} = \theta_2$ in degrees

now let find $\theta_3$.
![image](https://github.com/Sambor2511/4dof-robot-arm-with-inverse-kinematic/assets/76769524/8fe00a98-01b3-46c6-ab9d-82b306a6914d)

as seen in the picture there a angle between L1 and L2 called $\beta$, and in order to find $\theta_3$ we just have to subtract 180 by $\beta$.

### $\beta = \frac{L1^2 + L2^2 - d^2}{2 * L1 * L2}$

### $\theta_3 = 180 - \beta$

Great!, all that is left is $\theta_4$ which is the angle to make the end effector stay parallel to the x axis.


