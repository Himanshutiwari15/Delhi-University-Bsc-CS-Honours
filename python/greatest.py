student_1 = 21
student_2 = 19
student_3 = 29

oldest_student = ""

# Assume these are the ages of the students. Find out programmatically who is the oldest of the students.
# output should be like this

# if student_1 is the oldest, have oldest_student variable set to "student_1"
# if student_2 is the oldest, have oldest_student variable set to "student_2"
# if student_3 is the oldest, have oldest_student variable set to "student_3"

if student_1 > student_2:
    if student_1>student_3:
        oldest_student="student_1"
    else:
        oldest_student="student_3"
elif student_2 > student_3:
    oldest_student="student_2"
else:
    oldest_student="student_3"


print(oldest_student)
