//
// Created by lbw on 25-1-4.
//

#include "Judger.h"

Judger::Judger():rclcpp::Node("judger"),score(0),quz_count_(0) {

    question_pub_ = this->create_publisher<Question>("question", 10);
    answer_sub_ = this->create_subscription<Answer>("answer", 10,
                                                    std::bind(&Judger::answer_callback, this, std::placeholders::_1));

    srand(time(NULL));
    question_ = genQuestion();
    question_pub_->publish(question_);
    quz_count_++;
}

void Judger::answer_callback(const my_msgs::msg::Answer::SharedPtr msg) {
    Answer answer = *msg;

    solver_.solve(question_, answer);

    if(quz_count_ < NUM_QUESTIONS){
        question_ = genQuestion();
        quz_count_++;
    }
}

Judger::Question Judger::genQuestion() {
    Question question;
    int MaxRange = rand() % 100 + 20;
    int CityNum = rand() % 30 +2;
    int RoadNum = rand() % 30 +2;
    for(int i=0;i<CityNum;i++){
        CityDetails city;
        city.x = rand() % MaxRange;
        city.y = rand() % MaxRange;
        cities_.push_back(city);
    }

    CityNum = cities_.size();
    for(int i=0;i<RoadNum;i++){
        int c1 = rand() % CityNum;
        int c2 = rand() % CityNum;
        float dist = distance(cities_[c1], cities_[c2]);
        question.city1.push_back(c1);
        question.city2.push_back(c2);
        question.length.push_back(dist);
    }
    return question;
}

float Judger::distance(CityDetails c1, CityDetails c2) {
    float dx = c1.x - c2.x;
    float dy = c1.y - c2.y;
    return sqrt(dx*dx + dy*dy);
}

CityDetails Judger::getCity(int index) {
    int i = 0;
    for(auto it = cities_.begin(); it!= cities_.end(); it++){
        if(i == index)
            return *it;
        i++;
    }
    return CityDetails();
}
