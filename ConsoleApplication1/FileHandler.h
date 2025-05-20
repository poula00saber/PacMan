#pragma once  
#include <fstream>  
#include<nlohmann/json.hpp>
#include "string.h"
#include "Score.h"
using json = nlohmann::json;
using namespace std;

class FileHandler  
{  
public:
    nlohmann::json dataArray;

    void jsonWrite(stack<Score> scores) {
        dataArray.clear();  
        json dataScore;
        int i = 0;
        while (!scores.empty() && i < 10)
        {
            dataScore["Value"] = scores.top().value;
            dataScore["userName"] = scores.top().userName;
            dataArray.push_back(dataScore);
            scores.pop();
            i++;
        }
        std::ofstream o("scores.json");
        o << setw(4) << dataArray << endl;
        o.close();
    }


    stack<Score> jsonRead()
    {
        std::ifstream input("scores.json");
        stack<Score> scores;
        stack<Score> copy;

        input >> dataArray;
        int i = 0;

        for (json j : dataArray )
        {
            Score temp = Score(j["Value"], j["userName"]);
            copy.push(temp);
            if (i>10)
            {
                break;
            }
            i++;
        }
        while (!copy.empty())
        {
            scores.push(copy.top());
            copy.pop();
        }
        input.close();
        return scores;
    }

};
