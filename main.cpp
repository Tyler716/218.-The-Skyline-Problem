#include<ostream>

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> *results = new vector<vector<int>>();
        vector<int> *result;

        for (int i = 0; i < buildings.size(); i++)
        {
            if(i == buildings.size() - 1)
            {
                result = new vector<int>();
                result->push_back(buildings[i][1]);
                result->push_back(0);
                results->push_back(*result);
            }
            else
            {
                if(buildings[i][2] > buildings[i+1][2])
                {
                    if(buildings[i][1] > buildings[i+1][0])
                    {
                        result = new vector<int>();
                        result->push_back(buildings[i][0]);
                        result->push_back(buildings[i][2]);
                        results->push_back(*result);

                        result = new vector<int>();
                        result->push_back(buildings[i][1]);
                        result->push_back(buildings[i+1][2]);
                        results->push_back(*result);
                    }
                    else
                    {
                        result = new vector<int>();
                        result->push_back(buildings[i][1]);
                        result->push_back(0);
                        results->push_back(*result);
                    }
                    
                }
                else if(buildings[i][2] == buildings[i+1][2])
                {
                    if(buildings[i][1] >= buildings[i+1][0])
                    {
                        result = new vector<int>();
                        result->push_back(buildings[i][0]);
                        result->push_back(buildings[i][2]);
                        results->push_back(*result);
                    }
                    else
                    {
                        result = new vector<int>();
                        result->push_back(buildings[i][1]);
                        result->push_back(0);
                        results->push_back(*result);
                    }
                }
                else if(buildings[i][1] > buildings[i+1][0])
                {
                    vector<int> *result = new vector<int>();
                    result->push_back(buildings[i][0]);
                    result->push_back(buildings[i][2]);
                    results->push_back(*result);
                }
            }
        }
        return *results;
    }
};