#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structure to hold quiz questions and answers
struct Question {
    string question;
    vector<string> options;
    int correctAnswer;
};

// Function to display a question and return if the answer is correct
bool askQuestion(const Question &q, int &score) {
    cout << "\n" << q.question << endl;
    for (size_t i = 0; i < q.options.size(); i++) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }

    int answer;
    cout << "Enter your choice (1-" << q.options.size() << "): ";
    cin >> answer;

    if (answer == q.correctAnswer) {
        cout << "Correct!\n";
        score++;
        return true;
    } else {
        cout << "Wrong! The correct answer is: " << q.options[q.correctAnswer - 1] << endl;
        return false;
    }
}

// Function to shuffle questions for randomness
void shuffleQuestions(vector<Question> &questions) {
    srand((unsigned)time(0));
    for (size_t i = 0; i < questions.size(); i++) {
        swap(questions[i], questions[rand() % questions.size()]);
    }
}

// Main function
int main() {
    // List of questions
    vector<Question> questions = {
        {"What is the capital of France?",
         {"Paris", "London", "Berlin", "Madrid"},
         1},
        {"Which planet is known as the Red Planet?",
         {"Earth", "Mars", "Jupiter", "Venus"},
         2},
        {"What is 5 + 3?",
         {"5", "8", "10", "15"},
         2},
        {"Who wrote 'Hamlet'?",
         {"Charles Dickens", "William Shakespeare", "J.K. Rowling", "Mark Twain"},
         2},
        {"What is the boiling point of water (in Celsius)?",
         {"90", "100", "120", "150"},
         2}
    };

    cout << "Welcome to the Console Quiz Game!\n";
    cout << "You will answer multiple-choice questions. Good luck!\n\n";

    // Shuffle questions
    shuffleQuestions(questions);

    int score = 0; // Initialize score
    int totalQuestions = questions.size();

    // Ask each question
    for (size_t i = 0; i < totalQuestions; i++) {
        cout << "\nQuestion " << i + 1 << " of " << totalQuestions << ":";
        askQuestion(questions[i], score);
    }

    // Display final score
    cout << "\nQuiz Over! Your final score is: " << score << " out of " << totalQuestions << endl;

    // Performance feedback
    if (score == totalQuestions) {
        cout << "Excellent! You got all the answers correct!\n";
    } else if (score >= totalQuestions / 2) {
        cout << "Good job! But there's room for improvement.\n";
    } else {
        cout << "Better luck next time! Keep learning.\n";
    }

    return 0;
}