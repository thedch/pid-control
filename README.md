# PID Controller
Self-Driving Car Engineer Nanodegree Program

I implemented and tuned two PID controllers: one for the car throttle, and one for the car steering. 

For the steering PID controller, I sent cross track error (as provided by the simulator) into the PID algorithm, and used it to update the steering angle for the next time step.

For the throttle PID controller, I set an experimentally determined maximum throttle variable, and then subtracted from that variable proportionally based on the cross track error: the more error, the slower the car would go. This helped the vehicle stay on track.

For parameter tuning, I used [the following approach](https://robotics.stackexchange.com/questions/167/what-are-good-strategies-for-tuning-pid-loops), which I have used previously in other projects:

1. Set all gains to zero.
1. Increase the P gain until the response to a disturbance is steady oscillation.
1. Increase the D gain until the the oscillations go away (i.e. it's critically damped).
1. Repeat steps 2 and 3 until increasing the D gain does not stop the oscillations.
1. Set P and D to the last stable values.
1. Increase the I gain until it brings you to the setpoint with the number of oscillations desired 
(normally zero but a quicker response can be had if you don't mind a couple oscillations of overshoot)
