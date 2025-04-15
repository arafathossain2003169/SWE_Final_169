#include<iostream>
#include<bits/stdc++.h>
#include<gtest/gtest.h>

// Create a C++ program that uses the Singleton design pattern to manage a single instance of a StudentManager class, which holds a list of students.
// Requirements:
// Implement the Singleton design pattern.
// Add functionalities to add, remove and display student names
// Write at least 2 test cases using gtest

using namespace std;





class StudentManager {
private:
    static StudentManager* instance;
    vector<string> students;
    StudentManager() {}

public:
    static StudentManager* getInstance() {
        if (instance == nullptr) {
            instance = new StudentManager();
        }
        return instance;
    }

    void addStudent(const string& name) {
        students.push_back(name);
    }

    void removeStudent(const string& name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (*it == name) {
                students.erase(it);
                break;
            }
        }
    }

    void displayStudents() {
        for (const auto& student : students) {
            cout << student << endl;
        }
    }

    vector<string> getStudents() {
        return students;
    }
};

StudentManager* StudentManager::instance = nullptr;

TEST(StudentManagerTest, SingletonTest) {
    StudentManager* manager1 = StudentManager::getInstance();
    StudentManager* manager2 = StudentManager::getInstance();
    ASSERT_EQ(manager1, manager2);
}

TEST(StudentManagerTest, AddRemoveTest) {
    StudentManager* manager = StudentManager::getInstance();
    manager->addStudent("John");
    manager->addStudent("Alice");
    auto students = manager->getStudents();
    ASSERT_EQ(students.size(), 2);
    manager->removeStudent("John");
    students = manager->getStudents();
    ASSERT_EQ(students.size(), 1);
    ASSERT_EQ(students[0], "Alice");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}