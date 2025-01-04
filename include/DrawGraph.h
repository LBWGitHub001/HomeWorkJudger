//
// Created by lbw on 25-1-4.
//

#ifndef JUDGER_DRAWGRAPH_H
#define JUDGER_DRAWGRAPH_H

#include <iostream>
#include <set>
#include <vector>
#include "Details.h"
#include <opencv2/opencv.hpp>
#include "my_msgs/msg/question.hpp"
#include "my_msgs/msg/answer.hpp"


class DrawGraph {
    using Question = my_msgs::msg::Question;
    using Answer = my_msgs::msg::Answer;
public:
    DrawGraph();

    ~DrawGraph() = default;

    void drawGraph(std::vector<CityDetails>& cityDetails,Question& question, Answer& stdAnswer, Answer& userAnswer);
private:
    cv::Mat screen;

    void drawCrosses(cv::Mat& screen,const cv::Point2f &center, const cv::Scalar &color);
};


#endif //JUDGER_DRAWGRAPH_H
