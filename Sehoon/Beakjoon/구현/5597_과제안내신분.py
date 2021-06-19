STUDENTS_NUM = 30
SUBMIT_HOMEWORK_STUDENT_NUM = 28

def main():
    students = list(range(1, STUDENTS_NUM+1))
    submit_students = []
    for i in range(SUBMIT_HOMEWORK_STUDENT_NUM):
        student_id = int(input())
        submit_students.append(student_id)

    not_submit_homework_students = [x for x in students if x not in submit_students]
    not_submit_homework_students.sort()
    print(not_submit_homework_students[0])
    print(not_submit_homework_students[1])

main()