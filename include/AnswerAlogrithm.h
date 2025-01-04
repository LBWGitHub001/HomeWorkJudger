//
// Created by lbw on 25-1-4.
//
#ifndef ANSWER_ALOGRITHM_H
#define ANSWER_ALOGRITHM_H
//std

//project
#include "my_msgs/msg/question.hpp"
#include "my_msgs/msg/answer.hpp"

class AnswerAlgorithm {
    using Question = my_msgs::msg::Question;
    using Answer = my_msgs::msg::Answer;
public:
    AnswerAlgorithm() = default;

    ~AnswerAlgorithm() = default;

    void solve(Question& question, Answer& answer);
};

#endif //ANSWER_ALOGRITHM_H