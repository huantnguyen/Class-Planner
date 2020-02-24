import json
import re
from flask import Flask, escape, request
from flask_cors import CORS

# parse json
with open("courses.json") as file:
    json_data = file.read()
data = json.loads(json_data)

# class categories
lowerdiv = []
upperdiv = []
ge = []

# list of classes taken
class_taken = []
# TODO: add list of taken classes into list

# list of major requirements
major_reqs = { "STATS 10", "STATS 12", "STATS 13", "STATS 20", "ECON 41", "PSYCH 100A", "MATH 31A", "MATH 31B",
    "MATH 32A", "MATH 32B", "MATH 33A", "STATS 100A", "STATS 100B", "STATS 100C", "STATS 101A", "STATS 101B",
    "STATS 101C",  "STATS 102A", "STATS 102B", "STATS 102C", "STATS 140SL", "STATS 141SL" }
# list of non GE majors
other_majors = { "COM SCI", "STATS", "MATH" }

for i in data:
    # get course num, strip anything after -
    course_title = i["courseNum"]
    course_title = course_title.split('-')[0]

    # if class already taken, skip
    if course_title in class_taken:
        continue

    # get course number and convert to int (skip if not available)
    course_num = course_title.split(' ')[-1]
    course_num = re.sub("\D", "", course_num)
    if course_num != '':
        course_num = int(course_num)
    else:
        continue
    
    # get course major, professor, and title
    course_major = i["major"]
    course_prof  = i["professor"]
    course_name  = i["courseTitle"]

    # get quarter (skip if not available)
    if "quarter" in i:
        course_quarter = i["quarter"]
    else:
        continue

    # split quarter into season and year
    course_season = course_quarter[:2]
    course_year = course_quarter[-1]
    if course_season == 'F':
        course_season = 0
    elif course_season == 'W':
        course_season = 1
    elif course_season == 'S':
        course_season = 2
    else:
        continue

    # ignore classes from 2016-2017 year
    if course_season == 'F' or course_quarter == "17S":
        continue

    # create course string with course number, title, professor, and quarter
    course = course_title + "|" + course_name + "|" + course_prof + "|" + course_quarter

    if course_title in major_reqs:
        if course_num < 100:
            lowerdiv.append(course)
        else:
            upperdiv.append(course)
    elif course_major not in other_majors:
        ge.append(course)

app = Flask(__name__)
CORS(app)

@app.route('/')
def hello_world():
    print(request.args.get("name"))
    return '1'

@app.route('/taken')
def course_taken():
    class_taken.append(request.args.get("course_taken"))
    class_to_be_taken = []
    for i in major_reqs:
        if i not in class_taken:
            class_to_be_taken.append(i)
    return str(class_to_be_taken)



'''
print("LOWERDIVS")
for i in lowerdiv:
    print(i)
print("UPPERDIVS")
for i in upperdiv:
    print(i)

print("GES")
for i in ge:
    print(i)
'''

if __name__ == '__main__':
    app.run(debug=True)