//
// Created by lbw on 25-1-4.
//

#include "DrawGraph.h"

DrawGraph::DrawGraph() {
    cv::namedWindow("Graph", cv::WINDOW_AUTOSIZE);
    screen = cv::Mat::zeros(cv::Size(1500, 1600), CV_8UC3);
}


void
DrawGraph::drawGraph(std::vector<CityDetails> &cityDetails,
                     DrawGraph::Question &question,
                     DrawGraph::Answer &stdAnswer,
                     DrawGraph::Answer &userAnswer) {
    cv::line(screen, cv::Point(0, 800), cv::Point(1500, 800), cv::Scalar(255, 255, 255), 2);

    auto drawStd = [&](const cv::Point2f &point) {
        return cv::Point2f(point.x*5 + 750, 400 - point.y*2);
    };

    auto drawUser = [&](const cv::Point2f &point) {
        return cv::Point2f(point.x*5 + 750, 1200 - point.y*2);
    };


    //绘制城市
    for (auto &city: cityDetails) {
        auto center = cv::Point2f(city.x, city.y);
        drawCrosses(screen, drawStd(center), cv::Scalar(0, 0, 255));
        drawCrosses(screen, drawUser(center), cv::Scalar(0, 0, 255));
    }

    //绘制问题
    for (int i = 0; i < question.city1.size(); i++) {
        auto cityD1 = cityDetails[question.city1[i]];
        auto cityD2 = cityDetails[question.city2[i]];
        auto city1 = cv::Point2f(cityD1.x, cityD1.y);
        auto city2 = cv::Point2f(cityD2.x, cityD2.y);
        cv::line(screen, drawStd(city1), drawStd(city2),
                 cv::Scalar(255, 0, 0), 2);
        cv::line(screen, drawUser(city1), drawUser(city2),
                 cv::Scalar(255, 0, 0), 2);
    }

    cv::imshow("Graph", screen);
    cv::waitKey(-1);
}

void DrawGraph::drawCrosses(cv::Mat &screen,
                            const cv::Point2f &center,
                            const cv::Scalar &color) {
    int x = center.x;
    int y = center.y;
    cv::line(screen, cv::Point(x, y - 10), cv::Point(x, y + 10), color, 2);
    cv::line(screen, cv::Point(x - 10, y), cv::Point(x + 10, y), color, 2);
}


