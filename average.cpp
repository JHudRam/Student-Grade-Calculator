#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Function to read quiz grades from user
void read_grades(vector<double> &q, double &p, double &e){
    cout << "Please enter quiz grades 0 - 100: ";
    for(int i = 0; i < q.size(); i++){

        cin >> q[i];

    }

    //Input for project grade and exam
    cout << "Please enter project grade 0 - 100: ";
    cin >> p;
    cout << "Please enter exam grade 0 - 100: ";
    cin >> e;

}

//Function to compute average grade based on two schemes
double compute_average(vector<double> &q, double p, double e){
    double lowest = 1000;
    double secondLowest = 1000;
    double quiz_sum = 0;
    int d_check = 0;
    
    vector<double> new_q = q;
    
    //Find lowest quiz grade
    for(int i = 0; i < 6; i++){
        if(q[i] < lowest){
            lowest = q[i];
        }
    }
    
    //Find second lowest quiz grade
    for(int i = 0; i < 6; i++){
        if(q[i] < secondLowest && q[i] > lowest){
            secondLowest = q[i];
        }
    }
    
    //Drop two lowest quiz grades and output the remaining four
    for(int i = 0; i < 6; i++){
        if((q[i] == lowest || q[i] == secondLowest) && d_check != 2){
            cout << right << "Quiz " << i + 1 << " " << q[i] << " (Dropped) " << endl;
            d_check += 1;
        }
        else{
            cout << right << "Quiz " << i + 1 << " " << q[i] << endl;
        }
    }
    
    //Set two lowest quiz grades to zero
    for(int i = 0; i < 6; i++){
        if(q[i] == lowest){
            q[i] = 0;
            break;
        }
        
    }
    
    for(int i = 0; i < 6; i++){
        if(q[i] == secondLowest){
            q[i] = 0;
            break;
        }
        
    }
    
    
    //Compute sum of quiz grades
    for(int i = 0; i < 6; i++){
       
        quiz_sum = quiz_sum + q[i];
    }
    
    //Scheme 1 for computing grades
    double examGrade;
    double projectGrade;
    double quizGrade;
    examGrade = (e / 100) * 45;
    projectGrade = (p / 100) * 25;
    quizGrade = ((quiz_sum / 4) / 100) * 30;

    
    double average1 = examGrade + projectGrade + quizGrade;

   
    //Scheme 2 for computing grades
    double examGrade2;
    double projectGrade2;
    double quizGrade2;
    examGrade2 = (e / 100) * 46;
    projectGrade2 = (p / 100) * 32;
    quizGrade2 = ((quiz_sum / 4) / 100) * 22;

    
    double average2 = examGrade2 + projectGrade2 + quizGrade2;

    //Determine which average computes the higher score
    if (average1 > average2) {
        cout << "Scheme I is used" << endl;
        return average1;
    }
    else {
        cout << "Scheme II is used" << endl;
        return average2;
    }
    
}

int main(){

        // declare containers for different grade items
        vector<double> quiz(6);
        double exam, project; // contains midterm and final

        // read grades from user
        read_grades(quiz, project, exam);

        // compute average based on the grading scheme
        // print items to the console, including dropped situation
        double average = compute_average(quiz, project, exam);
        
        // output average grade
       
        cout << "The average grade is " << average << "." << endl;
        
        return 0;

    }


