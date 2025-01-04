//
// Created by lbw on 25-1-4.
//

#ifndef JUDGER_JUDGER_H
#define JUDGER_JUDGER_H
//std
#include <iostream>

//ros
#include <rclcpp/rclcpp.hpp>

//project
#include "my_msgs/msg/question.hpp"
#include "my_msgs/msg/answer.hpp"

class Judger
        : public rclcpp::Node{
    using Question = my_msgs::msg::Question;
    using Answer = my_msgs::msg::Answer;
private:
    int score;

    rclcpp::Publisher<Question>::SharedPtr question_pub_;
    rclcpp::Subscription<Answer>::SharedPtr answer_sub_;

    void answer_callback(const Answer::SharedPtr msg);

    static Question genQuestion();

public:
    Judger();
    ~Judger() =default;




};


#endif //JUDGER_JUDGER_H
