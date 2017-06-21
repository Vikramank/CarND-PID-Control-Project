# CarND-Controls-PID
My project solution to CarND-PID-Control-Project as a part of Self-Driving Car Engineer Nanodegree Program

## Project Goal
The main goal of this project is to implement PID controller for a self driving car and fine tune the gain parameters.

## CTE 
CTE stands for cross track error. It is a measurement of the difference of the desired steering angle and actual steering angle.

## Proportional gain
![alt text](https://github.com/Vikramank/CarND-PID-Control-Project/blob/master/pics/p.jpeg)
The proportional gain acts in a similar fasion to a oscilating pendulum travelling in a sinosuidal motion. Zero displacement is the ideal location we want to achieve. When we deviate far away from it driving force towards zero displacement is high and helps to reach the mean location. But once it reaches the destination, it still has momentum and continue to travel away from the desired location. It keeps oscillating forever. The force is proportional to the displacement. In our case we aim to achieve zero CTE. Hence first term, is proportional to CTE.

## Differential gain 
![alt text](https://github.com/Vikramank/CarND-PID-Control-Project/blob/master/pics/pd.jpeg)
In order to bring the car to a stable location we need to remove/minimise the oscillation terms. Considering the pendulum motion in real life, frictional force that is proportional to the derivative of the displacement, minimises the oscillations and brings the pendulum to rest which is mean position. In self-driving car scenario, we want to achieve the target location by minimising the oscillations gradually. This could be achieved by introducing a derivative term of CTE.  

## Integral gain 
![alt text](https://github.com/Vikramank/CarND-PID-Control-Project/blob/master/pics/pid.jpeg)
In real life situations, the car is not perfect. For instance, the locations of the wheel are not 100% aligned. As a result, this would give rise to a bias term which would not permit us to achieve ideal solution. To negate this effect, we introduce a new term which is an integral of all the previous CTE. By this way, the car will have an idea about the bias and 'P' and 'D' term will work towards reducing the effect of bias term 

## Selecting the hyperparameters :
My initial guess after knowing the influence of the terms is that, Differential gain will be dominant and much higher than proportional term in order to suppress the oscillations. The proportional gain will have to be low in order to have minimal oscillations. The integral gain will be very low since it stores all the CTEs. Hence I started out with these values. 
(0.1,0.0001, 1.0). 
I started to change 'P' and 'D' gain to till I got a nice smooth ride. I adopted methods similar to Newton-Rapson method, going over extreme values and then decreasing the range. 

After that, I tuned 'I' parameter. 

My final paramters are (0.5,0.005,12.5)

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
