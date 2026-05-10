class Solution {
public:
    vector<int> scoreValidator(vector<string>& v) {
        int n=v.size();
        int score=0,counter=0;
        for(auto &i:v){
            if(i=="1" || i=="2"|| i=="3" || i=="4" || i=="5" || i=="6"){
                score+=(stoi(i));
            }else if(i=="W"){
                counter++;
            }else if(i=="WD" || i=="NB"){
                score++;
            }
            if(counter==10){
                return {score,counter};
            }
        }
        return {score,counter};
    }
};