#ifndef ADDMARKERS_H
#define ADDMARKERS_H

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>


/* TODO: using other method to realize it instead of HARD CODE */
#define pick_up_pos_x 1.0
#define pick_up_orit_w 1.0
#define pick_up_pos_x_thres 0.15
#define pick_up_orit_w_thres 0.10

#define drop_off_pos_x 3.0
#define drop_off_orit_w 1.5
#define drop_off_thres 0.15
#define drop_off_orit_w_thres 0.10

class addMarkers
{
    private:
        /* ROS member variables */
        ros::NodeHandle nh_;
        ros::Subscriber odom_sub_;
        ros::Publisher marker_pub_;
        ros::Rate r_(20);

        /* Other member variables */
        bool isPickup_ = false;
        bool isDropoff_ = false;
        bool isPaused_ = false;
        
        geometry_msgs::Pose, odom_pose_;

        visualization_msgs::Marker marker_;


    public:
        addMarkers(ros::NodeHandle&);
        ~addMarkers();

        void odom_callback(const geometry_msgs::PoseWithCovarianceStamped);
        void update_odom_status(double, double);
        void publish_markers();

};

#endif /* ADDMARKERS_H */