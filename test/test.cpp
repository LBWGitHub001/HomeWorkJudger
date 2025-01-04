//
// Created by lbw on 25-1-4.
//

#include "Judger.h"
#include "DrawGraph.h"

using Question = my_msgs::msg::Question;
using Answer = my_msgs::msg::Answer;
int main(){
    DrawGraph dg;
    Question q;
    Answer a;
    std::vector<CityDetails > cities{{0,0},{10,10},{10,20},{-10,-10}};
    q.city1.push_back(0);
    q.city2.push_back(1);
    q.length.push_back(1.414);

    q.city1.push_back(1);
    q.city2.push_back(2);
    q.length.push_back(1.0);
    std::cout << "Question:" << std::endl;
    dg.drawGraph(cities,q,a,a);
    std::cout << "End:" << std::endl;

    return 0;
}