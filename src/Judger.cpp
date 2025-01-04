//
// Created by lbw on 25-1-4.
//

#include "Judger.h"

Judger::Judger():rclcpp::Node("judger"),score(0) {

    question_pub_ = this->create_publisher<Question>("question", 10);
    answer_sub_ = this->create_subscription<Answer>("answer", 10,
                                                    std::bind(&Judger::answer_callback, this, std::placeholders::_1));


}

void Judger::answer_callback(const my_msgs::msg::Answer::SharedPtr msg) {

}

Judger::Question Judger::genQuestion() {


    return Judger::Question();
}
