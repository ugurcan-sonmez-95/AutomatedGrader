// Automated Grader

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void print_header();
void print_footer(double average);
void print_student(const std::string &student, int score);
int response(const std::string &responses, const std::string &answer_key);

void print_header() {
    std::cout << std::setw(15) << std::left << "Student" << std::setw(5) << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average) {
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average score" << std::setw(5) << std::right << average << std::endl;
    std::cout << std::endl;
}

void print_student(const std::string &student, int score) {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << student << std::setw(5) << std::right << score << std::endl;
}

int response(const std::string &responses, const std::string &answer_key) {
    int score {};
    for (size_t i {}; i < answer_key.size(); i++) {
        if (responses.at(i) == answer_key.at(i))
            score++;
    }
    return score;
}

int main() {
    std::ifstream in_file;
    std::string answer_key;
    std::string name;
    std::string responses;
    int sum {};
    int total_studs {};
    double avg_score {};

    in_file.open("responses.txt");
    if (!in_file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    } else {
        in_file >> answer_key;
        std::cout << std::endl;
        print_header();
        while (in_file >> name >> responses) {
            total_studs++;
            int score = response(responses, answer_key);
            sum += score;
            print_student(name, score);
        }
    }
    if (total_studs != 0)
        avg_score = static_cast<double>(sum) / total_studs;
    
    print_footer(avg_score);
    
    in_file.close();
    
    return 0;
}