#ifndef _ODOMETRY_H_
#define _ODOMETRY_H_

class ODOM{
private:
    double current_time, last_time;
    double dt;
    double x, y, theta;
public:
    ODOM(double _x, double _y, double _theta);
    void update(const geometry_msgs::Twist::ConstPtr& ins_vel);
};

#endif
