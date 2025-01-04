//
// Created by lbw on 25-1-4.
//

#ifndef JUDGER_JUDGER_H
#define JUDGER_JUDGER_H
//std
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <set>

//ros
#include <rclcpp/rclcpp.hpp>

//project
#include "AnswerAlogrithm.h"
#include "Details.h"
#include "my_msgs/msg/question.hpp"
#include "my_msgs/msg/answer.hpp"

class Judger
        : public rclcpp::Node{
    using Question = my_msgs::msg::Question;
    using Answer = my_msgs::msg::Answer;
private:
    int score;
    Question question_;
    Answer answer_;
    AnswerAlgorithm solver_;

    std::vector<CityDetails> cities_;

    int quz_count_;

    rclcpp::Publisher<Question>::SharedPtr question_pub_;
    rclcpp::Subscription<Answer>::SharedPtr answer_sub_;

    void answer_callback(const Answer::SharedPtr msg);

    Question genQuestion();
    static inline float distance(CityDetails c1, CityDetails c2);
    inline CityDetails getCity(int index);

public:
    Judger();
    ~Judger() =default;




};


#endif //JUDGER_JUDGER_H
