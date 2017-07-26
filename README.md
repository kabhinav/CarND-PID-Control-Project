# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Discussion

The aim of the project was to implement a PID controller for steering an autonomous vehicle. The PID controller facilitates the continuous error calculation of the difference between required (truth) and current steering angles of auton
omus vehicle. Once the main program implmentation was completed, the parameter of the PID program were tuned to achieve the stable driving of autonomous vehicle on the simulator track.

The initial values of three tuned parameters were:

1. Proportional coffecient was set at value 0.1 to help reducing the oscillations of autonomous vehicle across the simulated track.

2. Integral coffecient was finally kept at zero but experimenting with this value led to car run into a loop with left steering bias on the track. Upon further reading, I found that it is best to keep this value at 0 since there was no systemic bias in the simulated environment.

3. With Differntial coffecient value I experimented with values ranging 0.2 (small) to 1.2 (large) and differing throttle values. In the end I chose an intermidiate value 0.9 becuase it provided best combination of stable driving and sp
eed across the track.

## Refection
* I ran the car across the simulated track several times observing the effect of each parameter value on the stable driving of the car. I observed that an increase in the value of differential value combined with faster throtle application made the car go off track very quickly. I tried to drive the car at max speed 50 mph. The steer angle seemed to hold in straight line but car quickly veered of the track while turning.

* In order to make the successful turns I then used Twiddle from the lecture to adjust the parameters based on average error calculated during several measurements while reducing the speed threshold to 35 mph. However, I am interested i
n finding what changes/increment I need to do to make current PID controller robust enough for driving at max speed 50 mph across the track.

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
