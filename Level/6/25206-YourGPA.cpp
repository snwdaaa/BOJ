// 전공 평점 = (학점 * 과목평점)의 합 / 학점의 총합
// 과목평점: A+, A0, ..(문자) => 4.5, 4.0, ..(숫자)
// P/F 과목은 계산에서 제외

// 20줄에 걸쳐 과목명, 학점, 등급이 입력됨
// 전공평점을 출력

#include <iostream>
#include <string>

// 과목
struct Class
{
    std::string className; // 과목 이름. ex) BruteForce
    float classScore; // 과목 평점. ex) 3.0
    std::string classGrade; // 과목 학점. ex) A+, F, ..
};

float InvertGradeToScore(std::string grade)
{
    if (grade == "A+") return 4.5f;
    else if (grade == "A0") return 4.0f;
    else if (grade == "B+") return 3.5f;
    else if (grade == "B0") return 3.0f;
    else if (grade == "C+") return 2.5f;
    else if (grade == "C0") return 2.0f;
    else if (grade == "D+") return 1.5f;
    else if (grade == "D0") return 1.0f;
    return 0.0f; // 예외
}

int main()
{
    Class classes[20];

    // 수강한 과목의 정보 입력
    for (int i = 0; i < 20; i++)
    {
        std::cin >> classes[i].className; // 과목명 입력
        std::cin >> classes[i].classScore; // 과목의 학점 입력
        std::cin >> classes[i].classGrade; // 과목평점(문자) 입력
    }

    float scoreSum = 0; // (학점 * 과목평점)의 합
    float gradeSum = 0; // 취득한 과목의 학점의 합
    for (int i = 0; i < 20; i++)
    {
        if (classes[i].classGrade != "P") // P/F 과목인 경우 제외
        {
            gradeSum += classes[i].classScore;
            scoreSum += classes[i].classScore * InvertGradeToScore(classes[i].classGrade);
        }
    }

    if (gradeSum == 0)
    {
        std::cout << "0";
    }
    else
    {
        std::cout << scoreSum / gradeSum; // 전공평점 출력
    }   

    return 0;
}