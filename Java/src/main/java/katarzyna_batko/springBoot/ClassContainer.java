package katarzyna_batko.springBoot;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ClassContainer {
    private Map<String, Class> groups;

    public ClassContainer() {
        this.groups = new HashMap<>();
    }

    public void addClass(String newClass, int number) {
        groups.put(newClass, new Class(newClass, number));
    }

    public Class getClass(String className) {
        return groups.get(className);
    }

    public Map<String, String> getClasses() {
        HashMap<String, String> map = new HashMap<>();

        groups.forEach((key, value) -> map.put(key, value.getGroupName()));

        return map;
    }

    public Student getStudent(int id) {
        for (Class group : groups.values()) {
            Student student = group.getStudentById(id);
            if (student != null) {
                return student;
            }
        }

        return null;
    }

    public void removeStudent(Student student) {
        for (Class group : groups.values()) {
            group.removeStudent(student);
        }
    }

    public void removeClass(String className) {
        groups.remove(className);
    }

    public List<String> findEmpty(){
        List<String> emptyGroups = new ArrayList<>();
        String x ="";
        for (Class group : groups.values()){
            if(group.getPercentageFull() == 0){
                emptyGroups.add(group.getGroupName());
                x=group.getGroupName();
            }
        }
        System.out.println(x);
        return emptyGroups;
    }
    public void summary(){
        for (Class group : groups.values()){
            System.out.printf("Grupa: \n", group.getGroupName(), group.getPercentageFull());
        }
    }
    public List<Student> getAllStudents()
    {
        List<Student> students = new ArrayList<>();

        for (Class group : groups.values()){
            students.addAll(group.getStudentList());
        }

        return students;
    }
}
